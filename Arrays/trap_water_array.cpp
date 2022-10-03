/*
 * =====================================================================================
 *
 *       Filename:  trap_water_array.cpp
 *
 *    Description:  If the array is represented as tetris, how much water does it trap 
 *
 *        Version:  1.0
 *        Created:  30/09/22 10:39:41 AM IST
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
 
int trapped_water(std::vector<int> &arr)
{
    int water;

    for (int i = 0; i < arr.size(); i++)
    {

        /* code */
    }
    


    return water;
}
 
 
//______main__function_____//
 
int main()
{

std::vector<int> arr;

arr.push_back(0);
arr.push_back(1);
arr.push_back(0);
arr.push_back(2);
arr.push_back(1);
arr.push_back(0);
arr.push_back(1);
arr.push_back(3);
arr.push_back(2);
arr.push_back(1);
arr.push_back(2);
arr.push_back(1);

 
return 0; 
}

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6