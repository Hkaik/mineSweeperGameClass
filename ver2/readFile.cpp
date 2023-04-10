#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream boardFile;
	boardFile.open("board1.txt");

	string row;

	int m, n;
	boardFile >> m >> n;
	vector<vector<char*>> blocks;

	//-------------

	while (boardFile >> row) {
		vector<char*> boardRow;

		for (auto& i : row) {
			char* charPtr;

			if (i == 'O') {
				charPtr = new char('O');
			}
			else if (i == 'X') {
				charPtr = new char('X');
			}

			boardRow.push_back(charPtr);
		}
		blocks.push_back(boardRow);
	}

	for (auto& i : blocks) {
		for (auto &j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}
