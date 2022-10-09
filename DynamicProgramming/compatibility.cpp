/*
 * =====================================================================================
 *
 *       Filename:  compatibility.cpp
 *
 *    Description:  calculate compatibiltiy score bit.ly/3VfqRcn 
 *
 *        Version:  1.0
 *        Created:  08/10/22 04:37:15 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/


// Input: students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
// Output: 8
// Explanation: We assign students to mentors in the following way:
// - student 0 to mentor 2 with a compatibility score of 3.
// - student 1 to mentor 0 with a compatibility score of 2.
// - student 2 to mentor 1 with a compatibility score of 3.
// The compatibility score sum is 3 + 2 + 3 = 8.

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
 
//_____secondary__functions______//



// function to find compatibiltiy of two vectors

int temp_comp_score(std::vector<int> student, std::vector<int> mentor)
{
    int temp_score =0;

    int st_len = student.size();
    int mt_len = mentor.size();

    if(st_len != mt_len)
    {
        return -1;
    }
    else if( st_len == 0)
    {
        return -1;
    }
    
    for (int i = 0; i < st_len; i++)
    {
        if( student[i] == mentor[i])
        {
            temp_score++;
        }
    }
    
    return temp_score;

}



// function to find max compatibiltiy of two matrices
 
int maxCompatibilitySum(std::vector<std::vector<int> > students, std::vector<std::vector<int> > mentors )
{
    int max_compatibility_score =0;

    int num_std = students.size();
    int num_mnt = mentors.size();

    int st_len = students[0].size();
    int mt_len = mentors[0].size();


    if(num_std != num_mnt || st_len != mt_len)
    {
        return -1;
    }
    else if(num_std == 0 || st_len == 0)
    {
        return -1;
    }

    std::vector<std::vector<int> > mat;

    std::vector<int> temp;

    for (int i = 0; i < num_std; i++)
    {
        for (int j = 0; j < num_std; j++)
        {
            temp.push_back(temp_comp_score(students[i], mentors[j]));
        }

        mat.push_back(temp);

        temp.clear();
    }
    


    std::vector<std::string> permutations;
    std::string initial_string = "";

    
    for (int i = 0; i < num_std; i++)
    {
        initial_string.append(std::to_string(i));
    }

    permutations.push_back(initial_string);

    std::string temp_string = initial_string;

    int fact_num_std =1;
    int k = num_std;

    while(k != 1)
    {
        fact_num_std = fact_num_std*k;
        k--;
    }

    for(int i=1; i<fact_num_std; i++)
    {
        std::next_permutation(temp_string.begin(), temp_string.end());
        permutations.push_back(temp_string);
    }
    
    
    std::vector<int> final_arr;
    int temp_sum =0;


    for (int i = 0; i < fact_num_std; i++)
    {
        std::string s = permutations[i];

        for (int j = 0; j < num_std; j++)
        {
            int k = s[j]-48;

            temp_sum = temp_sum + mat[j][k];
        }

        if(temp_sum > max_compatibility_score)
        {
            max_compatibility_score = temp_sum;
        }

        temp_sum =0;

    }
    

    return max_compatibility_score;

} 
 
//______main__function_____//
 
int main()
{
    std::vector<std::vector<int> > students;
    std::vector<std::vector<int> > mentors;

    students.push_back({1,1,0});
    students.push_back({1,0,1});
    students.push_back({0,0,1});

    mentors.push_back({1,0,0});
    mentors.push_back({0,0,1});
    mentors.push_back({1,1,0});

    int comp_score = maxCompatibilitySum(students, mentors);

    std::cout<<comp_score<<std::endl;

    //std::cout<<temp_comp_score(students[0], mentors[2])<<std::endl;
 
return 0; 
}