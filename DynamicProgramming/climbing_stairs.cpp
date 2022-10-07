/*
 * =====================================================================================
 *
 *       Filename:  climbing_stairs.cpp
 *
 *    Description:  You are climbing a staircase. It takes n steps to reach the top.
 *
 *		            Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
 *                  
 *                  Equivalent to Fibonacci sequence         
 *
 *        Version:  1.0
 *        Created:  06/10/22 08:43:55 PM IST
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

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 
//_____secondary__functions______//
 
int ways(int n) {
    
    std::vector<int> nthfibonacci;
    
    nthfibonacci.push_back(1);
    nthfibonacci.push_back(1);
    
    if(n == 0)
    {
        return nthfibonacci[0];
    }
    else if(n ==1)
    {
        return nthfibonacci[1];
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            nthfibonacci.push_back(nthfibonacci[i-1]+nthfibonacci[i-2]);
        }
        return nthfibonacci[n];
    }
    
    return -1;
}
 
 
//______main__function_____//
 
int main()
{
 
std::cout<<ways(5)<<std::endl;


return 0; 
}
