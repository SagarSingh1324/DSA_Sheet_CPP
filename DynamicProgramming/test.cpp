#include<iostream>
#include<vector>
#include<algorithm>
 
//_____secondary__functions______//
 
bool isSortedNonDecreasing(int* begin, int* end)
{
    bool temp = std::is_sorted(begin, end);
    return temp;
}

bool isSortedNonIncreasing(int* begin, int* end)
{
    int *ptr = begin;

    while(ptr != end)
    {
        if(*(ptr+1) > *ptr)
        {
            return false;
        }

        ptr++;
    }

    return true;
}

std::vector<int> goodDaysToRobBank(std::vector<int>& security, int time) 
{
    std::vector<int> result;

    if(time == 0)
    {
        for (int i = 0; i < security.size(); i++)
        {
            result.push_back(i);
        }

        return result;
        
    }
    
    if(time >= security.size())
    {
        return result;
    }

    
    for(int i = time; i<(security.size()-time); i++)
    {
        if( isSortedNonIncreasing( &security[i-time], &security[i] ) && isSortedNonDecreasing( &security[i], &security[i+time+1] ) )
        {
            result.push_back(i);
        }
    }
            
    return result;
    
}
 
//______main__function_____//
 
int main()
{

// Input: security = [5,3,3,3,5,6,2], time = 2
// Output: [2,3]

std::vector<int> security;

// [1,2,5,4,1,0,2,4,5,3,1,2,4,3,2,4,8]



security.push_back(1);
security.push_back(2);
security.push_back(5);
security.push_back(4);
security.push_back(1);
security.push_back(0);
security.push_back(2);
security.push_back(4);
security.push_back(5);
security.push_back(3);
security.push_back(1);
security.push_back(2);
security.push_back(4);
security.push_back(3);
security.push_back(2);
security.push_back(4);
security.push_back(8);
// security.push_back(6);
// security.push_back(2);

std::vector<int> result = goodDaysToRobBank(security, 2);

std::cout<<result[2]<<std::endl;

 return 0; 
}