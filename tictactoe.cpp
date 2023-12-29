#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
bool checkWin(char board[3][3]);
bool placeMarker(char board[3][3], int position, char marker);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int position;
    char currentPlayer = 'X';
    int turns = 0;

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        printBoard(board);
        cout << "Player " << currentPlayer << " turn (choose a position 1-9): ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid input. Choose a position between 1 and 9.\n";
            continue;
        }

        if (!placeMarker(board, position, currentPlayer)) {
            cout << "Position already taken. Choose another position.\n";
            continue;
        }

        if (checkWin(board)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;
        }

        turns++;

        if (turns == 9) {
            printBoard(board);
            cout << "It's a draw!\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } while (!checkWin(board));

    return 0;
}

void printBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 0) cout << "|";
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return true; // Check rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return true; // Check columns
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || // Check diagonals
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }
    return false;
}

bool placeMarker(char board[3][3], int position, char marker) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    } else {
        board[row][col] = marker;
        return true;
    }
}
