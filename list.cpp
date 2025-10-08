#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> l = {1, 2, 3};
    l.push_back(4);
    for (int x : l) cout << x << " "; // Output: 1 2 3 4
    cout<<endl;
    cout<<"size "<<l.size()<<endl;
    return 0;
}