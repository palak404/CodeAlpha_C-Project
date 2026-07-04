#include<iostream>
using namespace std;

const int SIZE = 9;

//Function to print Sudoku grid
void printGrid(int grid[SIZE][SIZE])
{
    cout<< "\nSolved Sudoku:\n\n";

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            cout<< grid[i][j] << " ";
        }
        cout<<endl;
    }
}

// Check row
bool isRowSafe(int grid[SIZE][SIZE], int row, int num)
{
    for(int col = 0; col<SIZE;col++)
    {
        if(grid[row][col] == num)
             return false;
    }
    return true;
}

// Check column
bool isColSafe(int grid[SIZE][SIZE], int col, int num)
{
    for(int row=0; row<SIZE; row++)
    {
        if(grid[row][col] == num)
             return false;
    }
    return true;
}

// Check 3x3 box
bool isBoxSafe(int grid[SIZE][SIZE], int startRow, int startCol, int num)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
    {
        if(grid[startRow + i][startCol + j] == num)
             return false;
    }
    }
    return true;
}

// Check whether number can be placed
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    return isRowSafe(grid, row, num)&&
           isColSafe(grid, col, num)&&
           isBoxSafe(grid, row - row % 3, col - col % 3, num);

}

// Backtracking Function
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;
    bool found = false;

    // Find empty cell
    for(row=0; col<SIZE; col++)
    {
        for(col=0; col<SIZE; col++)
        {
            if(grid[row][col] == 0)
            {
                found = true;
                goto EMPTY;
            }
        }
    }
EMPTY:
    if(!found)
       return true;
    for(int num=1; num<=9; num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if(solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;    

        }
    }
    return false;
}

int main()
{
    int grid[SIZE][SIZE] =
    {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    cout << "Original Sudoku:\n\n";

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            cout<< grid[i][j] << " ";
        }
        cout<< endl;
    }
    if(solveSudoku(grid))
    {
        printGrid(grid);
    }
    else{
        cout<< "\nNo Solution Exists";
    }
    return 0;
}
