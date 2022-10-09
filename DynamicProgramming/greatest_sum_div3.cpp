/*
 * =====================================================================================
 *
 *       Filename:  greatest_sum_div3.cpp
 *
 *    Description:  given an array, find the greatest sum of array elements that is divisible by 3 
 *
 *        Version:  1.0
 *        Created:  09/10/22 01:19:29 PM IST
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

// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
 
//_____secondary__functions______//
 
int greatest_sum(std::vector<int> &nums)
{
    int nums_len = nums.size();

    std::sort(nums.begin(), nums.end());

    int nums_sum = 0;

    for (int i = 0; i < nums_len; i++)
    {
        nums_sum = nums_sum + nums[i];
    }

    int nums_sum_mod = nums_sum%3;


    if(nums_sum_mod == 0)
    {
        return nums_sum;
    }
    else if (nums_sum_mod == 1)
    {
        int i =0;

        while( ( (i < nums_len) && (nums[i]%3) != 1)  )
        {
            i++;
        }

        int j=0, k=0;

        while( (j < nums_len) && (nums[j]%3 != 2) )
        {
            j++;
        }

        k = j+1;

        while( (k < nums_len) && (nums[k]%3 != 2) )
        {
            k++;
        }

        if( (i<nums_len)&&(j<nums_len)&&(k<nums_len) )
        {
            if( nums[i] <= (nums[j]+nums[k]) )
            {
                return (nums_sum - nums [i]);
            }
            else if ( nums[i] > (nums[j]+nums[k]) )
            {
                return ( nums_sum - (nums[j]+nums[k]) );
            }
        }
        else if( (i>=nums_len) &&((j<nums_len)&&(k<nums_len)))
        {
            return ( nums_sum - (nums[j]+nums[k]) );
        }
        else if( (i<nums_len) &&((j>=nums_len)||(k>=nums_len)))
        {
            return (nums_sum - nums [i]);
        }

    }
    else if (nums_sum_mod == 2)
    {
        int i =0;

        while( ( (i < nums_len) && (nums[i]%3) != 2) )
        {
            i++;
        }

        int j=0, k=0;

        while( (j < nums_len) && (nums[j]%3 != 1) )
        {
            j++;
        }

        k = j+1;

        while((k < nums_len) && (nums[k]%3 != 1) )
        {
            k++;
        }

        if( (i<nums_len)&&(j<nums_len)&&(k<nums_len) )
        {
            if( nums[i] <= (nums[j]+nums[k]) )
            {
                return (nums_sum - nums [i]);
            }
            else if ( nums[i] > (nums[j]+nums[k]) )
            {
                return ( nums_sum - (nums[j]+nums[k]) );
            }
        }
        else if( (i>=nums_len) &&((j<nums_len)&&(k<nums_len)))
        {
            return ( nums_sum - (nums[j]+nums[k]) );
        }
        else if( (i<nums_len) &&((j>=nums_len)||(k>=nums_len)))
        {
            return (nums_sum - nums [i]);
        }
    }
    
    return nums_sum;
}
 
 
//______main__function_____//
 
int main()
{

std::vector<int> nums = {4};

int res = greatest_sum(nums);

std::cout<<res<<std::endl;

return 0; 
}

