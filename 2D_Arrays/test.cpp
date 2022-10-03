#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

// forgive me 
using namespace std;

//_____secondary__functions______//
 

 
 
//______main__function_____//
 
int main()
{
 

vector<pair<int,int> > alpha;

alpha.push_back({2,3});
alpha.push_back({6,7});
alpha.push_back({6,7});


// bool found = (find(alpha.begin(), alpha.end(), ({6,7})) != alpha.end());

// cout<<found<<endl;


int a;

if(alpha[0] == [2,3])
{
    a=1; 
}

cout<<a<<endl;

return 0; 
}