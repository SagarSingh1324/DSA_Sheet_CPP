/*
 * =====================================================================================
 *
 *       Filename:  min_range_subset.cpp
 *
 *    Description: Find the subset with given no. of elements having minimum range 
 *
 *        Version:  1.0
 *        Created:  29/09/22 12:20:54 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<bits/stdc++.h>

int min;

int func(std::vector<int> arr, int m){
	std::sort(arr.begin(), arr.end());
	int window = arr.size()-m+1;
	min = arr[m-1]-arr[0];
	for(int i=1; i<window; i++)
	{
		if((arr[i+m-1]-arr[i]) <= min)
			min = arr[i+m-1]-arr[i];
	}
	return min;
}

int main()
{
	std::vector<int> arr;
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(9);
	arr.push_back(56);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(12);

	min = func(arr, 5);

	std::cout<<min<<std::endl;
	return 0;
}
