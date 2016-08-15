/*
 * OLEDIndicator.h
 *
 *  Created on: 15.08.2016
 *      Author: ian
 */

#ifndef LIB_ESP8266_OLED_SSD1306_OLEDOVERLAY_H_
#define LIB_ESP8266_OLED_SSD1306_OLEDOVERLAY_H_

#include <OLEDDisplayUi.h>

class OLEDOverlay {
public:
	OLEDOverlay();

	virtual void drawOverlay(OLEDDisplay& display,  OLEDDisplayUiState& state, uint8_t idx) = 0;

private:
	OLEDOverlay* _next;
    static OLEDOverlay* _first;
    static OLEDOverlay* _last;
    static uint8_t _nodeCount;

public:
	uint8_t count() {return _nodeCount;};

	static OLEDOverlay* get(uint8_t idx);

};

#endif /* LIB_ESP8266_OLED_SSD1306_OLEDOVERLAY_H_ */
