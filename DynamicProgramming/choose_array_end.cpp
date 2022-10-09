/*
 * =====================================================================================
 *
 *       Filename:  choose_array_end.cpp
 *
 *    Description:  Game theory problem - see the example commented below 
 *
 *        Version:  1.0
 *        Created:  09/10/22 03:17:18 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/


// Input: nums = [1,5,233,7]
// Output: true
// Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

#include<iostream>
#include<vector>
#include<algorithm>
 
//_____secondary__functions______//
 
bool can_A_win(std::vector<int> &nums)
{

    int A_score = 0;
    int B_score = 0;

    int A_turn = 1;
    int B_turn = -1;

    while(nums.size() != 0)
    {

        if(A_turn == 1)
        {
            if(nums.size() >= 4)
            {

                if( std::max(nums[1], nums[nums.size()-1]) > std::max(nums[0], nums[nums.size()-2]) )
                {
                    std::vector<int>::iterator it;
                    it = (nums.end()-1);
                    A_score = A_score + *it;
                    nums.erase(it);
                }
                else if( std::max(nums[1], nums[nums.size()-1]) < std::max(nums[0], nums[nums.size()-2]) )
                {
                    std::vector<int>::iterator it;
                    it = nums.begin();
                    A_score = A_score + *it;
                    nums.erase(it);
                }
                else if( std::max(nums[1], nums[nums.size()-1]) == std::max(nums[0], nums[nums.size()-2]) )
                {
                    if( nums[0] >= nums[nums.size()-1] )
                    {
                        std::vector<int>::iterator it;
                        it = nums.begin();
                        A_score = A_score + *it;
                        nums.erase(it);
                    }
                    else if ( nums[0] < nums[nums.size()-1] )
                    {
                        std::vector<int>::iterator it;
                        it = (nums.end()-1);
                        A_score = A_score + *it;
                        nums.erase(it);
                    }
                }
            }
            else if(nums.size()<=3 && nums.size() >=2)
            {
                if(nums[0] >= nums[nums.size()-1])
                {
                    std::vector<int>::iterator it;
                    it = nums.begin();
                    A_score = A_score + *it;
                    nums.erase(it);
                }
                else 
                {
                    std::vector<int>::iterator it;
                    it = (nums.end()-1);
                    A_score = A_score + *it;
                    nums.erase(it);
                }
            }
            else
            {

                std::vector<int>::iterator it;
                it = nums.begin();
                A_score = A_score + *it;
                nums.erase(it);

            }

            A_turn = A_turn*(-1);
            B_turn = B_turn*(-1);

        }
        else if(B_turn == 1)
        {
            if(nums.size() >= 4)
            {

                if( std::max(nums[1], nums[nums.size()-1]) > std::max(nums[0], nums[nums.size()-2]) )
                {
                    std::vector<int>::iterator it;
                    it = (nums.end()-1);
                    B_score = B_score + *it;
                    nums.erase(it);
                }
                else if( std::max(nums[1], nums[nums.size()-1]) < std::max(nums[0], nums[nums.size()-2]) )
                {
                    std::vector<int>::iterator it;
                    it = nums.begin();
                    B_score = B_score + *it;
                    nums.erase(it);
                }
                else if( std::max(nums[1], nums[nums.size()-1]) == std::max(nums[0], nums[nums.size()-2]) )
                {
                    if( nums[0] >= nums[nums.size()-1] )
                    {
                        std::vector<int>::iterator it;
                        it = nums.begin();
                        B_score = B_score + *it;
                        nums.erase(it);
                    }
                    else if ( nums[0] < nums[nums.size()-1] )
                    {
                        std::vector<int>::iterator it;
                        it = (nums.end()-1);
                        B_score = B_score + *it;
                        nums.erase(it);
                    }
                }
            }
            else if(nums.size()<=3 && nums.size() >=2)
            {
                if(nums[0] >= nums[nums.size()-1])
                {
                    std::vector<int>::iterator it;
                    it = nums.begin();
                    B_score = B_score + *it;
                    nums.erase(it);
                }
                else 
                {
                    std::vector<int>::iterator it;
                    it = (nums.end()-1);
                    B_score = B_score + *it;
                    nums.erase(it);
                }
            }
            else
            {

                std::vector<int>::iterator it;
                it = nums.begin();
                B_score = B_score + *it;
                nums.erase(it);

            }

            A_turn = A_turn*(-1);
            B_turn = B_turn*(-1);

        }

    }

    if(A_score >= B_score)
    {
        return true;
    }

    return false;

}
 
 
//______main__function_____//
 
int main()
{

    std::vector<int> nums = {10,17,11,16,17,9,14,17,18,13,11,4,17,18,15,3,13,10};

    std::cout<<can_A_win(nums)<<std::endl;
 
    return 0; 
}