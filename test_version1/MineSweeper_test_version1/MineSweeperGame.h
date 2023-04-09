#pragma once
#include "GAME_STATE.h"

class MineSweeperGame {
private:
	GAME_STATE state = GAME_STATE::STAND_BY;
	Board board;
public:
	GAME_STATE getState();
	Board getBoard();
	void setState(GAME_STATE);
	void start();
};