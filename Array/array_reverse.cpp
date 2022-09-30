/*
 * =====================================================================================
 *
 *       Filename:  array_reverse.cpp
 *
 *    Description:  reverse an array/string 
 *
 *        Version:  1.0
 *        Created:  28/09/22 11:02:30 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 * =====================================================================================
 */

#include<iostream>
#include<bits/stdc++.h>

// funtion array reverse

int arr2[7];

int* func(int arr[7])
{

	for(int i=0; i<7; i++)
		arr2[i] = arr[6-i];

	return arr2;
}

int main()
{

	int arr[7] = {3,7,5,1,6,3,9};

	int *arr2 = func(arr);

	std::cout<<arr2[0]<<arr2[1]<<arr2[2]<<arr2[3]<<arr2[4]<<arr2[5]<<arr2[6]<<std::endl;


	return 0;
}









