/*
 * =====================================================================================
 *
 *       Filename:  kth_largest_element.cpp
 *
 *    Description:  find the kth largest element in an array in linear time 
 *
 *        Version:  1.0
 *        Created:  29/09/22 05:57:26 PM IST
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
 
int kth_element=0; 
//_____secondary__functions______//
 
void func(std::vector<int> &arr, int k)
{

    std::priority_queue<int> temp;

    for(int i=0; i<arr.size(); i++)
    {
        temp.push(-1*arr[i]);
    }

    for(int j=0; j<(arr.size()-k); j++)
    {
        temp.pop();
    }

    kth_element = -1*temp.top();
 
} 
 
//______main__function_____//
 
int main()
{
    std::vector<int> arr;

    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(6);

    func(arr, 4);

    std::cout<<kth_element<<std::endl;
 
return 0; 
}

