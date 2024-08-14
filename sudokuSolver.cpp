#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define LEN 9

void print_board(const vector<vector<int>> &board)
{
    for (int row = 0; row < LEN; ++row)
    {
        for (int col = 0; col < LEN; ++col)
        {
            cout << board[row][col] << " ";
            if ((col + 1) % 3 == 0 && col < LEN - 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
        if ((row + 1) % 3 == 0 && row < LEN - 1)
        {
            cout << "------+-------+------" << endl;
        }
    }
}

bool isUsedInRow(const vector<vector<int>> &board, int row, int num)
{
    for (int i = 0; i < LEN; ++i) {
        if (board[row][i] == num) {
            return true;
        }
    }
    return false;
}

bool isUsedInCol(const vector<vector<int>> &board, int col, int num)
{
    for (int i = 0; i < LEN; ++i) {
        if (board[i][col] == num) {
            return true;
        }
    }
    return false;
}

bool isUsedInSq(const vector<vector<int>> &board, int row, int col, int num)
{
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(const vector<vector<int>> &board, int row, int col, int num)
{
    return !isUsedInRow(board, row, num) &&
           !isUsedInCol(board, col, num) &&
           !isUsedInSq(board, row, col, num) &&
           board[row][col] == 0;
}

bool zeroExist(const vector<vector<int>> &board, int &row, int &col)
{
    for (row = 0; row < LEN; ++row) {
        for (col = 0; col < LEN; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve(vector<vector<int>> &board)
{
    int row, col;
    if (!zeroExist(board, row, col)) {
        return true;
    }

    for (int num = 1; num <= LEN; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solve(board)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void printResult(vector<vector<int>> &board){
    cout << "Sudoku Grid:" << endl;
    print_board(board);
    cout << "-------------------------------------" << endl;
    auto start = high_resolution_clock::now();
    if (solve(board)) {
        auto stop = high_resolution_clock::now();
        cout << "Solved Sudoku Grid:" << endl;
        print_board(board);
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    } else {
        cout << "No solution exists" << endl;
    }
}

int main()
{
    vector<vector<int>> sudokuBoard = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    printResult(sudokuBoard);
    cout << "-------------------------------------" << endl;

    return 0;
}