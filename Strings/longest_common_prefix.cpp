/*
 * =====================================================================================
 *
 *       Filename:  longest_common_prefix.cpp
 *
 *    Description:  given a set of strings, find the longest common prefix among them 
 *
 *        Version:  1.0
 *        Created:  30/09/22 08:09:03 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 * 
 *           Note:  Input format should be: //  ["sagar","sangh","samay"]
 *
 * =====================================================================================
*/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
 
//_____secondary__functions______//
 
std::string lcp(std::string str1, std::string str2)
{
    std::string temp_str;

    int len;

    if(str1.length() <= str2.length())
    {
        len = str1.length();
    }
    else
    {
        len = str2.length();
    }

    if(str1[0]!=str2[0])
    {
        return " ";
    }

    for (int i = 0; i < len; i++)
    {
        if(str1[i] == str2[i])
        {
            temp_str.push_back(str1[i]);
        }
        else
        {
            return temp_str;
        }
    }

    return temp_str;
}
 
std::string lcp_strings(std::vector<std::string> vect)
{
    std::string final_str;

    final_str = lcp(vect[0], vect[1]);

    for (int i = 2; i < vect.size(); i++)
    {
        final_str = lcp(vect[i], final_str);
    }

    return final_str;
}

 
//______main__function_____//

int main()
{
 
std::string input_str;

getline(std::cin, input_str);

std::stringstream ss(input_str);

std::vector<std::string> result;

while( ss.good() )
{
    std::string substr;
    getline( ss, substr, ',' );
    result.push_back(substr);
}

int len = result.size();

result[0].erase(result[0].begin());
result[0].erase(result[0].begin());
result[0].erase(result[0].end()-1);

result[len-1].erase(result[len-1].begin());
result[len-1].erase(result[len-1].end()-1);
result[len-1].erase(result[len-1].end()-1);

for (int i = 1; i < len-1; i++)
{
    result[i].erase(result[i].begin());
    result[i].erase(result[i].end()-1);
}

std::string res_str = lcp_strings(result);

std::cout<<res_str<<std::endl;

return 0; 
}
