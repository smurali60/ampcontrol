#ifndef ACTIONS_H
#define ACTIONS_H

#include "inttypes.h"

#include "audio/audioproc.h"
#include "input.h"

typedef enum {
	/* First commands should be equal to RC5 commands */
	ACTION_GO_STANDBY = CMD_RC5_STBY,		/* First RC5 command */
	ACTION_SWITCH_MUTE,
	ACTION_NEXT_SNDPARAM,
	ACTION_VOLUME_UP,
	ACTION_VOLUME_DOWN,
	ACTION_INPUT_0,
	ACTION_INPUT_1,
	ACTION_INPUT_2,
	ACTION_INPUT_3,
	ACTION_NEXT_INPUT,
	ACTION_EDIT_TIME,
	ACTION_BRIGHTNESS,
	ACTION_NEXT_SPMODE,
	ACTION_NEXT_FALLSPEED,
	ACTION_DEF_DISPLAY,
	ACTION_CHANGE_TIMER,

	ACTION_EDIT_ALARM,
	ACTION_INC_FM,
	ACTION_DEC_FM,
	ACTION_CHANGE_FM_MODE,
	ACTION_SWITCH_FM_MONO,
	ACTION_STORE_FM_STATION,
	ACTION_FM_STATION_1,
	ACTION_FM_STATION_2,
	ACTION_FM_STATION_3,
	ACTION_FM_STATION_4,
	ACTION_FM_STATION_5,
	ACTION_FM_STATION_6,
	ACTION_FM_STATION_7,
	ACTION_FM_STATION_8,
	ACTION_FM_STATION_9,
	ACTION_FM_STATION_0,

	ACTION_SWITCH_LOUDNESS = CMD_RC5_END,	/* First non-RC5 command */
	ACTION_NEXT_RC5_CMD,
	ACTION_ZERO_DISPLAYTIME,
	ACTION_EXIT_STANDBY,
	ACTION_TESTMODE,
	ACTION_TEMPMODE,

	ACTION_NOACTION
} actionID;

actionID getAction(uint8_t *dispMode);
void handleAction(actionID action, uint8_t *dispMode);

void powerOn(void);
void powerOff(void);
void handleSetInput(uint8_t *dispMode);
void handleEditTime(uint8_t *dispMode);
void handleSwitchMute(uint8_t *dispMode);
void handleSetDefDisplay(uint8_t *dispMode);
void handleSwitchFmMode(uint8_t *dispMode);
void handleStoreStation(uint8_t *dispMode);
void handleChangeFM(uint8_t *dispMode, uint8_t step);
void handleEditAlarm(uint8_t *dispMode);
void checkAlarmAndTime(uint8_t *dispMode);

#endif /* ACTIONS_H */
