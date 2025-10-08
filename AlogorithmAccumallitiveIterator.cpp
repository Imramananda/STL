#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
 vector<int>v = {5,9,3,1,2,3,4};
 sort(v.begin(),v.end());
 for(int x:v)
 cout<<" sort "<<x<<" ";
 cout<<endl;
 auto it = find(v.begin(),v.end(),4);
 if(it!= v.end())
    cout<<"found : "<<*it<<endl;

int sum =accumulate(v.begin(),v.end(),0);
cout<<" Sum : "<<sum<<endl;
 return 0;

}