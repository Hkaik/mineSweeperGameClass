#include "BlockFactory.h"
#include "Block.h"
#include "BLOCK_TYPE.h"
#include "BombBlock.h"
#include "NumberBlock.h"

using namespace std;

// template<class T> T *BlockFactory::getBlock(BLOCK_TYPE blockType) {
Block* BlockFactory::getBlock(BLOCK_TYPE blockType) {
	switch (blockType)
	{
	case BOMB:
		Block *newBlock = new BombBlock;
		return newBlock;
	case NUMBER:
		Block *newBlock = new NumberBlock;
		return newBlock;
	}
}
