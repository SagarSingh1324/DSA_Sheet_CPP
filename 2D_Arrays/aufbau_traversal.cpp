/*
 * =====================================================================================
 *
 *       Filename:  aufbau_traversal.cpp
 *
 *    Description:  traverse the matrix in aufbau fashion 
 *
 *        Version:  1.0
 *        Created:  03/10/22 06:49:52 PM IST
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
 
void aufbau_traversal(std::vector<std::vector<int> > matrix)
{

    int row_num = matrix.size();
    int col_num = matrix[0].size();

    int i=0, j=0, sum=0;

    // top left half

    for (int  k = 0; k < row_num*col_num/2; k++)
    {
        if(( (i+j) == sum) && (i > -1) )
        {
            std::cout<<matrix[i][j]<<'\n';
            i--;
            j++;
        }
        else
        {
            sum++;
            i = sum;
            j = 0;
        }
    }

    // off diagonal

    i = row_num-1;
    j =0;

    for (int k = 0; k < row_num; k++)
    {
        std::cout<<matrix[i][j]<<'\n';
        i--;
        j++;
    }


 // bottom right half

    i = row_num-1;
    j =1;
    sum = row_num;

    for (int  k = 0; k < row_num*col_num/2; k++)
    {
        if(( (i+j) == sum) && (j < col_num) )
        {
            std::cout<<matrix[i][j]<<'\n';
            i--;
            j++;
        }
        else
        {
            sum++;
            i = row_num-1;
            j = sum - i;
        }
    }

}
 
 
//______main__function_____//

int main()
{

std::vector<std::vector<int> >  matrix;

matrix.push_back({1, 2, 3, 4});
matrix.push_back({5, 6, 7, 8});
matrix.push_back({9, 10,11,12});
matrix.push_back({13,14,15,16});

// result should be: [1,5,2,9,6,3,13,10,7,4,14,11,8,15,12,16]

aufbau_traversal(matrix);

return 0; 
}
