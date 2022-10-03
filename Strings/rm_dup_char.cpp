/*
 * =====================================================================================
 *
 *       Filename:  rm_dup_char.cpp
 *
 *    Description:  from a given string of lowercase characters, remove all duplicates/repeated 
 *
 *        Version:  1.0
 *        Created:  30/09/22 07:47:09 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/

#include<iostream>
#include<string>
 
//_____secondary__functions______//
 
std::string func(std::string str2)
{
    for (int i = 1; i < str2.length(); i++)
    {
        if(str2[i] == str2[i-1])
        {
            str2.erase(str2.begin()+i);
            i = i-1;
        }
    }
    return str2;
}
 
 
//______main__function_____//
 
int main()
{
 
std::string str;

getline(std::cin, str);

std::string str2 = func(str);

std::cout<<str2<<std::endl;

return 0; 
}
