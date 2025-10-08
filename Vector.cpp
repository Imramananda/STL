#include<iostream>
#include<vector>
using namespace std;
int main()
{

    vector<int> v= {1,2,3,4};
    v.push_back(10);
    for(int i : v)
    {
        cout<<"Elemtn- "<<i<<",";
    }
    cout<<endl;
    return 0;
}