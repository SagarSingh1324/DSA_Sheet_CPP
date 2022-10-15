/*
 * =====================================================================================
 *
 *       Filename:  minimum_sideways_jumps.cpp
 *
 *    Description:  find minimum no. of sideways jumps a forg should make 
 *
 *        Version:  1.0
 *        Created:  10/10/22 12:27:04 AM IST
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

int minSideJumps(std::vector<int>& obstacles)  
{
    
    int current_lane = 2;
    int num_jumps = 0;
    
    for(int i=0; i<(obstacles.size()-1); i++)
    {
        if( ((i+1) < obstacles.size() ) && (obstacles[i+1] == current_lane))
        {
            int k = i;

            while( (k<obstacles.size()) && ( (obstacles[k] == 0) || (obstacles[k] == current_lane) ) )
            {
                k++;
            }
            
            if(k == obstacles.size() )
            {
                if( obstacles[i+1] == current_lane) 
                {
                    num_jumps++;

                    if(current_lane == 1)
                        current_lane = 2;
                    else if(current_lane == 2)
                        current_lane = 3;
                    else if(current_lane == 3)
                        current_lane = 1;
                }
                    
        
            }
            else if(obstacles[k] == 1 && current_lane == 2)
            {
                num_jumps++;
                current_lane = 3;
            }
            else if(obstacles[k] == 3 && current_lane == 2)
            {
                num_jumps++;
                current_lane = 1;
            }
            else if(obstacles[k] == 2 && current_lane == 1)
            {
                num_jumps++;
                current_lane = 3;
            }
            else if(obstacles[k] == 3 && current_lane == 1)
            {
                num_jumps++;
                current_lane = 2;
            }
            else if(obstacles[k] == 1 && current_lane == 3)
            {
                num_jumps++;
                current_lane = 2;
            }
            else if(obstacles[k] == 2 && current_lane == 3)
            {
                num_jumps++;
                current_lane = 1;
            }
            
        }
    }
    
    return num_jumps;
    
}
 
 
//______main__function_____//
 
int main()
{

std::vector<int> obstacles;

// [0,3,3,0,3,1,3,0,2,2,0]

obstacles.push_back(0);
obstacles.push_back(0);
obstacles.push_back(2);
obstacles.push_back(0);



std::cout<<minSideJumps(obstacles)<<std::endl;
 
return 0; 
}
