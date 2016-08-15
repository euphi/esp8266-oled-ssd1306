/*
 * OLEDFrame.cpp
 *
 *  Created on: 15.08.2016
 *      Author: ian
 */

#include <OLEDFrame.h>

OLEDFrame* OLEDFrame::_first = 0;
OLEDFrame* OLEDFrame::_last = 0;
uint8_t OLEDFrame::_nodeCount = 0;

OLEDFrame::OLEDFrame() {
	if (_last)
		_last->_next = this;
	else
		_first = this;
	_last = this;
	++_nodeCount;
}


OLEDFrame* OLEDFrame::getFrame(uint8_t idx) {
	if (idx >= _nodeCount)
		return 0;
	OLEDFrame* ptr = _first;
	uint_fast8_t i = 0;
	while (i < idx) {
		ptr = ptr->_next;
		i++;
	}
	return ptr;
}
