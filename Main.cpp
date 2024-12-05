﻿#include <iostream>
#include <cstdlib>
#include "ChessBoard.h"
#include "Chess.h"
#include "Checker.h"
#include "Othello.h"
using namespace std;

int main() {
	int menu_c;
	ChessBoard chessboard;
	cout << "[1.체스] || [2.체커] || [3.오셀로]" << std::endl;
	cout << "플레이할 게임을 선택하세요: ";
	cin >> menu_c;

	if (menu_c == 1) {
		Chess chess(chessboard);
		chess.setupBoard();
		chess.showBoard();
		string loc;
		while (1) {
			std::string turn;
			if (chess.p_turn == s_White) {
				turn = "백";
			}
			else if (chess.p_turn == s_Black) {
				turn = "흑";
			}
			do {
				cout << turn + "차례 움직일 말을 선택하세요 (ex. A1, B4): ";
				cin >> loc;
			} while (!chess.currentSel(chess.p_turn, loc));
			chess.selectPiece(loc);
			chess.showBoard();
			do {
				cout << turn + "차례 움직일 곳을 선택하세요 (ex. A1, B4): ";
				cin >> loc;
			} while (!chess.currentSel(loc));
			chess.movePiece(loc);
			chess.showBoard();
			chess.changeturn();
			if (chess.isEnd()) {
				cout << "끝났습니다";
				break;
			}
		}
	}
	if (menu_c == 2) {
		Checker checker(chessboard);
		checker.setupBoard();
		checker.showBoard();
		string loc;
		while (1) {
			std::string turn;
			if (checker.p_turn == s_White) {
				turn = "백";
			}
			else if (checker.p_turn == s_Black) {
				turn = "흑";
			}
			do {
				cout << turn + "차례 움직일 말을 선택하세요 (ex. A1, B4): ";
				cin >> loc;
			} while (!checker.currentSel(checker.p_turn, loc));
			checker.selectPiece(loc);
			checker.showBoard();
			do {
				cout << turn + "차례 움직일 곳을 선택하세요 (ex. A1, B4): ";
				cin >> loc;
			} while (!checker.currentSel(loc));
			checker.movePiece(loc);
			checker.showBoard();
			if (!checker.isRemove) {
				checker.changeturn();
			}
			checker.isRemove = false;
			if (checker.isEnd()) {
				cout << "끝났습니다";
				break;
			}
		}
	}

	if (menu_c == 3) {
		Othello othello(chessboard);
		othello.setupBoard();
		othello.showBoard();
		string loc;
		while (1) {
			std::string turn;
			if (othello.p_turn == s_White) {
				turn = "백";
			}
			else if (othello.p_turn == s_Black) {
				turn = "흑";
			}
			do {
				cout << turn + "차례 움직일 말을 선택하세요 (ex. A1, B4): ";
				cin >> loc;
			} while (!othello.currentSel(othello.p_turn, loc));
			othello.selectPiece(loc);
			othello.showBoard();
			do {
				cout << turn + "차례 움직일 곳을 선택하세요 (ex. A1, B4): ";
				cin >> loc;
			} while (!othello.currentSel(loc));
			othello.movePiece(loc);
			othello.showBoard();
			othello.changeturn();
			if (othello.isEnd()) {
				cout << "끝났습니다";
				break;
			}
		}
	}
}