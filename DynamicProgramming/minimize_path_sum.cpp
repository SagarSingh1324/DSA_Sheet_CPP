/*
 * =====================================================================================
 *
 *       Filename:  minimize_path_sum.cpp
 *
 *    Description:  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
 *                  which minimizes the sum of all numbers along its path. 
 *
 *        Version:  1.0
 *        Created:  08/10/22 08:32:09 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/

#include<iostream>
#include<vector>
#include<algorithm>
 
//_____secondary__functions______//
 
int min_cost(std::vector<std::vector<int> > mat)
{
   int cost = 0;
   
   int num_rows = mat.size();
   int num_cols = mat[0].size();

   for (int i = 0; i < num_rows; i++)
   {
        for (int j = 0; j < num_cols; j++)
        {
            if((i-1) < 0 && (j-1) < 0)
            {
                mat[i][j] = mat[i][j];
            }
            else if( (i-1) < 0 && (j-1) >= 0)
            {
                mat[i][j] = mat[i][j]+mat[i][j-1];
            }
            else if( (j-1) < 0 && (i-1) >= 0)
            {
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }
            else
            {
                mat[i][j] = std::min((mat[i][j]+mat[i][j-1]),(mat[i][j]+mat[i-1][j]));
            }
        }  
   }

    return mat[num_rows-1][num_cols-1];
} 
 
//______main__function_____//
 
int main()
{
 
std::vector<std::vector<int> > mat;

mat.push_back({1,3,1});
mat.push_back({1,5,1});
mat.push_back({4,2,1});

std::cout<<min_cost(mat)<<std::endl;

return 0; 
}
