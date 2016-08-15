/*
 * OLEDFrame.h
 *
 *  Created on: 14.08.2016
 *      Author: ian
 */

#ifndef LIB_ESP8266_OLED_SSD1306_OLEDFRAME_H_
#define LIB_ESP8266_OLED_SSD1306_OLEDFRAME_H_

#include <OLEDDisplay.h>
#include <OLEDDisplayUi.h>

class OLEDFrame {

public:
	OLEDFrame();

	virtual void drawFrame(OLEDDisplay *display,  OLEDDisplayUiState* state, int16_t x, int16_t y) = 0;

private:
	OLEDFrame* _next;
    static OLEDFrame* _first;
    static OLEDFrame* _last;
    static uint8_t _nodeCount;

public:
	uint8_t count() {return _nodeCount;};

	static OLEDFrame* getFrame(uint8_t idx);
};


#endif /* LIB_ESP8266_OLED_SSD1306_OLEDFRAME_H_ */
