#include<iostream>
#include<vector>
#include<bits/stdc++.h>
 
//_____secondary__functions______//
 
int getMaximumGenerated(int n) {
    
    std::vector<int> nums;
    
    nums.push_back(0);
    nums.push_back(1);
    
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    
    for(int i=2; i<=n; i++)
    {
        if(i%2 == 0)
        {
            nums.push_back(nums[i/2]);
        }
        else if(i%2 == 1)
        {
            nums.push_back(nums[(i-1)/2]+nums[((i-1)/2)+1]);
        }
    }
    
    return *max_element(nums.begin(), nums.end());
    
}
 
 
//______main__function_____//
 
int main()
{
 
std::cout<<getMaximumGenerated(7)<<std::endl;

return 0; 
}