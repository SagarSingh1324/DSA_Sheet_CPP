/*
 * =====================================================================================
 *
 *       Filename:  largest_1_borded_square.cpp
 *
 *    Description:  Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid. 
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:58:13 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/


// Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid

#include<iostream>
#include<vector>
 
//_____secondary__functions______//
 
int largestBorderedSquare(std::vector<std::vector<int> > &grid)
{
    int num_ones;







    return num_ones;
}
 
 
//______main__function_____//
 
int main()
{

std::vector<std::vector<int> > grid;

grid.push_back({1,1,1});
grid.push_back({1,0,1});
grid.push_back({1,1,1});

std::cout<<largestBorderedSquare(grid)<<std::endl;
 
return 0; 
}