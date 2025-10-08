#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> m;
    m["Ram"]=30;
    m["aaru"]=27;
    for(auto& [key,value]:m)
    cout<<"name "<<key<<" age "<<value<<endl;
    return 0;
}