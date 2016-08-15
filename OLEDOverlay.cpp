/*
 * OLEDIndicator.cpp
 *
 *  Created on: 15.08.2016
 *      Author: ian
 */

#include <OLEDOverlay.h>

OLEDOverlay* OLEDOverlay::_first = 0;
OLEDOverlay* OLEDOverlay::_last = 0;
uint8_t OLEDOverlay::_nodeCount = 0;


OLEDOverlay::OLEDOverlay(): _next(0) {
	if (_last)
		_last->_next = this;
	else
		_first = this;
	_last = this;
	++_nodeCount;
}

OLEDOverlay* OLEDOverlay::get(uint8_t idx) {
	if (idx >= _nodeCount)
		return 0;
	OLEDOverlay* ptr = _first;
	uint_fast8_t i = 0;
	while (i < idx) {
		ptr = ptr->_next;
		i++;
	}
	return ptr;
}


