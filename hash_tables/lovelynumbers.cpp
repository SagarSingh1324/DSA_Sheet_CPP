/*
 * =====================================================================================
 *
 *       Filename:  lovelynumbers.cpp
 *
 *    Description:  find numbers that are lonely 
 *
 *        Version:  1.0
 *        Created:  14/10/22 03:38:55 AM IST
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
#include<set>
 
//_____secondary__functions______//
 
std::vector<int> findLonely(std::vector<int>  &nums)
{
    std::set<int> temp;
    
    int len = nums.size();
    
    std::vector<int> res;

    for (int i = 0; i < len; i++)
    {
        temp.insert(nums[i]);
    }
    
    
    for( int i=0; i < len; i++)
    { 

        if( temp.find(nums[i]-1) == temp.end() )
        {
            if ( (temp.find(nums[i]+1) == temp.end()) )
            {
                res.push_back(nums[i]);
            }
        }

    }
    
    return res;
} 
 
//______main__function_____//
 
int main()
{

std::vector<int> inp;

inp.push_back(1);
inp.push_back(3);
inp.push_back(5);
inp.push_back(3);

std::vector<int> result;
result = findLonely(inp);

std::cout<<result[0]<<'\n'<<result[1]<<std::endl;
 
return 0; 
}