#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int>s={3,2,4,1,5,3};
    for(int x:s)
    cout<<"elemt"<<x<<",";
    cout<<endl;
    cout<<"sizeof "<<s.size()<<endl;
    return 0;
}