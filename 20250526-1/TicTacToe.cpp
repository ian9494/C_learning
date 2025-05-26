#include <iostream>
#include <stdlib.h>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() {
    resetGame();
}

// 初始化棋盤為空
void TicTacToe::resetGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0; 
        }
    }
}

// 顯示棋盤
void TicTacToe::displayBoard() {
    system("cls"); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                cout << "□";
            } else if (board[i][j] == 1) {
                cout << "X";
            } else {
                cout << "O";
            }
        }
        cout << endl;
    }
}

// 放置標記，返回是否成功
bool TicTacToe::placeMark(int row, int col, int player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != 0) {
        return false; // 無效位置或已被佔用
    }
    board[row][col] = player;
    return true;
}

// 檢查是否有贏家，返回 0: 無人勝出, 1: 玩家1勝出, 2: 玩家2勝出, 3: 平局
int TicTacToe::checkWinner() {
    // 檢查行
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0]; // 返回贏家
        }
    }
    
    // 檢查列
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j]; // 返回贏家
        }
    }
    
    // 檢查對角線
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0]; // 返回贏家
    }
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2]; // 返回贏家
    }
    
    // 檢查平局
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0; // 還有空位，無人勝出
            }
        }
    }
    
    return 3; // 平局
}