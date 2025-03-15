#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
           cout << "Element found at position: " << i << endl;
        }
    }
    cout << "Element not found in the array." << endl;
}

int main()
{
    int n, x;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> x;

    linearSearch(arr, n, x);

    return 0;
}
