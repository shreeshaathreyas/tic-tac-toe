#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<char> &board) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if (i % 3 != 2)
            cout << "|";
        else if (i != 8)
            cout << "\n---+---+---\n";
    }
    cout << "\n";
}

bool isWinner(const vector<char> &board, char player) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto &pattern : winPatterns) {
        if (board[pattern[0]] == player && board[pattern[1]] == player && board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool isFull(const vector<char> &board) {
    for (char cell : board) {
        if (cell == ' ')
            return false;
    }
    return true;
}

int main() {
    vector<char> board(9, ' ');
    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        int position;
        cin >> position;

        if (position < 1 || position > 9 || board[position - 1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[position - 1] = currentPlayer;

        if (isWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isFull(board)) {
            displayBoard(board);
            cout << "It's a tie!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
