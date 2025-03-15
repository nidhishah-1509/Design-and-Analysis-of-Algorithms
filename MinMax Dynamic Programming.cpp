#include<iostream>
using namespace std;

void minmax_dp(int arr[], int n)
{
    int min_val = arr[0];
    int max_val = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }

    for(int j = 0; j < n; j++)
    {
        if(arr[j] > max_val)
        {
            max_val = arr[j];
        }
    }

    cout<<"maximum value: "<<max_val<<endl;
    cout<<"minimum value: "<<min_val;
}

int main()
{
    cout<<"enter an array of 10 elements: "<<endl;
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    int n = sizeof(arr)/sizeof(arr[0]);

    minmax_dp(arr, n);
}
