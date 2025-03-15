#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class array1
{
    int arr1[10];
    int n = 0;
    int sum = 0;
    int element;
public:
    array1()
    {
        cout<<"enter number of elements: ";
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cout<<"Enter element: ";
            cin>>element;
            arr1[i] = element;
        }
    }

    void addelements()
    {
        cout<<"\n"<<"sum of elements: "<<"\n";
        for(int i = 0; i < n; i++)
        {
            sum += arr1[i];
        }
        cout<<sum;
    }

};

int main()
{
    array1 A;
    A.addelements();
}
