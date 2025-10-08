#include <iostream>
using namespace std;
// generic
template <typename T>
class vectorClass
{
    T *arr;
    int capacity;
    int current;

public:
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    ~vectorClass()
    {
        delete[] arr;
    }
    // push the element at last
    void push(T data)
    {
        if (capacity == current) // double the capacity
        {
            T *tmep = new T[2 * capacity];
            for (int i=0; i < capacity; i++)
                tmep[i] = arr[i];
            delete[] arr;
            capacity = capacity * 2;
            arr = tmep;
        }
        arr[current] = data;
        current++;
    }
    // push to perticuler index
    void push(T data, int index)
    {
        if (index = capacity)
            push(data);
        else
            arr[index] = data;
    }
    void pop(T data)
    {
        current--;
    }
    int getSize()
    {
        return current;
    }
    int getCapacity()
    {
        return capacity;
    }
    void print()
    {
        for(int i=0;i<current;i++)
        {
        cout<<arr[i]<<" ," ;
        }
        cout<<endl;
    }
    T get(int index)
    {
        if(index<current)
        {
            cout<<"At index "<<index <<" : "<<arr[index]<<endl;
        }
    return -1;
    }
};

int main()
{
    vectorClass<int> objInt;
    vectorClass<char> objChar;
    objInt.push(55);
    objInt.push(50);
    objInt.push(510);
    objInt.get(2);
    cout<<objInt.getSize()<< " Size "<<endl;
    objInt.print();

    // Test character vector
    objChar.push('A');
    objChar.push('B');
    objChar.push('C');
    objChar.print(); // Output: A B C
    return 0;
}