#include<iostream>
using namespace std;

class array1
{
    int arr1[10];
    int element;
public:
    array1()
    {
        for(int i = 0; i < 10; i++)
        {
            cout << "Enter element to add in array: ";
            cin >> element;
            arr1[i] = element;
        }
    }

    void printarray()
    {
        cout<<"array: "<<"\n";
        for(int i = 0; i < 10; i++)
        {
            cout << arr1[i] << "\t";
        }
    }
};

int main()
{
    array1 A;
    A.printarray();
}
