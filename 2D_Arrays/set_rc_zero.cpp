/*
 * =====================================================================================
 *
 *       Filenum:  set_rc_zero.cpp
 *
 *    Description:  given a matrix, for each zero element, set that element's row and column to zero 
 *
 *        Version:  1.0
 *        Created:  30/09/22 10:17:52 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/

/*
    Input: matrix = [[0,1,2,0]
                     [3,4,5,2]
                     [1,3,1,5]

    Output: [[0,0,0,0]
             [0,4,5,0]
             [0,3,1,0]]
*/

#include<iostream>
#include<vector>
#include<set>
 
//_____secondary__functions______//

// auxilairy function - mirror wrt diagonal

void mirror(std::vector<std::vector<int> >  &matrix)
{
    int row_num = matrix.size();
    int col_num = matrix[0].size();

    int i=0, j=1;

    while(j < col_num)
    {
        if(i < j)
        {
            while((i < row_num) && (i < j) )
            {
                int temp;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp; 
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

// set zeros function
 
void set_zeros(std::vector<std::vector<int> >  &matrix)
{
    int row_num = matrix.size();
    int col_num = matrix[0].size();

    std::vector<int> zero_rows;
    std::vector<int> zero_cols;


    std::vector<int> row_of_zeros;
    for (int i = 0; i < col_num; i++)
        row_of_zeros.push_back(0);

    std::vector<int> col_of_zeros;
    for (int i = 0; i < col_num; i++)
        col_of_zeros.push_back(0);
    



    for (int i = 0; i < row_num; i++)
    {

        for (int j = 0; j < col_num; j++)
        {
            if(matrix[i][j] == 0)
            {
                zero_rows.push_back(i);
                zero_cols.push_back(j);

            }
        }
    }

    for (int i = 0; i < zero_rows.size(); i++)
    {

        matrix[zero_rows[i]] = row_of_zeros;
    }
    
    mirror(matrix);

    for (int j = 0; j < zero_cols.size(); j++)
    {
        matrix[zero_cols[j]] = col_of_zeros;
    }    
    
    mirror(matrix);
    
}
 
 
//______main__function_____//
 
int main()
{

std::vector<std::vector<int> >  matrix;

// matrix.push_back({1, 2, 3, 4});
// matrix.push_back({5, 0, 7, 8});
// matrix.push_back({9, 10,11,12});
// matrix.push_back({13,14,0, 16});

/*
    result should be: [[1, 0,0,4 ]
                       [0, 0,0,0 ]
                       [9, 0,0,12] 
                       [0, 0,0,0 ]]
*/

// set_zeros(matrix);

// std::cout<<matrix[0][0]<<'\n';
// std::cout<<matrix[0][1]<<'\n';
// std::cout<<matrix[0][2]<<'\n';
// std::cout<<matrix[0][3]<<'\n';
// std::cout<<matrix[1][0]<<'\n';
// std::cout<<matrix[1][1]<<'\n';
// std::cout<<matrix[1][2]<<'\n';
// std::cout<<matrix[1][3]<<'\n';
// std::cout<<matrix[2][0]<<'\n';
// std::cout<<matrix[2][1]<<'\n';
// std::cout<<matrix[2][2]<<'\n';
// std::cout<<matrix[2][3]<<'\n';
// std::cout<<matrix[3][0]<<'\n';
// std::cout<<matrix[3][1]<<'\n';
// std::cout<<matrix[3][2]<<'\n';
// std::cout<<matrix[3][3]<<'\n';


matrix.push_back({0,1,2,0});
matrix.push_back({3,4,5,2});
matrix.push_back({1,3,1,5});

set_zeros(matrix);

return 0; 
}

