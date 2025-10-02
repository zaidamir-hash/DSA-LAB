#include <iostream>
#include <string>
using namespace std;

bool issafe(string** board, int row, int col, int n) {
    // Checking column for QUEEN
    for (int i = 0; i < row; i++) {
        if (board[i][col] == "Q")
            return false;
    }

    // Check upper-left diagonal for QUEEN
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == "Q")
            return false;
        i--; j--;
    }

    // Check upper-right diagonal for the QUEEEN
    i = row - 1; j = col + 1;
    while (i >= 0 && j < n) {
        if (board[i][j] == "Q")
            return false;
        i--; j++;
    }

    return true;
}

bool NQueens(string** board, int row, int n) {
    if (row == n) {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return true; 
    }

    for (int col = 0; col < n; col++) {
        if (issafe(board, row, col, n)) {
            board[row][col] = "Q";
            NQueens(board, row + 1, n);
            board[row][col] = "."; 
        }
    }

    return false;
}

int main() {
    int n = 4;
    string** board = new string*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new string[n];
        for (int j = 0; j < n; j++)
            board[i][j] = ".";
    }

    NQueens(board, 0, n);

    // Free memory
    for (int i = 0; i < n; i++)
        delete[] board[i];
    delete[] board;
}
