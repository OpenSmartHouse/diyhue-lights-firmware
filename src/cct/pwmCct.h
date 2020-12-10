#ifndef LIGHT_H
#define LIGHT_H



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "../BaseLight.h"
#include "../internal_cfg.h"


#define COLOR_WARM_WHITE 0
#define COLOR_COLD_WHITE 1


class Light : public BaseLight
{
private:
	// Declare RGBW channels of the MY9291 chip (OUT_x port)
	uint8_t pwmPins[CHANNELS_COUNT];

protected:
	void lightEngine();
	String getModelId();
	void applyColorsImmediatly();
	void convert_ct(uint8_t* rgbw_p, int ct, int bri);

public:
	void initPlatformSpecific();
	void notifyNotConnected();


};

#endif
