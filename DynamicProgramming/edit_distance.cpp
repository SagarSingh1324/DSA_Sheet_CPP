/*
 * =====================================================================================
 *
 *       Filename:  edit_distance.cpp
 *
 *    Description:  calculate the minimum no. of operations required to convert one string to another 
 *
 *        Version:  1.0
 *        Created:  08/10/22 12:04:11 AM IST
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
 
//_____secondary__functions______//


// to find at what index should the string 's' should be placed wrt 't' so that no. of letter matches can be maximized

int best_position(std::string s, std::string t)
{
    int pos_index_s_wrt_t =0;                      // position of first letter of strign 's' with respect to 't'  

    int max_matches =0;

    int lens = s.length();
    int lent = t.length();

    for (int i = 0; i < (lens+lent-1); i++)
    {   
        int temp =0;

        for (int j = 0; j <= i; j++)
        {
            if( t[j] == s[ (lens-1) - j] )
            {
                temp++;
            }
        }

        if( temp > max_matches)
        {
            max_matches = temp;
        }

        temp =0;
        
    }

    return max_matches;
    
}

// function to find the minimum edit distance
 
int edit_distance(std::string s, std::string t)
{
    int min_edit_distance =0;

    int nof_letters_needed =0;
    int nof_letters_deleted =0;

    int lens = s.length();
    int lent = t.length();


    // logic to find the no. bits needed to be added or deleted

    if( lent > lens ) 
    {
        nof_letters_needed = lent-lens;
    }
    else if( lens > lent )
    {
        nof_letters_deleted = lent-lens;
    }
    else if( lens == lent )
    {
        nof_letters_needed = 0;
        nof_letters_deleted = 0;
    }
    else 
    {
        return -1;
    }











    return min_edit_distance;

}
 
 
//______main__function_____//
 
int main()
{

std::string s;
std::string t;

s = "gee";
t = "gesek";

// std::cout<<edit_distance(s,t)<<std::endl;

std::cout<<best_position(s,t)<<std::endl;
 
return 0; 
}
