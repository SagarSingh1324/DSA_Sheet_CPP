/*
 * =====================================================================================
 *
 *       Filename:  anagram_string.cpp
 *
 *    Description:  test if two strings are anagrams of each other 
 *		    
 *        Version:  1.0
 *        Created:  30/09/22 05:34:40 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *           
 *           Note:  same method can with used for Problem no. 35 with minor modifications
 *
 * =====================================================================================
*/

// Input: s = "anagram", t = "nagaram"
// Output: true

#include<iostream>
#include<vector>
#include<array>
 
//_____secondary__functions______//
 
bool isAnagram(std::string &str1, std::string &str2)
{
    std::array<int, 26> vct1 ={0};
    std::array<int, 26> vct2 ={0};

    for (int i = 0; i < str1.length(); i++)
    {
        vct1[(char)str1[i]-97]++;
    }
    
    for (int i = 0; i < str2.length(); i++)
    {
        vct2[(char)str2[i]-97]++;
    }

    if(vct1 == vct2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
 
//______main__function_____//
 
int main()
{

std::string str1;
std::string str2;

getline(std::cin, str1);
getline(std::cin, str2);

std::cout<<isAnagram(str1,str2)<<std::endl;
 
return 0; 
}

