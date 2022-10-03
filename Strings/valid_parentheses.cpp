/*
 * =====================================================================================
 *
 *       Filename:  valid_parentheses.cpp
 *
 *    Description:  check if the given string of parentheses is correct (every opened bracket is closed) 
 *
 *        Version:  1.0
 *        Created:  30/09/22 05:59:45 PM IST
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
#include<stack>
 
//_____secondary__functions______//
 
bool isValidParentheses(std::string &str)
{
    std::stack<int> stk1;

    for (int i = 0; i < str.length(); i++)
    {
        if((char)str[i]=='(') 
        {
            stk1.push(1);
        }
        else if((char)str[i]=='[') 
        {
            stk1.push(2);
        }
        else if((char)str[i]=='{') 
        {
            stk1.push(3);
        }
        else if((char)str[i]=='}') 
        {
            if(!stk1.empty())
            {
                if(stk1.top() == 3)
                {
                    stk1.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if((char)str[i]==']') 
        {
            if(!stk1.empty())
            {
                if(stk1.top() == 2)
                {
                    stk1.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;;
            }
        }
        else if((char)str[i]==')') 
        {
            if(!stk1.empty())
            {
                if(stk1.top() == 1)
                {
                    stk1.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if(stk1.empty())
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
 
std::string input_str;

getline(std::cin, input_str);

std::cout<<isValidParentheses(input_str)<<std::endl;

return 0; 
}

