/*
 * =====================================================================================
 *
 *       Filename:  rotate_90_clockwise.cpp
 *
 *    Description:  rotate the matric 90 degrees in clockwise direction 
 *
 *        Version:  1.0
 *        Created:  03/10/22 06:50:32 PM IST
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
 
//_____secondary__functions______//
 
void rotate_matrix(std::vector<std::vector<int> > &temp_matrix)
{
    int row_num = temp_matrix.size();
    int col_num = temp_matrix[0].size();

    for (int i = 0; i < (row_num/2); i++)
    {
        temp_matrix[i].swap(temp_matrix[(row_num-1)-i]);
    }
    
    int i=0, j=1;

    while(j < col_num)
    {
        if(i < j)
        {
            while((i < row_num) && (i < j) )
            {
                int temp;
                temp = temp_matrix[i][j];
                temp_matrix[i][j] = temp_matrix[j][i];
                temp_matrix[j][i] = temp; 
                if(j+1 != col_num)
                {
                    j++;
                }
                else 
                {
                    j=0;
                }
            }
            i++;
        }
        else
        {
            j++;
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

// result should be: [[13,9,5,1],[14,10,6,2],[15,11,7,3],[16,12,8,4]]

rotate_matrix(matrix);

std::cout<<matrix[0][0]<<'\n';
std::cout<<matrix[0][1]<<'\n';
std::cout<<matrix[0][2]<<'\n';
std::cout<<matrix[0][3]<<'\n';
std::cout<<matrix[1][0]<<'\n';
std::cout<<matrix[1][1]<<'\n';
std::cout<<matrix[1][2]<<'\n';
std::cout<<matrix[1][3]<<'\n';
std::cout<<matrix[2][0]<<'\n';
std::cout<<matrix[2][1]<<'\n';
std::cout<<matrix[2][2]<<'\n';
std::cout<<matrix[2][3]<<'\n';
std::cout<<matrix[3][0]<<'\n';
std::cout<<matrix[3][1]<<'\n';
std::cout<<matrix[3][2]<<'\n';
std::cout<<matrix[3][3]<<'\n';

return 0; 
}
