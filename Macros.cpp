#include<iostream>
#define ADD(x,y) x+y
#define MUL(a,b) a*b
using namespace std;
int main()
{
    cout<<"Rama "<<MUL(ADD(1,2),ADD(3,4))<<endl;
    // 1+2*3+4
    return 0;
}