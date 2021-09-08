// counthsw.cpp
// Robert Lawton
// 29 Sept 2020
//
// For CS311 Fall 2020
// Source for Project 4: Counting Holey Spider Walks

#include "counthsw.h"
#include <vector>
using std::vector;


// countHSW
// Documentaion in header.
int countHSW(int dim_x, int dim_y,             // Board dimensions
             int hole_x, int hole_y,           // Hole Coordinates
             int start_x, int start_y,         // Start square coordinates
             int finish_x, int finish_y)       // Finish square coordinates
{
    // Create empty partial solution
    vector<vector<int>> board(dim_x, vector<int>(dim_y,0));

    int tiles_remaining = (dim_x*dim_y) - 2;

    // Define position of start
    board[start_x][start_y] = 1;

    // Define position of hole
    board[hole_x][hole_y] = 1;

    // Current position of spider
    int current_x = start_x;
    int current_y = start_y;
    return countHSW_recurse(board,dim_x, dim_y, finish_x, finish_y, 
                            current_x, current_y, tiles_remaining);

}

int countHSW_recurse(vector<vector<int>> & board,  // Vector of already visited tiles
                     int dim_x, int dim_y,         // Board dimensions
                     int finish_x, int finish_y,   // Finish square coordinates
                     int current_x, int current_y, // Current square coordinates
                     int tiles_remaining)          // Number of tiles still available. 
{
    int solutions_count = 0; // Running count of solutions

    // Base Case
    if (tiles_remaining == 0 && current_x == finish_x && current_y == finish_y)
    {
        return 1;
    }

    // Recursive Case
    for (int x = -1; x <= 1; ++x){
        for (int y = -1; x <= 1; ++y){

            if(x == 0 && y == 0) continue;

            if ((current_x + x) < 0 || (current_x + x) > (dim_x - 1) 
             ||(current_y + y) < 0 || (current_y + y) > (dim_x - 1)) continue;

            if (board[current_x + x][current_y + y] == 0){

                current_x += x;
                current_y += y;

                board[current_x][current_y] = 1;
                --tiles_remaining;

                solutions_count += countHSW_recurse(board, dim_x, dim_y, finish_x, finish_y, 
                                                    current_x, current_y, tiles_remaining);
                
                board[current_x][current_y] = 0;
                current_x -= x;
                current_y -= y;
                ++tiles_remaining;
            }
        }
    }

    return solutions_count;
}