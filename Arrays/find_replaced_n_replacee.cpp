/*
 * =====================================================================================
 *
 *       Filename:  find_replaced_n_replacee.cpp
 *
 *    Description:  array contains integers from 1 to n, but k replaces l. find who replaces whom. 
 *
 *        Version:  1.0
 *        Created:  29/09/22 02:35:18 PM IST
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

struct pair
{
    double replaced;
    double replacee;
}pair1;

//_____secondary__functions______//
 
void func(std::vector<int> &arr)
{

double sum =0, sigma = 0, prod=1, fact=1;

for(int i=0; i<arr.size(); i++)
{
    sum = sum +arr[i];
    sigma = sigma + (i+1);

    prod = prod*arr[i];
    fact = fact*(i+1);

}

double A = sum-sigma;
double B = fact/prod;

pair1.replaced = (A*B)/(1.0-B);
pair1.replacee = (A)/(1.0-B);

}
 
 
//______main__function_____//
 
int main()
{
 
std::vector<int> arr;

// replaced: 9, replacee: 1

arr.push_back(1);
arr.push_back(2);
arr.push_back(3);
arr.push_back(3);
arr.push_back(4);
arr.push_back(9);
arr.push_back(6);
arr.push_back(7);
arr.push_back(8);

func(arr);

std::cout<<"replaced: "<<pair1.replaced<<'\n'<<"replacee: "<<pair1.replacee<<'\n';


return 0; 
}
