#pragma once
#include <iostream>
#include <vector>
#include "Block.h"
#include "BombBlock.h"
#include "Position.h"

using namespace std;

class Board {
	private:
		vector<vector<Block*>> blocks;
		// BlockFactory blockFactory;
	public:
		int getBombCount();
		int getFlagCount();
		int getOpenBlankCount();
		int getRemainBlankCount();
		void setBoard(string); // path
		void setBoard(int); // bomb amount
		void setBoard(double); // bomb chance
		void leftClick(Position);
		void rightClick(Position);
		void printBoard();
		void printAnswer();
};
