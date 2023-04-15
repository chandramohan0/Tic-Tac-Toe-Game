#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';

void drawBoard() {
    cout << "  1   2   3" << endl;
    cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMark(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid move. Please enter a row and column between 1 and 3." << endl;
        return false;
    }
    if (board[row][col] != ' ') {
        cout << "Invalid move. That spot is already taken." << endl;
        return false;
    }
    board[row][col] = player;
    return true;
}

void changePlayer() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

bool checkForWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

bool checkForDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    drawBoard();
    while (true) {
        cout << "Player " << player << ", enter row (1-3): ";
        int row;
        cin >> row;
        cout << "Player " << player << ", enter column (1-3): ";
        int col;
        cin >> col;
        if (placeMark(row-1, col-1)) {
            drawBoard();
            if (checkForWin()) {
                cout << "Player " << player << " wins!" << endl;
                break;
            } else if (checkForDraw()) {
                cout << "Match " << player << " drawn!" << endl;
                break;
            }
            changePlayer();
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    return 0;
}
