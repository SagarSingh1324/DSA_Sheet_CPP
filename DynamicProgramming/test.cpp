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
                if( std::max(nums[1], nums[nums.size()-2]) > std::max(nums[0], nums[nums.size()-1]) )
                {
                    if(nums[1] > nums[nums.size()-2])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.end()-1);
                        A_score = A_score + *it;
                        nums.erase(it);
                    }
                    else if(nums[1] < nums[nums.size()-2])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.begin());
                        A_score = A_score + *it;
                        nums.erase(it);                        
                    }
                    else if(nums[1] == nums[nums.size()-2])
                    {
                        if(nums[0] >= nums[nums.size()-1])
                        {
                            std::vector<int>::iterator it;
                            it = (nums.begin());
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
                }
                else if( std::max(nums[1], nums[nums.size()-2]) < std::max(nums[0], nums[nums.size()-1]) )
                {

                    if(nums[0] < nums[nums.size()-1])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.end()-1);
                        A_score = A_score + *it;
                        nums.erase(it);
                    }
                    else if(nums[0] > nums[nums.size()-1])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.begin());
                        A_score = A_score + *it;
                        nums.erase(it);                        
                    }
                    else if(nums[0] == nums[nums.size()-1])
                    {
                        if(nums[1] >= nums[nums.size()-2])
                        {
                            std::vector<int>::iterator it;
                            it = (nums.end()-1);
                            A_score = A_score + *it;
                            nums.erase(it);                               
                        }
                        else
                        {
                            std::vector<int>::iterator it;
                            it = (nums.begin());
                            A_score = A_score + *it;
                            nums.erase(it);   
                        }
                    }
                    
                }
                else if( std::max(nums[1], nums[nums.size()-2]) == std::max(nums[0], nums[nums.size()-1]) )
                {
                    if( (nums[0] >= nums[nums.size()-1]) ) //&& (nums[1] >= nums[nums.size()-2]) )
                    {

                            std::vector<int>::iterator it;
                            it = (nums.begin());
                            B_score = B_score + *it;
                            nums.erase(it);

                        // if(nums[nums.size()-1] >= nums[nums.size()-2])
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.end()-1);
                        //     A_score = A_score + *it;
                        //     nums.erase(it);
                        // }
                        // else
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.begin());
                        //     A_score = A_score + *it;
                        //     nums.erase(it);
                        // }
                    }
                    else if ( (nums[0] <= nums[nums.size()-1]) ) //&& (nums[1] <= nums[nums.size()-2]) )
                    {

                            std::vector<int>::iterator it;
                            it = (nums.end()-1);
                            B_score = B_score + *it;
                            nums.erase(it);

                        // if(nums[0] >= nums[1])
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.begin());
                        //     A_score = A_score + *it;
                        //     nums.erase(it);
                        // }
                        // else
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.end()-1);
                        //     A_score = A_score + *it;
                        //     nums.erase(it);
                        // }
                    }
                    // else if( (nums[0] >= nums[nums.size()-1]) && (nums[1] <= nums[nums.size()-2]) )
                    // {
                    //     if(nums[nums.size()-1] >= nums[1])
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.end()-1);
                    //         A_score = A_score + *it;
                    //         nums.erase(it);
                    //     }
                    //     else
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.begin());
                    //         A_score = A_score + *it;
                    //         nums.erase(it);
                    //     }
                    // }
                    // else if( (nums[0] <= nums[nums.size()-1]) && (nums[1] >= nums[nums.size()-2]) )
                    // {
                    //     if(nums[0] >= nums[nums.size()-2])
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.begin());
                    //         A_score = A_score + *it;
                    //         nums.erase(it);
                    //     }
                    //     else
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.end()-1);
                    //         A_score = A_score + *it;
                    //         nums.erase(it);
                    //     }
                    // }
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

        }  /////////////////-----------------------------------------------------////////////////////////----------------------------------/////////////////////---------------------------//////////////// 
        else if(B_turn == 1)
        {
            if(nums.size() >= 4)
            {
                if( std::max(nums[1], nums[nums.size()-2]) > std::max(nums[0], nums[nums.size()-1]) )
                {
                    if(nums[1] > nums[nums.size()-2])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.end()-1);
                        B_score = B_score + *it;
                        nums.erase(it);
                    }
                    else if(nums[1] < nums[nums.size()-2])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.begin());
                        B_score = B_score + *it;
                        nums.erase(it);                        
                    }
                    else if(nums[1] == nums[nums.size()-2])
                    {
                        if(nums[0] >= nums[nums.size()-1])
                        {
                            std::vector<int>::iterator it;
                            it = (nums.begin());
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
                }
                else if( std::max(nums[1], nums[nums.size()-2]) < std::max(nums[0], nums[nums.size()-1]) )
                {

                    if(nums[0] > nums[nums.size()-1])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.begin());
                        B_score = B_score + *it;
                        nums.erase(it);
                    }
                    else if(nums[0] < nums[nums.size()-1])
                    {
                        std::vector<int>::iterator it;
                        it = (nums.end()-1);
                        B_score = B_score + *it;
                        nums.erase(it);                        
                    }
                    else if(nums[0] == nums[nums.size()-1])
                    {
                        if(nums[1] >= nums[nums.size()-2])
                        {
                            std::vector<int>::iterator it;
                            it = (nums.end()-1);
                            B_score = B_score + *it;
                            nums.erase(it);                               
                        }
                        else
                        {
                            std::vector<int>::iterator it;
                            it = (nums.begin());
                            B_score = B_score + *it;
                            nums.erase(it);   
                        }
                    }
                    
                }
                else if( std::max(nums[1], nums[nums.size()-2]) == std::max(nums[0], nums[nums.size()-1]) )
                {
                    if( (nums[0] >= nums[nums.size()-1]) ) //&& (nums[1] >= nums[nums.size()-2]) )
                    {

                        std::vector<int>::iterator it;
                        it = (nums.begin());
                        B_score = B_score + *it;
                        nums.erase(it);

                        // if(nums[nums.size()-1] >= nums[nums.size()-2])
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.end()-1);
                        //     B_score = B_score + *it;
                        //     nums.erase(it);
                        // }
                        // else
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.begin());
                        //     B_score = B_score + *it;
                        //     nums.erase(it);
                        // }
                    }
                    else if ( (nums[0] <= nums[nums.size()-1]) ) // && (nums[1] <= nums[nums.size()-2]) )
                    {

                            std::vector<int>::iterator it;
                            it = (nums.end()-1);
                            B_score = B_score + *it;
                            nums.erase(it);

                        // if(nums[0] >= nums[1])
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.begin());
                        //     B_score = B_score + *it;
                        //     nums.erase(it);
                        // }
                        // else
                        // {
                        //     std::vector<int>::iterator it;
                        //     it = (nums.end()-1);
                        //     B_score = B_score + *it;
                        //     nums.erase(it);
                        // }
                    }
                    // else if( (nums[0] >= nums[nums.size()-1]) && (nums[1] <= nums[nums.size()-2]) )
                    // {
                    //     if(nums[nums.size()-1] >= nums[1])
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.end()-1);
                    //         B_score = B_score + *it;
                    //         nums.erase(it);
                    //     }
                    //     else
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.begin());
                    //         B_score = B_score + *it;
                    //         nums.erase(it);
                    //     }
                    // }
                    // else if( (nums[0] <= nums[nums.size()-1]) && (nums[1] >= nums[nums.size()-2]) )
                    // {
                    //     if(nums[0] >= nums[nums.size()-2])
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.begin());
                    //         B_score = B_score + *it;
                    //         nums.erase(it);
                    //     }
                    //     else
                    //     {
                    //         std::vector<int>::iterator it;
                    //         it = (nums.end()-1);
                    //         B_score = B_score + *it;
                    //         nums.erase(it);
                    //     }
                    // }
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

    std::vector<int> nums = {1000,999,999,1000,555,400};

    std::cout<<can_A_win(nums)<<std::endl;
 
    return 0; 
}