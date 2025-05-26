#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
    TicTacToe game;
    int player = 1; // 玩家1先手
    int row, col;
    char again;

    do {
        game.resetGame(); // 重置遊戲
        int winner = 0;
        while (winner == 0) {
            game.displayBoard();
            cout << "玩家 " << player << " 請輸入行和列 (0-2): ";
            cin >> row >> col;

            if (game.placeMark(row, col, player)) {
                winner = game.checkWinner();
                if (winner != 0) {
                    game.displayBoard();
                    if (winner == 3) {
                        cout << "遊戲結束，平局！" << endl;
                    } else {
                        cout << "玩家 " << winner << " 勝出！" << endl;
                    }
                } else {
                    // 換下一個玩家
                    player = (player == 1) ? 2 : 1;
                }
            } else {
                cout << "無效位置，請重試。" << endl;
            }
        }
        cout << "是否要再玩一次？(y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}