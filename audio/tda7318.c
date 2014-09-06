#include "tda7318.h"

#include <avr/eeprom.h>

#include "../i2c.h"
#include "../eeprom.h"
#include "../input.h"

static sndParam sndPar[SND_PARAM_COUNT];

static uint8_t chan;
static uint8_t mute;

sndParam *sndParAddr(uint8_t index)
{
	return &sndPar[index];
}

uint8_t getChan()
{
	return chan;
}

uint8_t getMute()
{
	return mute;
}

static void setVolume(int8_t val)
{
	int8_t spFrontLeft = 0;
	int8_t spFrontRight = 0;

	int8_t spRearLeft = 0;
	int8_t spRearRight = 0;

	if (sndPar[SND_BALANCE].value > 0) {
		spFrontRight -= sndPar[SND_BALANCE].value;
		spRearRight -= sndPar[SND_BALANCE].value;
	} else {
		spFrontLeft += sndPar[SND_BALANCE].value;
		spRearLeft += sndPar[SND_BALANCE].value;
	}
	if (sndPar[SND_BALANCE_FR].value > 0) {
		spRearLeft -= sndPar[SND_BALANCE_FR].value;
		spRearRight -= sndPar[SND_BALANCE_FR].value;
	} else {
		spFrontLeft += sndPar[SND_BALANCE_FR].value;
		spFrontRight += sndPar[SND_BALANCE_FR].value;
	}
	I2CStart(AUDIOPROC_ADDR);
	I2CWriteByte(TDA7318_VOLUME | -val);
	I2CWriteByte(TDA7318_SP_FRONT_LEFT | -spFrontLeft);
	I2CWriteByte(TDA7318_SP_FRONT_RIGHT | -spFrontRight);
	I2CWriteByte(TDA7318_SP_REAR_LEFT | -spRearLeft);
	I2CWriteByte(TDA7318_SP_REAR_RIGHT | -spRearRight);
	I2CStop();
}

static void setBalanceFrontRear(int8_t val)
{
	setVolume(sndPar[SND_VOLUME].value);
}

static int8_t calcBMT(int8_t val)
{
	if (val > 0)
		return 15 - val;
	return 7 + val;
}

static void setBass(int8_t val)
{
	I2CStart(AUDIOPROC_ADDR);
	I2CWriteByte(TDA7318_BASS | calcBMT(val));
	I2CStop();
}

static void setTreble(int8_t val)
{
	I2CStart(AUDIOPROC_ADDR);
	I2CWriteByte(TDA7318_TREBLE | calcBMT(val));
	I2CStop();
}

static void setSwitch(int8_t gain)
{
	I2CStart(AUDIOPROC_ADDR);
	I2CWriteByte(TDA7318_SW | (CHAN_CNT - gain) << 3 | chan);
	I2CStop();
}

static void setGain(int8_t val)
{
	setSwitch(val);
}

void setChan(uint8_t ch)
{
	chan = ch;
	setGain(sndPar[SND_GAIN0 + ch].value);
	setSwitch(sndPar[SND_GAIN0 + chan].value);
}

void nextChan(void)
{
	chan++;
	if (chan >= CHAN_CNT)
		chan = 0;
	setChan(chan);
}

static void setBalance(int8_t val)
{
	setVolume(sndPar[SND_VOLUME].value);
}

void muteVolume(void)
{
	setVolume(sndPar[SND_VOLUME].min);
	mute = MUTE_ON;
	STMU_PORT &= ~MUTE;
}

void unmuteVolume(void)
{
	setVolume(sndPar[SND_VOLUME].value);
	mute = MUTE_OFF;
	STMU_PORT |= MUTE;
}

void switchMute(void)
{
	if (mute == MUTE_ON) {
		unmuteVolume();
	} else {
		muteVolume();
	}
}

void loadAudioParams(uint8_t **txtLabels)
{
	uint8_t i;

	for (i = 0; i < SND_PARAM_COUNT; i++) {
		sndPar[i].value = eeprom_read_byte(eepromVolume + i);
		sndPar[i].label = txtLabels[i];
		sndPar[i].min = eeprom_read_byte(eepromMinimums + i);
		sndPar[i].max = eeprom_read_byte(eepromMaximums + i);
		sndPar[i].step = eeprom_read_byte(eepromSteps + i);
	}

	chan = eeprom_read_byte(eepromChannel);

	sndPar[SND_VOLUME].set = setVolume;
	sndPar[SND_BASS].set = setBass;
	sndPar[SND_TREBLE].set = setTreble;
	sndPar[SND_BALANCE_FR].set = setBalanceFrontRear;
	sndPar[SND_BALANCE].set = setBalance;

	for (i = 0; i < 4; i++) {
		sndPar[SND_GAIN0 + i].set = setGain;
	}

	muteVolume();
	setChan(chan);
	setBass(sndPar[SND_BASS].value);
	setBalanceFrontRear(0);
	setTreble(sndPar[SND_TREBLE].value);
}

void saveAudioParams(void)
{
	uint8_t i;

	for (i = 0; i < SND_PARAM_COUNT; i++) {
		eeprom_update_byte(eepromVolume + i, sndPar[i].value);
	}
	eeprom_update_byte(eepromChannel, chan);
}

void changeParam(sndParam *param, int8_t diff)
{
	param->value += diff;
	if (param->value > param->max)
		param->value = param->max;
	if (param->value < param->min)
		param->value = param->min;
	param->set(param->value);
}