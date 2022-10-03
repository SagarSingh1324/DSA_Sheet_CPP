/*
 * =====================================================================================
 *
 *       Filename:  find_key_in_array.cpp
 *
 *    Description:  find a key in a 'sorted' and 'rotated' array with distinct values in log(n) time  
 *
 *        Version:  1.0
 *        Created:  29/09/22 09:21:37 AM IST
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

int  pivot = 0;
int final_pivot = 0;
int key_position = -1;
int final_key_position = -1;

//____finding pivot using binary search_________//

int pivot_finding(int *begin, int *end)
{
	if(final_pivot==0)
	{
	
		int mid = (end-begin)/(2);

		if((*begin)>(*(begin + 1)))
		{
			final_pivot = pivot+1;
			return pivot;
		}
		else if((begin == end))
		{
			pivot++;
			return 0;
		}
		else
			return ( pivot_finding(begin, begin + mid ) + pivot_finding(begin + mid + 1 ,end) );
	
	}
	else
	{
		return final_pivot;
	}
}		

////__________________finding key using binary search_________________//////
 
int key_finding(int *begin, int *end, int k)
{

if(final_key_position == -1)
{	
		int mid = (end-begin)/(2);

		if(begin != end)
		{
			return ( key_finding(begin, begin + mid , k) + key_finding(begin + mid + 1 , end, k ) );
			
		}
		else if(((begin == end) && (*begin != k)))
		{
			key_position++;
			return 0;
		}
		else if(((begin == end) && (*begin == k)))
		{
			final_key_position = key_position;
			return 0;
		}
	}	
	else 
	{
		return final_key_position;
	}
		
}		



//_________main_______// 

int main()
{
	std::vector<int> arr;
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(10);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);


	pivot_finding(&(*arr.begin()), &(*(arr.end()-1)));

	key_finding(&(*arr.begin()), &(*(arr.begin()+final_pivot-1)), 2);

	if(final_key_position == -1)
	{
		key_finding(&(*(arr.begin()+final_pivot)), &(*(arr.end()-1)), 2);	 
	}

	std::cout<<(final_key_position+2)<<"\n";

	return 0;
}
