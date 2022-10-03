/*
 * =====================================================================================
 *
 *       Filename:  traverse_matrix_spiral.cpp
 *
 *    Description:  traverse the matrix in a spiral manner 
 *
 *        Version:  1.0
 *        Created:  03/10/22 06:49:05 PM IST
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
#include<limits.h>


//_____secondary__functions______//
 
// function to traverse the matrix in spiral fashion 


void spiral_traversal(std::vector<std::vector<int> > temp_mat)
{
    int row_num = temp_mat.size();
    int col_num = temp_mat[0].size();
    

    int row_count =0;
    int col_count =0;

    for (int i = 0; i < row_num*col_num; i++)
    {

        if(temp_mat[row_count][col_count] != INT_MIN)
        {
            std::cout<<temp_mat[row_count][col_count]<<'\n';
            temp_mat[row_count][col_count]  = INT_MIN;        
        }
        else if( ((col_count+1) < col_num) && (temp_mat[row_count][col_count+1] != INT_MIN) )
        {
            while( ((col_count+1) < col_num) && (temp_mat[row_count][col_count+1] != INT_MIN) )
            {
                col_count++;
                std::cout<<temp_mat[row_count][col_count]<<'\n';
                temp_mat[row_count][col_count]  = INT_MIN;
            }
        }
        else if( ((row_count+1) < row_num) && (temp_mat[row_count+1][col_count] != INT_MIN) )
        {
            while( ((row_count+1) < row_num) && (temp_mat[row_count+1][col_count] != INT_MIN) )
            {
                row_count++;
                std::cout<<temp_mat[row_count][col_count]<<'\n';
                temp_mat[row_count][col_count]  = INT_MIN;
            }
        }
        else if( ((col_count-1) > -1) && (temp_mat[row_count][col_count-1] != INT_MIN) )
        {
            while( ((col_count-1) > -1) && (temp_mat[row_count][col_count-1] != INT_MIN) )
            {
                col_count--;
                std::cout<<temp_mat[row_count][col_count]<<'\n';
                temp_mat[row_count][col_count]  = INT_MIN;
            }
        }    
        else if( ((row_count-1) > -1) && (temp_mat[row_count-1][col_count] != INT_MIN) )
        {
            while( ((row_count-1) > -1) && (temp_mat[row_count-1][col_count] != INT_MIN) )
            {
                row_count--;
                std::cout<<temp_mat[row_count][col_count]<<'\n';
                temp_mat[row_count][col_count]  = INT_MIN;
            }
        }
    }        
}
 
 
//______main__function_____//
 
int main()
{

std::vector<std::vector<int> >  matrix;

matrix.push_back({1,2,3,4});
matrix.push_back({5,6,7,8});
matrix.push_back({9,10,11,12});
matrix.push_back({13,14,15,16});

// result should be: [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]

spiral_traversal(matrix);

return 0; 
}
