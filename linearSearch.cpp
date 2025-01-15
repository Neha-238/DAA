#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    int comparisons = 0;
    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == key)
        {
            cout << "Total comparisons: " << comparisons << endl;
            return i; // Return the index of the key if found
        }
    }
    cout << "Total comparisons: " << comparisons << endl;
    return -1; // Return -1 if key is not found
}

int main()
{
    // Example array and key to search for
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int key = 30;                         // Key to search for

    int result = linearSearch(arr, n, key);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
