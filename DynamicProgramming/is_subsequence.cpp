/*
 * =====================================================================================
 *
 *       Filename:  is_subsequence.cpp
 *
 *    Description:  find if secondstring is a subsequence of first or not 
 *
 *        Version:  1.0
 *        Created:  06/10/22 09:11:48 PM IST
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
 

int is_substring(std::string s, std::string t)
{
    
    int lens = s.length();
    int lent = t.length();
    
    int index_t =0;
    
    if(lens > lent)
    {
        return false;
    }
    
    if(lens == 0)
    {
        return true;
    }
    
    
    for(int i=0; i<lens; i++)
    {
        int j=index_t; 
        
        while(s[i] != t[j] && j<lent)
        {
                j++;
        }
        
        
        if(j == lent)
        {
            return false;
        }
        
        if(s[i] == t[j])
        {
            index_t = j;
        }
        
        index_t++;
        
        if(i == (lens-1))
        {
            return true;
        }
        
    }
    
    return false;
    
}
 
 
//______main__function_____//
 
int main()
{

std::string s;
std::string t;

s = "ab";
t = "ahbgdc";

std::cout<<is_substring(s,t)<<std::endl;

return 0; 
}

