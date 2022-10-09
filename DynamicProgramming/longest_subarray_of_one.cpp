/*
 * =====================================================================================
 *
 *       Filename:  longest_subarray_of_one.cpp
 *
 *    Description:  Given a binary array nums, you should delete one element from it.
 *                  Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
 *                  Return 0 if there is no such subarray. 
 *
 *        Version:  1.0
 *        Created:  08/10/22 08:53:46 PM IST
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
 
int longest_subarray(std::vector<int> &nums)
{
    int subarray_length =0;

    nums.push_back(0);

    int nums_len = nums.size();

    int i = -1, j = -1, temp_len =0;

    for (int k = 0; k < nums_len; k++)
    {
        if( (nums[k] == 0) || (k == (nums_len-1)) )
        {
            if( i == j)
            {
                temp_len = k-i-1;
            }
            else
            {
                temp_len = k-i-2;
            }

            i = j;
            j = k;

            if(temp_len > subarray_length)
            {
                subarray_length = temp_len;
                temp_len =0;
            }
        }

    }
    
    if(subarray_length == nums_len -1)
    {
        return subarray_length -1;
    }

    return subarray_length;
} 
 
//______main__function_____//
 
int main()
{

std::vector<int> nums = {1,1,1};

std::cout<<longest_subarray(nums)<<std::endl;
 
return 0; 
}
