#include <iostream>
#include <vector>

#define LEN 9

void print_board(const std::vector<std::vector<int>> &board)
{
    for (int row = 0; row < LEN; ++row)
    {
        for (int col = 0; col < LEN; ++col)
        {
            std::cout << board[row][col] << " ";
            if ((col + 1) % 3 == 0 && col < LEN - 1)
            {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        if ((row + 1) % 3 == 0 && row < LEN - 1)
        {
            std::cout << "------+-------+------" << std::endl;
        }
    }
}

int main()
{
    std::vector<std::vector<int>> sudokuBoard = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    std::cout << "Sudoku Grid:" << std::endl;
    print_board(sudokuBoard);

    return 0;
}