#pragma once
#include "MARK_TYPE.h"
#include "Position.h"

class Block {
private:
	Position pos;
	MARK_TYPE mark = MARK_TYPE::NO_MARK;
	bool isOpen = false;

public:
	MARK_TYPE getMark();
	bool getOpen();
	void setMark(MARK_TYPE);
	virtual void open() = 0;
	virtual char getIcon() = 0;
};