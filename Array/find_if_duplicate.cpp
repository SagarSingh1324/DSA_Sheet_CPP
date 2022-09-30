/*
 * =====================================================================================
 *
 *       Filename:  find_if_duplicate.cpp
 *
 *    Description:  find if array has a duplicate entry of size n with all entries <= n
 *
 *        Version:  1.0
 *        Created:  29/09/22 02:34:11 PM IST
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
 
//_____secondary__functions______//

int duplicate(std::vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[abs(arr[i])] < (int)arr.size())
        {
            if(arr[abs(arr[i])]>0)
            {
                arr[abs(arr[i])] = -1*arr[abs(arr[i])];
            }
            else if(arr[abs(arr[i])] < 0)
            {
                return abs(arr[i]);
            }
        }    
    }

    return -1;
}
 
 
//______main__function_____//
 
int main()
{

std::vector<int> arr;

arr.push_back(1);
arr.push_back(2);
arr.push_back(3);
arr.push_back(4);
arr.push_back(5);
arr.push_back(6);
arr.push_back(7);
arr.push_back(8);
arr.push_back(3);

std::cout<<"duplicate value is: "<<duplicate(arr)<<'\n';

return 0; 
}
