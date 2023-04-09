#include "Block.h"

#include <iostream>
using namespace std;

MARK_TYPE Block::getMark() {
	return this->mark;
}

bool Block::getOpen() {
	return this->isOpen;
}

void Block::setMark(MARK_TYPE mark) {
	this->mark = mark;
}
