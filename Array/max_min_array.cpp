/*
 * =====================================================================================
 *
 *       Filename:  max_min_array.cpp
 *
 *    Description: find the maximum and minimum value form an array with minimum no. of comparisons 
 *
 *        Version:  1.0
 *        Created:  28/09/22 10:31:33 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 * =====================================================================================
 */

#include<iostream>
#include<bits/stdc++.h>


struct max_min
{
	int max;
	int min;
}array_max_min;


max_min func(int arr[8])
{
	array_max_min.max = arr[0];
	array_max_min.min = arr[0];

	for(int i=1; i<8; i++)
	{
	if(arr[i] <= array_max_min.min)
		array_max_min.min = arr[i];
	else if(arr[i] >= array_max_min.max)
		array_max_min.max = arr[i];
	}

	return array_max_min;
}


int main()
{

int arr[] = {2,3,7,4,6,5,9,1};

array_max_min = func(arr);

std::cout<<"max value is: "<<array_max_min.max<<std::endl;

std::cout<<"min value is: "<<array_max_min.min<<std::endl;


return 0;	
}
