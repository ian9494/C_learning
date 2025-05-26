#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
private:
    int board[3][3]; // 0: empty, 1: player 1, 2: player 2
public:
    TicTacToe();
    
    void displayBoard(); //顯示棋盤
    bool placeMark(int row, int col, int player); // 放置標記，返回是否成功
    int checkWinner(); // 檢查是否有贏家，返回 0: 無人勝出, 1: 玩家1勝出, 2: 玩家2勝出 3: 平局
    void resetGame(); // 重置遊戲
};

#endif // TICTACTOE_H
