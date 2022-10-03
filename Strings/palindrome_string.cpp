/*
 * =====================================================================================
 *
 *       Filename:  palindrome_string.cpp
 *
 *    Description:  find is a string is palindrome after removing spaces, non-alphanums, and coverting all to lowercase 
 *
 *        Version:  1.0
 *        Created:  30/09/22 05:29:42 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/

#include<iostream>
#include<vector>
#include<string>
 
//_____secondary__functions______//
 
bool isPalindrome(std::string s) 
{
std::vector<char> temp_string;

for (int i = 0; i < s.length(); i++)
{
    if(isalnum(s[i]))
    {
        if(isupper(s[i]))
        {
            temp_string.push_back(tolower(s[i]));
        }else
        {
            temp_string.push_back(s[i]);
        }
    }
}

int len = temp_string.size();
int flag =0;

for (int i = 0; i < len/2; i++)
{
    if(temp_string[i] != (char)temp_string[len-1-i])
    {
        flag++;
    }
}

if(flag == 0)
{
    return true;
}
else 
{
    return false;
}        
}
 
 
//______main__function_____//
 
int main()
{

std::string str;

getline(std::cin, str);

std::cout<<isPalindrome(str)<<std::endl;

return 0; 
}

