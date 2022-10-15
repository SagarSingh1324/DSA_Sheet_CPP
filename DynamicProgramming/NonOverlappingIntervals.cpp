/*
 * =====================================================================================
 *
 *       Filename:  NonOverlappingIntervals.cpp
 *
 *    Description:  Given an array of intervals intervals where intervals[i] = [starti, endi], 
 *                  return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 *
 *        Version:  1.0
 *        Created:  09/10/22 11:18:44 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
*/

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
 
//_____secondary__functions______//
 
int eraseOverlapIntervals(std::vector<std::vector<int> > &intervals)
{
    std::map<int, int> intervals_mapping;

    for (int i = 0; i < intervals.size(); i++)
    {
        
        for (int j = intervals[i][0]; j < intervals[i][1]; j++)
        {
            if( intervals_mapping.find(j) == intervals_mapping.end() )
            {
                intervals_mapping[j] = 1;
            }
            else if( intervals_mapping.find(j) != intervals_mapping.end() )
            {
                intervals_mapping[j]++;
            }
        }

    }

    std::map<int,int>::iterator best;

    best = std::max_element(intervals_mapping.begin(),intervals_mapping.end(),[] (const std::pair<int,int>& a, const std::pair<int,int>& b)->bool{ return a.second < b.second; } );
    
    return best->second;
    
}
 
 
//______main__function_____//
 
int main()
{

std::vector<std::vector<int> > intervals;

intervals.push_back({1,2});
intervals.push_back({2,3});
intervals.push_back({3,4});
intervals.push_back({1,3});

std::cout<<eraseOverlapIntervals(intervals)<<std::endl;
 
return 0; 
}