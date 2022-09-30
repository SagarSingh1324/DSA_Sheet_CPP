/*
 * =====================================================================================
 *
 *       Filename:  max_profit.cpp
 *
 *    Description:  buy and sell stocks from array to max profit  
 *
 *        Version:  1.0
 *        Created:  29/09/22 02:06:37 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<bits/stdc++.h>

//___globals_____//

int max_profit = 0;

//_____secondary__functions______//
 
int profit(std::vector<int> arr)
{
    int max=0;
    int min=0;

    max = arr[0];
    min = arr[0];

    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            max = arr[i];
        }
        else if(arr[i] > max)
        {
            max = arr[i];
        }
        if((max-min) > max_profit)
        {
            max_profit = max-min;
        }    
    }
    return max_profit;
}
 
 
//______main__function_____//
 
int main()
{
    std::vector<int> arr;

    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(3);

    std::cout<<profit(arr)<<'\n';
 


return 0; 
}

