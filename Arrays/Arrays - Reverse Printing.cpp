#include<iostream>
using namespace std;

class array1
{
    int arr1[10];
    int n;
    int element;
public:
    array1()
    {
        cout<<"enter number of elements: ";
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cout << "Enter element: ";
            cin >> element;
            arr1[i] = element;
        }
    }

    void printreverse()
    {
        cout<<"\n"<<"reversed list: "<<"\n";
        for(int i = n - 1; i >= 0; i--)
        {
            cout << arr1[i] << "\t";
        }
    }

};

int main()
{
    array1 A;
    A.printreverse();
}
