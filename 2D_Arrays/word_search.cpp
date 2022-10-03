/*
 * =====================================================================================
 *
 *       Filename:  word_search.cpp
 *
 *    Description:  search for a given word in a matrix (puzzle solver) 
 *
 *        Version:  1.0
 *        Created:  03/10/22 06:51:12 PM IST
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
#include<algorithm>
#include<set>
#include<queue>

//_____secondary__functions______//

int hash(int x, int y)
{
    int n = ((x + y)*(x + y + 1)/2) + y;
    return n;
}
 
bool find_word(std::vector<std::vector<char> > board, std::string word)
{

    int row_num = board.size();
    int col_num = board[0].size();

    int word_index = 0;
    int word_length = word.length();
    char lookup_letter = word[0];

    int letters_found =0;
    std::vector<int> visited;


    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            if( board[i][j] == lookup_letter)
            {
                int i_temp = i;
                int j_temp = j;

                // found the first letter

                if(word.length() == 1)
                {
                    return 1;
                }
            
                letters_found++;
                word_index++;
                lookup_letter = word[word_index];

                visited.push_back(hash(i_temp,j_temp));


                while(letters_found <= word.length())
                {

                    if((j_temp+1 < col_num) && (board[i_temp][j_temp+1] == lookup_letter) && !(std::find(visited.begin(), visited.end(), hash(i_temp,j_temp+1)) != visited.end()))                                    // check right
                    {
                        j_temp++;
                        word_index++;
                        lookup_letter = word[word_index];
                        letters_found++;
                        visited.push_back(hash(i_temp,j_temp));
                    } 
                    else if((i_temp+1 < row_num) && (board[i_temp+1][j_temp] == lookup_letter) && !(std::find(visited.begin(), visited.end(), hash(i_temp+1,j_temp)) != visited.end()) )                                     // check below
                    {
                        i_temp++;
                        word_index++;
                        lookup_letter = word[word_index];
                        letters_found++;
                        visited.push_back(hash(i_temp,j_temp));
                    }
                    else if((j_temp-1 > -1) && (board[i_temp][j_temp-1] == lookup_letter) && !(std::find(visited.begin(), visited.end(), hash(i_temp,j_temp-1)) != visited.end()) )                                          // check left
                    {
                        j_temp--;
                        word_index++;
                        lookup_letter = word[word_index];
                        letters_found++;
                        visited.push_back(hash(i_temp,j_temp));
                    }
                    else if((i_temp-1 > -1) && (board[i_temp-1][j_temp] == lookup_letter) && !(std::find(visited.begin(), visited.end(), hash(i_temp-1,j_temp)) != visited.end()) )                                          // check top
                    {
                        i_temp--;
                        word_index++;
                        lookup_letter = word[word_index];
                        letters_found++;
                        visited.push_back(hash(i_temp,j_temp));
                    }
                    else 
                    {
                        letters_found = word.length() + 1;
                    }

                    if(letters_found == word.length())
                    {
                        return true;
                    }
                }

                // 'this' first letter didn't lead to the word
                
                word_index =0;
                letters_found = 0;
                lookup_letter = word[word_index];   
                lookup_letter = word[0];

                visited.clear();
            }    
        }
    }   

    return false;
           
}
 
 
//______main__function_____//
 
int main()
{

// board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"

std::vector<std::vector<char> > board;

board.push_back({'C','A','A'});
board.push_back({'A','A','A'});
board.push_back({'B','C','D'});

std::string word = "AAB";

std::cout<<find_word(board, word)<<std::endl;


return 0; 
}
