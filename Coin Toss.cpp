#include <iostream>
#include <vector>
using namespace std;

void printTruthCombinations(int n)
{
    int totalCombinations = 1 << n;
    for (int i = 0; i < totalCombinations; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            bool value = (i & (1 << j)) != 0;
            cout << (value ? "true" : "false") << (j == 0 ? "" : ", ");
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of Boolean variables (n): ";
    cin >> n;

    if (n < 1)
    {
        cout << "Number of variables must be at least 1." << endl;
        return 0;
    }

    cout << "All possible combinations of truth values:" << endl;
    printTruthCombinations(n);

    return 0;
}
