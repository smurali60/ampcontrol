#ifndef ACTIONS_H
#define ACTIONS_H

#include "inttypes.h"

#include "audio/audioproc.h"
#include "input.h"

/* Timers for different screens */
#define DISPLAY_TIME_TEST					20000U
#define DISPLAY_TIME_TEMP					20000U
#define DISPLAY_TIME_GAIN					3000U
#define DISPLAY_TIME_TIME					3000U
#define DISPLAY_TIME_TIME_EDIT				10000U
#define DISPLAY_TIME_TIMER					5000U
#define DISPLAY_TIME_TIMER_EXP				64000U
#define DISPLAY_TIME_ALARM					3000U
#define DISPLAY_TIME_ALARM_EDIT				10000U
#define DISPLAY_TIME_FM_RADIO				5000U
#define DISPLAY_TIME_FM_TUNE				10000U
#define DISPLAY_TIME_CHAN					2000U
#define DISPLAY_TIME_AUDIO					3000U
#define DISPLAY_TIME_SP						3000U
#define DISPLAY_TIME_BR						3000U

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

/* Display modes */
enum {
	MODE_SPECTRUM = MODE_SND_END,
	MODE_STANDBY,
	MODE_FM_RADIO,
	MODE_FM_TUNE,

	MODE_TIME,
	MODE_TIME_EDIT,
	MODE_TIMER,
	MODE_SILENCE_TIMER,
	MODE_ALARM,
	MODE_ALARM_EDIT,
	MODE_MUTE,
	MODE_LOUDNESS,
	MODE_TEST,

	MODE_BR,

	MODE_TEMP
};

actionID getAction(void);

void handleAction(actionID action);
void handleEncoder(int8_t encCnt);
void handleChangeFM(uint8_t step);

actionID checkAlarmAndTime(void);

void handleExitDefaultMode(void);
void handleTimers(void);
void handleModeChange(void);

void showScreen(void);

#endif /* ACTIONS_H */