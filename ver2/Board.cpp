#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Position.h"
#include "BlockFactory.h"
#include "Board.h"
#include "BLOCK_TYPE.h"
#include "MARK_TYPE.h"

using namespace std;

int Board::getBombCount() {
	int bombCount = 0;

	for (auto &i :this->blocks) {
		for (auto& j : i) {
			if (j.getBlockType() == BLOCK_TYPE::BOMB) {
				bombCount++;
			}
		}
	}

	return bombCount;
}

int Board::getFlagCount() {
	int flagCount = 0;

	for (auto& i : this->blocks) {
		for (auto& j : i) {
			if (j.getMark() == MARK_TYPE::FLAG) {
				flagCount++;
			}
		}
	}

	return flagCount;
}

int Board::getOpenBlankCount() {
	int openBlankCount = 0;

	for (auto& i : this->blocks) {
		for (auto& j : i) {
			if (j.getBlockType() == BLOCK_TYPE::NUMBER) {
				if (j.getValue() == 0 && j.getOpen()) {
					openBlankCount++;
				}
			}
		}
	}

	return openBlankCount;
}

int Board::getRemainBlankCount() {
	int remainBlankCount = 0;

	for (auto& i : this->blocks) {
		for (auto& j : i) {
			if (j.getBlockType() == BLOCK_TYPE::NUMBER) {
				if (j.getValue() == 0 && !(j.getOpen())) {
					remainBlankCount++;
				}
			}
		}
	}

	return remainBlankCount;
}

void Board::setBoard(string path) { // path
	ifstream boardFile;
	boardFile.open(path);

	string row;
	BlockFactory blockFactory;

	int m, n;
	boardFile >> m >> n;

	while (boardFile >> row) {
		vector<Block*> blocksRow;

		for (auto& i : row) {
			Block* blockPtr;

			if (i == 'O') {
				blockPtr = blockFactory.getBlock(BLOCK_TYPE::NUMBER);
			}
			else if (i == 'X') {
				blockPtr = blockFactory.getBlock(BLOCK_TYPE::BOMB);
			}

			blocksRow.push_back(blockPtr);
		}
		this->blocks.push_back(blocksRow);
	}
}

void Board::setBoard(int m, int n, int bombAmount) { // bomb amount
	vector<int> bombTable (m * n , 0);
	int bombPos = rand() % (m * n);

	for (int i = 0; i < bombAmount; i++) {
		while (bombTable[bombPos] != 0) {
			bombPos = rand() % (m * n);
		}
		bombTable[bombPos] = 1;
	}

	BlockFactory blockFactory;

	for (int i = 0; i < m; i++) {
		vector<Block*> blocksRow;

		for (int j = 0; j < n; j++) {
			Block* blockPtr;
			if (bombTable[i * j + j]) {
				blockPtr = blockFactory.getBlock(BLOCK_TYPE::BOMB);
			}
			else {
				blockPtr = blockFactory.getBlock(BLOCK_TYPE::BOMB);
			}
			blocksRow.push_back(blockPtr);
		}
		this->blocks.push_back(blocksRow);
	}
}

void Board::setBoard(int m, int n, double bombRate) { // bomb chance
	bombRate *= 100;
	BlockFactory blockFactory;

	for (int i = 0; i < m; i++) {
		vector<Block*> blocksRow;

		for (int j = 0; j < n; j++) {
			Block* blockPtr;
			if (rand() % 100 + 1 <= bombRate) {
				blockPtr = blockFactory.getBlock(BLOCK_TYPE::BOMB);
			}
			else {
				blockPtr = blockFactory.getBlock(BLOCK_TYPE::BOMB);
			}
			blocksRow.push_back(blockPtr);
		}
		this->blocks.push_back(blocksRow);
	}
}

void Board::leftClick(Position pos) {
	if (pos.x >= this->blocks.size() || pos.y >= this->blocks[0].size() || pos.x < 0 || pos.y < 0) {
		return;
	}

	Block* tempBlockPtr = this->blocks[pos.x][pos.y];

	if (tempBlockPtr->getBlockType() == BLOCK_TYPE::NUMBER) {
		if (tempBlockPtr->getOpen() || tempBlockPtr->getMark() == MARK_TYPE::FLAG) {
			return;
		}

		if (tempBlockPtr->getvalue() == 0) {
			tempBlockPtr->open();

			int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
			Position newPos;

			for (int i = 0; i < 4; i++) {
				newPos.x = pos.x + dir[i][0];
				newPos.y = pos.y + dir[i][1];
				leftClick(newPos);
			}
		}
		else {
			tempBlockPtr->open();
			return;
		}
	}
}

void Board::rightClick(Position pos) {
	MARK_TYPE markType = this->blocks[pos.x][pos.y]->getMark();
	switch (markType)
	{
	case MARK_TYPE::FLAG:
		this->blocks[pos.x][pos.y]->setMark(MARK_TYPE::QUESTION);
		return;
	case MARK_TYPE::QUESTION:
		this->blocks[pos.x][pos.y]->setMark(MARK_TYPE::NO_MARK);
		return;
	case MARK_TYPE::NO_MARK:
		this->blocks[pos.x][pos.y]->setMark(MARK_TYPE::FLAG);
		return;
	}
}

void Board::printBoard() {
	for (auto& i : this->blocks) {
		for (auto& j : i) {
			if (j->getOpen() == 0) {
				cout << "# ";
			}
			else {
				cout << j->getIcon() << " ";
			}
		}
		cout << endl;
	}
}

void Board::printAnswer() {
	for (auto& i : this->blocks) {
		for (auto& j : i) {
			if (j->getBlockType() == BLOCK_TYPE::BOMB) {
				cout << "X ";
			}
			else {
				cout << j->getValue() << " ";
			}
		}
		cout << endl;
	}
}