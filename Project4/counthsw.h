// counthsw.h
// Robert Lawton
// 29 Sept 2020
//
// For CS 311 Fall 2020
// Header for Project 4: Counting Holey Spider Walks

#ifndef FILE_COUNTHSW_H_INCLUDED
#define FILE_COUNTHSW_H_INCLUDED

#include <vector>
using std::vector;


// Pre: dim_x > 0           && dim_y > 0
//      dim_x > hole_x >= 0  && dim_y > hole_y >= 0 
//      dim_x > start_x >= 0  && dim_y > start_x >= 0 
//      dim_x > finish_x >= 0  && dim_y > finish_y >= 0
int countHSW(int dim_x, int dim_y,              // Board dimensions
             int hole_x, int hole_y,            // Hole Coordinates
             int start_x, int start_y,          // Start square coordinates
             int finish_x, int finish_y);       // Finish square coordinates

int countHSW_recurse(vector<vector<int>> & board,  // Vector of already visited tiles
                     int dim_x, int dim_y,         // Board dimensions
                     int finish_x, int finish_y,   // Finish square coordinates
                     int current_x, int current_y, // Current square coordinates
                     int tiles_remaining);          // Number of tiles still available. 

#endif  // #ifndef FILE_COUNTHSW_H_INCLUDED