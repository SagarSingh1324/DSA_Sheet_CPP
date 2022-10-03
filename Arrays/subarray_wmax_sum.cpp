/*
 * =====================================================================================
 *
 *       Filename:  subarray_wmax_sum.cpp
 *
 *    Description:  find the subarray with maximum sum  { kadane'salgorithm}
 *
 *        Version:  1.0
 *        Created:  30/09/22 09:30:24 AM IST
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
 #include<climits>

//_____secondary__functions______//

int max_sub(std::vector<int> &arr)
{
    int max_so_far = INT_MIN, max_ending_here = 0;    ///   very important - INT_MAX and INT_MIN
 
    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
} 
 
//______main__function_____//
 
int main()
{

    std::vector<int>  arr;

    arr.push_back(-2);
    arr.push_back(1);
    arr.push_back(-3);
    arr.push_back(4);
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(-5);
    arr.push_back(4);

    // arr.push_back(-2);
    // arr.push_back(-1);
    // arr.push_back(-3);

    int res =max_sub(arr);

    std::cout<<res<<std::endl;

    return 0;
}
