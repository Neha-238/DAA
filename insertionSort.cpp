// ******Implement Insertion Sort***********
// 1) I Count the number of key comparisons and assignments for
//    various inputs and plot the graph for both of them.
// 2) For every input size n , run it with 10 different data points
//    generated randomly.
// 3) Compute the minimum, maximum and average of the number
//   of key comparisons (and assignments) for each input size.
// 4) I Plot the graph for each case - best, worst and average      number of comparisons (and assignments) .
//  n varies from 10 to 100 in steps of 5.

#include <iostream>
#include <ctime>
using namespace std;

// void insertionSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {

//         int curr = arr[i];
//         int prev = i - 1;

//         while (prev >= 0 && arr[prev] > curr)
//         {
//             arr[prev + 1] = arr[prev];
//             prev--;
//         }

//         arr[prev + 1] = curr;
//     }
// }

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &assignments)
{
    comparisons = 0;
    assignments = 0;

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        assignments++; // Assignment for 'curr'

        while (prev >= 0)
        {
            comparisons++; // Comparison in the while loop condition
            if (arr[prev] > curr)
            {
                arr[prev + 1] = arr[prev];
                assignments++; // Assignment during shifting
                prev--;
            }
            else
            {
                break;
            }
        }

        arr[prev + 1] = curr;
        assignments++; // Final assignment for placing 'curr'
    }
}

// Generate random array
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 101; // Random numbers between 0 and 100
    }
}

// Main function
int main()
{
    srand(time(0)); // Seed random number generator

    ofstream csvFile("insertion_sort.csv");
    csvFile << "n,Best Comparisons,Best Assignments,Worst Comparisons,Worst Assignments,Average Comparisons,Average Assignments\n";

    for (int n = 10; n <= 100; n += 5)
    {
        int bestComparisons = 0, bestAssignments = 0;
        int worstComparisons = 0, worstAssignments = 0;
        int totalComparisons = 0, totalAssignments = 0;

        int *arr = new int[n];

        // Best case: Sorted array
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }

        insertionSort(arr, n, bestComparisons, bestAssignments);

        // Worst case: Reverse-sorted array
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }

        insertionSort(arr, n, worstComparisons, worstAssignments);

        // Average case: 10 random arrays
        for (int trial = 0; trial < 10; trial++)
        {
            generateRandomArray(arr, n);
            int trialComparisons = 0, trialAssignments = 0;
            insertionSort(arr, n, trialComparisons, trialAssignments);
            totalComparisons += trialComparisons;
            totalAssignments += trialAssignments;
        }
        int avgComparisons = totalComparisons / 10;
        int avgAssignments = totalAssignments / 10;

        // Write results to CSV
        csvFile << n << "," << bestComparisons << "," << bestAssignments << ","
                << worstComparisons << "," << worstAssignments << ","
                << avgComparisons << "," << avgAssignments << "\n";

        delete[] arr; // Clean up dynamic memory
    }

    csvFile.close();

    return 0;
}
