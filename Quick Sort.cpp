#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition_array(int arr[], int low, int high)
{
    int pivot = arr[low];  //Pivot is the first element
    int i = low, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (i <= high && arr[i] < pivot);

        do
        {
            j--;
        } while (j >= low && arr[j] > pivot);

        if (i >= j)
        {
            swap(arr[low], arr[j]);
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition_array(arr, low, high);
        quicksort(arr, low, p - 1);  // Sort left partition
        quicksort(arr, p + 1, high); // Sort right partition
    }
}

int main()
{
    int n = 10;
    cout<<"Enter 10 elements: "<<endl;
    int arr[10];
    for (int k = 0; k < n; k++)
    {
        cin>>arr[k];
    }

    quicksort(arr, 0, n - 1);

    cout<<"Sorted array: ";
    for (int k = 0; k < n; k++)
    {
        cout<<arr[k]<<"  ";
    }
    return 0;
}
