#include "MineSweeperGame.h"
#include "GAME_STATE.h"
#include "Position.h"
#include <iostream>

using namespace std;

GAME_STATE MineSweeperGame::getState() {
	return this->state;
}

Board MineSweeperGame::getBoard() {
	return this->board;
}

void MineSweeperGame::setState(GAME_STATE currState) {
	this->state = currState;
}

void MineSweeperGame::start() {
	string command;

	while (this->state == GAME_STATE::STAND_BY) {
		cin >> command;

		if (command == "Load") {
			string loadCommand;
			cin >> loadCommand;

			if (loadCommand == "BoardFile") {
				string sourceFile;
				cin >> sourceFile;

				board.setBoard(sourceFile);
			}
		}
		else if (command == "StartGame") {
			this->state = GAME_STATE::PLAYING;
		}
	}

	while (this->state == GAME_STATE::PLAYING) {
		cin >> command;

		if (command == "Print") {
			string printCommand;
			cin >> printCommand;

			if (printCommand == "GameBoard") {
				board.printBoard();
			}
			else if (printCommand == "GameState") {
				cout << getState() << endl;
			}
			else if (printCommand == "GameAnswer") {
				board.printAnswer();
			}
			else if (printCommand == "BombCount") {
				cout << board.getBombCount() << endl;
			}
			else if (printCommand == "FlagCount") {
				cout << board.getFlagCount() << endl;
			}
			else if (printCommand == "OpenBlankCount") {
				cout << board.getOpenBlankCount() << endl;
			}
			else if (printCommand == "RemainBlankCount") {
				cout << board.getRemainBlankCount() << endl;
			}
		}
		else if (command == "LeftClick") {
			Position pos;
			cin >> pos.x >> pos.y;
			board.leftClick(pos);
		}
		else if (command == "RightClick") {
			Position pos;
			cin >> pos.x >> pos.y;
			board.rightClick(pos);
		}
	}

	cin >> command;
	if (command == "Replay") {
		start();
	}
	else if (command == "Quit") {
		return;
	}
}