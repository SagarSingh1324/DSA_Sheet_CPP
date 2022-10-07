/*
 * =====================================================================================
 *
 *       Filename:  max_diff_0_1.cpp
 *
 *    Description:  given a string of 0's and 1's, find the substring with maximum differecne between 0's and 1's 
 *
 *        Version:  1.0
 *        Created:  06/10/22 05:45:33 PM IST
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
#include<string>
 
//_____secondary__functions______//
 
int max_diff(std::string str)
{
    int max=0;
    int len = str.length();

    std::vector<std::vector<int> > mat;

    std::vector<int> row1;


    if (str[0] == '1')
    {
        row1.push_back(-1);
        max = -1;
    }
    else if (str[0] == '0')
    {
        row1.push_back(1);
        max =1;
    }    
    

    for (int i = 1; i < len; i++)
    {
        if(str[i] == '1')
        {
            row1.push_back(row1[i-1]-1);

            if(row1[i]>max)
            {
                max= row1[i];
            }
        }
        else if (str[i] == '0')
        {
            row1.push_back(row1[i-1]+1);

            if(row1[i]>max)
            {
                max= row1[i];
            }
        }
    }       

    mat.push_back(row1);

    std::vector<int> temp;

    for (int i = 1; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (str[i-1] == '1')
            {
                temp.push_back(mat[i-1][j-i+1]+1);

                if((mat[i-1][j-i+1]+1)>max)
                {
                    max= (mat[i-1][j-i+1]+1);
                }
            }
            else if (str[i-1] == '0')
            {
                temp.push_back(mat[i-1][j-i+1]-1);

                if((mat[i-1][j-i+1]-1)>max)
                {
                    max= (mat[i-1][j-i+1]-1);
                }
            }
        }  

        mat.push_back(temp);
        temp.clear();
    }

    return max;
}
 
 
//______main__function_____//
 
int main()
{

std::string S;
S = "1100010010010001"; 

std::cout<<max_diff(S)<<std::endl;

//std::cout<<S[0]<<std::endl;

 
return 0; 
}


