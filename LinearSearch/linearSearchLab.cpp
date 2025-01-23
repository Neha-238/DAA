#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

int linearSearch(const vector<int> &arr, int key, int &comparisons)
{
    comparisons = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        comparisons++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int generateRandomNumber(int maxValue)
{
    return rand() % maxValue + 1;
}

int main()
{
    srand(time(0)); // Seed for random number generation

    ofstream file("linear_search_cases.csv");

    file << "Array Size, Best Case, Average Case, Worst Case\n";

    for (int n = 10; n <= 100; n += 5)
    {
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = generateRandomNumber(100);
        }

        // Best Case: The target is the first element
        int target = arr[0];
        int comparisons = 0;
        linearSearch(arr, target, comparisons);
        int bestCase = comparisons;

        // worst case
        target = arr[n - 1];
        comparisons = 0;
        linearSearch(arr, target, comparisons);
        int worstCaseLastElement = comparisons;

        target = 101;
        comparisons = 0;
        linearSearch(arr, target, comparisons);
        int worstCaseNonExistent = comparisons;

        int worstCase = max(worstCaseLastElement, worstCaseNonExistent);

        // average case
        int totalComparisons = 0;
        for (int i = 0; i < n; i++)
        {
            comparisons = 0;
            linearSearch(arr, arr[i], comparisons);
            totalComparisons += comparisons;
        }
        int averageCase = totalComparisons / n;

        file << n << "," << bestCase << "," << averageCase << "," << worstCase << "\n";
    }

    file.close();

    cout << "Data has been written to linear_search_cases.csv\n";

    return 0;
}
