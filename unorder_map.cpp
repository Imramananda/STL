#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int>m;
    m["Ram"]=30;
    m["aaru"]=27;
    for(auto& [key,value]:m)
    cout<<"Name "<<key <<" Age "<<value <<endl;
    cout<<endl;
    return 0;
}