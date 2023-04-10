#pragma once
#include "BLOCK_TYPE.h"
#include "Block.h"

class BlockFactory {
public:
	// template<class T> T *getBlock(BLOCK_TYPE);
	Block* getBlock(BLOCK_TYPE);
};
