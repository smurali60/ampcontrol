#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#include "eeprom.h"
#include "adc.h"
#include "input.h"
#include "rc5.h"
#include "i2c.h"

#include "audio/audio.h"
#include "display.h"
#include "tuner.h"
#include "temp.h"

#include "actions.h"

uint8_t *txtLabels[LABELS_COUNT];	/* Array with text label pointers */

/* Load text labels from EEPROM */
static void loadLabels(uint8_t **txtLabels)
{
	uint8_t i;
	uint8_t *addr;

	addr = labelsAddr;
	i = 0;

	while (i < LABELS_COUNT && addr < (uint8_t*)EEPROM_SIZE) {
		if (eeprom_read_byte(addr) != '\0') {
			txtLabels[i] = addr;
			addr++;
			i++;
			while (eeprom_read_byte(addr) != '\0' &&
				   addr < (uint8_t*)EEPROM_SIZE) {
				addr++;
			}
		} else {
			addr++;
		}
	}

	return;
}

/* Hardware initialization */
static void hwInit(void)
{
	sei();								/* Gloabl interrupt enable */
	inputInit();						/* Buttons/encoder polling */
#if !defined(LM7001)
	ds18x20SearchDevices();
	tempInit();							/* Init temperature control */
#endif

	loadLabels(txtLabels);				/* Load text labels from EEPROM */

	gdInit();

	rc5Init();							/* IR Remote control */
	adcInit();							/* Analog-to-digital converter */
	I2CInit();							/* I2C bus */
#if !defined(NOTUNER)
	tunerInit();						/* Tuner */
#endif

	DDR(STMU_STBY) |= STMU_STBY_LINE;	/* Standby port */
	DDR(STMU_MUTE) |= STMU_MUTE_LINE;	/* Mute port */

	PORT(STMU_STBY) &= ~STMU_STBY_LINE;

	muteVolume();

	return;
}

int main(void)
{
	hwInit();

	uint8_t dispMode = MODE_STANDBY;
	uint8_t dispModePrev = dispMode;

	sndParam *curSndParam = sndParAddr(SND_VOLUME);

	int8_t encCnt = 0;
	uint8_t cmd = CMD_EMPTY;

#if !defined(NOTUNER)
	loadTunerParams();
#endif
	loadAudioParams(txtLabels);
	loadDispParams();
	setStbyBrightness();

	while (1) {
		encCnt = getEncoder();
		cmd = getBtnCmd();

#if !defined(LM7001)
		ds18x20Process();
		tempControlProcess();
#endif

		/* Don't handle any command in test mode except BTN_5 and BTN_1_LONG */
		if (dispMode == MODE_TEST) {
			if (cmd != CMD_EMPTY)
				setDisplayTime(DISPLAY_TIME_TEST);
			if (cmd != CMD_BTN_5 && cmd != CMD_BTN_1_LONG)
				cmd = CMD_EMPTY;
		}
		/* Don't handle any command in temp mode except BTN_1_LONG */
		if (dispMode == MODE_TEMP) {
			if (cmd != CMD_EMPTY)
				setDisplayTime(DISPLAY_TIME_TEMP);
			if (cmd != CMD_BTN_1_LONG)
				cmd = CMD_EMPTY;
		}

		/* Don't handle commands in standby mode except STBY, TEST and TEMP */
		if (dispMode == MODE_STANDBY) {
#if !defined(LM7001)
			if (cmd != CMD_BTN_1 && cmd != CMD_RC5_STBY &&
				cmd != CMD_BTN_TEST && cmd != CMD_BTN_TEMP)
				cmd = CMD_EMPTY;
#else
			if (cmd != CMD_BTN_1 && cmd != CMD_RC5_STBY &&
				cmd != CMD_BTN_TEST)
				cmd = CMD_EMPTY;
#endif
		}

		/* Handle command */
		switch (cmd) {
		case CMD_RC5_STBY:
			handleSwitchPower(&dispMode);
			break;
		case CMD_RC5_MUTE:
			handleSwitchMute(&dispMode);
			break;
		case CMD_RC5_MENU:
			handleNextSndParam(&dispMode, &curSndParam);
			break;
		/* CMD_VOL_UP and CMD_VOL_DOWN are processed below as encoder actions */
		case CMD_RC5_INPUT_0:
		case CMD_RC5_INPUT_1:
		case CMD_RC5_INPUT_2:
#if !defined(TDA7313)
		case CMD_RC5_INPUT_3:
#endif
			setChan(cmd - CMD_RC5_INPUT_0);
			gdClear();
			curSndParam = sndParAddr(SND_GAIN0 + getChan());
			dispMode = MODE_GAIN;
			setDisplayTime(DISPLAY_TIME_GAIN);
			break;
#if defined(TDA7313)
		case CMD_RC5_INPUT_3:
			gdClear();
			switchLoudness();
			dispMode = MODE_LOUDNESS;
			setDisplayTime(DISPLAY_TIME_AUDIO);
			break;
#endif
		case CMD_RC5_NEXT_INPUT:
			handleNextInput (&dispMode);
			curSndParam = sndParAddr(SND_GAIN0 + getChan());
			break;
		case CMD_RC5_TIME:
			handleEditTime(&dispMode);
			break;
		case CMD_RC5_BACKLIGHT:
			dispMode = MODE_BR;
			setDisplayTime(DISPLAY_TIME_BR);
			break;
		case CMD_RC5_SP_MODE:
			handleSwitchSpMode(&dispMode);
			break;
		case CMD_RC5_DISPLAY:
			handleSetDefDisplay(&dispMode);
			break;
#if !defined(NOTUNER)
		case CMD_RC5_FM_CHAN_UP:
		case CMD_RC5_FM_CHAN_DOWN:
			setChan(0);
			if (dispMode == MODE_FM_RADIO) {
				switch (cmd) {
				case CMD_RC5_FM_CHAN_UP:
					scanStoredFreq(SEARCH_UP);
					break;
				case CMD_RC5_FM_CHAN_DOWN:
					scanStoredFreq(SEARCH_DOWN);
					break;
				}
			}
			dispMode = MODE_FM_RADIO;
			setDisplayTime(DISPLAY_TIME_FM_RADIO);
			break;
		case CMD_RC5_FM_TUNE:
			handleSwitchFmMode(&dispMode);
			break;
		case CMD_RC5_FM_MONO:
			if (getChan() == 0) {
				tunerSwitchMono();
				dispMode = MODE_FM_RADIO;
				setDisplayTime(DISPLAY_TIME_FM_RADIO);
			}
			break;
		case CMD_RC5_FM_STORE:
			if (dispMode == MODE_FM_RADIO) {
				storeStation();
				setDisplayTime(DISPLAY_TIME_FM_RADIO);
			}
			break;
		case CMD_RC5_FM_1:
		case CMD_RC5_FM_2:
		case CMD_RC5_FM_3:
		case CMD_RC5_FM_4:
		case CMD_RC5_FM_5:
		case CMD_RC5_FM_6:
		case CMD_RC5_FM_7:
		case CMD_RC5_FM_8:
		case CMD_RC5_FM_9:
		case CMD_RC5_FM_0:
			setChan(0);
			loadStation(cmd - CMD_RC5_FM_1);
			dispMode = MODE_FM_RADIO;
			setDisplayTime(DISPLAY_TIME_FM_RADIO);
			break;
#endif
		case CMD_BTN_1:
			handleSwitchPower(&dispMode);
			break;
		case CMD_BTN_2:
			handleNextInput(&dispMode);
			curSndParam = sndParAddr(SND_GAIN0 + getChan());
			break;
		case CMD_BTN_3:
			switch (dispMode) {
#if !defined(NOTUNER)
			case MODE_FM_RADIO:
				scanStoredFreq(SEARCH_DOWN);
				setDisplayTime(DISPLAY_TIME_FM_RADIO);
				break;
#endif
			default:
				handleEditTime(&dispMode);
				break;
			}
			break;
		case CMD_BTN_4:
			switch (dispMode) {
#if !defined(NOTUNER)
			case MODE_FM_RADIO:
				scanStoredFreq(SEARCH_UP);
				setDisplayTime(DISPLAY_TIME_FM_RADIO);
				break;
#endif
			default:
				handleSwitchMute(&dispMode);
				break;
			}
			break;
		case CMD_BTN_5:
			if (dispMode == MODE_TEST) {
				gdClear();
				nextRC5Cmd();
			} else {
				handleNextSndParam(&dispMode, &curSndParam);
			}
			break;

		case CMD_BTN_1_LONG:
			switch (dispMode) {
			case MODE_TEST:
			case MODE_TEMP:
				setDisplayTime(0);
				break;
			default:
				dispMode = MODE_BR;
				setDisplayTime(DISPLAY_TIME_BR);
				break;
			}
			break;
		case CMD_BTN_2_LONG:
			handleSetDefDisplay(&dispMode);
			break;
		case CMD_BTN_3_LONG:
			handleSwitchSpMode(&dispMode);
			break;
		case CMD_BTN_4_LONG:
			handleSwitchFmMode(&dispMode);
			break;
		case CMD_BTN_5_LONG:
			if (dispMode == MODE_FM_RADIO) {
#if !defined(NOTUNER)
				storeStation();
				setDisplayTime(DISPLAY_TIME_FM_RADIO);
#endif
			}
			break;
		case CMD_BTN_TEST:
			switch (dispMode) {
			case MODE_STANDBY:
				dispMode = MODE_TEST;
				startTestMode();
				setDisplayTime(DISPLAY_TIME_TEST);
				break;
			}
			break;
		case CMD_BTN_TEMP:
			switch (dispMode) {
			case MODE_STANDBY:
				dispMode = MODE_TEMP;
				setDisplayTime(DISPLAY_TIME_TEMP);
				break;
			}
			break;
		}

		/* Emulate RC5 VOL_UP/VOL_DOWN as encoder actions */
		if (cmd == CMD_RC5_VOL_UP)
			encCnt++;
		if (cmd == CMD_RC5_VOL_DOWN)
			encCnt--;

		/* Handle encoder */
		if (encCnt) {
			switch (dispMode) {
			case MODE_STANDBY:
				break;
			case MODE_TEST:
				setDisplayTime(DISPLAY_TIME_TEST);
				break;
#if !defined(LM7001)
			case MODE_TEMP:
				changeTempTH(encCnt);
				setDisplayTime(DISPLAY_TIME_TEMP);
				break;
#endif
			case MODE_TIME_EDIT:
				changeTime(encCnt);
				setDisplayTime(DISPLAY_TIME_TIME_EDIT);
				break;
			case MODE_BR:
				changeBrWork(encCnt);
				setDisplayTime(DISPLAY_TIME_BR);
				break;
			case MODE_FM_TUNE:
#if !defined(NOTUNER)
				if (encCnt > 0)
					tunerIncFreq();
				else
					tunerDecFreq();
				setDisplayTime(DISPLAY_TIME_FM_TUNE);
#endif
				break;
			case MODE_MUTE:
			case MODE_LOUDNESS:
			case MODE_SPECTRUM:
			case MODE_TIME:
			case MODE_FM_RADIO:
				curSndParam = sndParAddr(SND_VOLUME);
				dispMode = MODE_VOLUME;
			default:
				if (getMute())
					unmuteVolume();
				changeParam(curSndParam, encCnt);
				setDisplayTime(DISPLAY_TIME_GAIN);
				break;
			}
		}

		/* Exit to default mode and save params to EEPROM*/
		if (getDisplayTime() == 0) {
			switch (dispMode) {
			case MODE_STANDBY:
				break;
			case MODE_TEST:
				dispMode = MODE_STANDBY;
				break;
#if !defined(LM7001)
			case MODE_TEMP:
				saveTempParams();
				dispMode = MODE_STANDBY;
				break;
#endif
			default:
				dispMode = getDefDisplay();
				if (dispMode == MODE_FM_RADIO && getChan())
					dispMode = MODE_SPECTRUM;
				break;
			}
		}

		/* Clear screen if mode has changed */
		if (dispMode != dispModePrev)
			gdClear();

		/* Show things */
		switch (dispMode) {
		case MODE_STANDBY:
			showTime(txtLabels);
			setStbyBrightness();
			break;
		case MODE_TEST:
			showRC5Info(txtLabels);
			setWorkBrightness();
			break;
#if !defined(LM7001)
		case MODE_TEMP:
			showTemp(txtLabels);
			setWorkBrightness();
			break;
#endif
		case MODE_SPECTRUM:
			drawSpectrum(getSpData(), txtLabels);
			break;
#if !defined(NOTUNER)
		case MODE_FM_RADIO:
			tunerReadStatus();
			showRadio(getSpData(), 0);
			break;
		case MODE_FM_TUNE:
			tunerReadStatus();
			showRadio(getSpData(), 1);
			break;
#endif
		case MODE_MUTE:
			showMute(txtLabels, getSpData());
			break;
#if defined(TDA7313)
		case MODE_LOUDNESS:
			showLoudness(txtLabels, getSpData());
			break;
#endif
		case MODE_TIME:
		case MODE_TIME_EDIT:
			showTime(txtLabels);
			break;
		case MODE_BR:
			showBrWork(txtLabels, getSpData());
			break;
		default:
			showSndParam(curSndParam, txtLabels, getSpData());
			break;
		}

		/* Save current mode */
		dispModePrev = dispMode;
		/* Save current RC5 raw buf */
	}

	return 0;
}
