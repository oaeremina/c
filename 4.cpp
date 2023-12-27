#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Проверка вертикалей
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Проверка левых диагоналей
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Проверка правых диагоналей
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solveNQueensHelper(vector<vector<string>>& solutions, vector<string>& board, int row, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensHelper(solutions, board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));

    solveNQueensHelper(solutions, board, 0, n);

    return solutions;
}

int main() {
    int n;
    cout << "Введите размерность доски: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Все решения головоломки:" << endl;
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Решение " << i + 1 << ":" << endl;
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
