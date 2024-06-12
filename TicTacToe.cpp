#include <iostream>
#include <cstdlib>
#include <ctime>


/* Author: Jeffery Reed
 Description: Tic Tac Toe Part 2
 Lab Section: CS-130 Online
 Class: CS-130-50-4242
 Date: 04/03/2024
*/

class TicTacToe {
protected:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        // Randomly decide who goes first
        srand(time(0));
        currentPlayer = (rand() % 2 == 0) ? 'X' : 'O';
    }

    void printBoard() {
        std::cout << "  0 1 2" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "--------" << std::endl;
            std::cout << i << "|";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) {
                    std::cout << "|";
                }
            }
            std::cout << std::endl << " |";
        }
        std::cout << std::endl;
    }

    virtual bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Illegal move. Try again." << std::endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    virtual bool checkWin(char player) {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true; // Row
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true; // Column
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true; // Diagonal
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true; // Diagonal
        }
        return false;
    }

    bool isBoardFull() {
        // Check if the board is full
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    virtual void play() {
        int row, col;
        bool gameOver = false;

        while (!gameOver) {
            printBoard();
            std::cout << "Current player: " << currentPlayer << std::endl;
            if (currentPlayer == 'X') {
                std::cout << "Enter your move (row column): ";
                std::cin >> row >> col;
            } else {
                // Automated player O
                row = rand() % 3;
                col = rand() % 3;
                while (board[row][col] != ' ') {
                    row = rand() % 3;
                    col = rand() % 3;
                }
                std::cout << "Player O chose: " << row << " " << col << std::endl;
            }

            if (makeMove(row, col)) {
                if (checkWin(currentPlayer)) {
                    printBoard();
                    std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                    gameOver = true;
                } else if (isBoardFull()) {
                    printBoard();
                    std::cout << "It's a draw!" << std::endl;
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }
        }
    }
};

class TicTacToe3D : public TicTacToe {
protected:
    char board[3][3][3];

public:
    TicTacToe3D() : TicTacToe() {
        // Initialize the 3D board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    board[i][j][k] = ' ';
                }
            }
        }
    }

void printBoard()  {
    // Print the 3D board using ASCII art
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "Layer " << i << ":" << std::endl;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                std::cout << board[i][j][k];
                if (k < 2) {
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
        }
        if (i < 2) {
            std::cout << "-----------" << std::endl;
        }
    }
    std::cout << std::endl;
}




    bool makeMove(int x, int y, int z)  {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || z < 0 || z >= 3 || board[x][y][z] != ' ') {
        std::cout << "Illegal move. Try again." << std::endl;
        return false;
    }
    board[x][y][z] = currentPlayer;
    return true;
}

bool checkWin(char player) {
    // Check rows, columns, diagonals, and 3D diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0][0] == player && board[i][1][1] == player && board[i][2][2] == player) ||
            (board[i][0][2] == player && board[i][1][1] == player && board[i][2][0] == player)) {
            return true; // Diagonals in XY plane
        }
        if ((board[i][0][0] == player && board[i][0][1] == player && board[i][0][2] == player) ||
            (board[i][1][0] == player && board[i][1][1] == player && board[i][1][2] == player) ||
            (board[i][2][0] == player && board[i][2][1] == player && board[i][2][2] == player) ||
            (board[i][0][0] == player && board[i][1][0] == player && board[i][2][0] == player) ||
            (board[i][0][1] == player && board[i][1][1] == player && board[i][2][1] == player) ||
            (board[i][0][2] == player && board[i][1][2] == player && board[i][2][2] == player) ||
            (board[i][0][0] == player && board[i][1][1] == player && board[i][2][2] == player) ||
            (board[i][0][2] == player && board[i][1][1] == player && board[i][2][0] == player)) {
            return true; // Rows, columns, and diagonals in XZ plane
        }
    }

    // Check diagonals in other planes
    if ((board[0][0][0] == player && board[1][1][1] == player && board[2][2][2] == player) ||
        (board[0][0][2] == player && board[1][1][1] == player && board[2][2][0] == player) ||
        (board[0][2][0] == player && board[1][1][1] == player && board[2][0][2] == player) ||
        (board[0][2][2] == player && board[1][1][1] == player && board[2][0][0] == player)) {
        return true; // Diagonals in XYZ direction
    }

    // Check rows, columns, and diagonals in Z direction
    for (int i = 0; i < 3; ++i) {
        if ((board[0][0][i] == player && board[1][1][i] == player && board[2][2][i] == player) ||
            (board[0][2][i] == player && board[1][1][i] == player && board[2][0][i] == player)) {
            return true; // Diagonals in Z direction
        }
        if ((board[i][0][0] == player && board[i][1][1] == player && board[i][2][2] == player) ||
            (board[i][0][2] == player && board[i][1][1] == player && board[i][2][0] == player)) {
            return true; // Rows and columns in Z direction
        }
    }

    return false;
}


    bool isBoardFull()  {
        // Check if the board is full
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (board[i][j][k] == ' ') {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    TicTacToe3D game;
    game.play();
    return 0;
}

