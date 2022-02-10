// C++ program to divide the array into two
// subarrays with the same sum on removing
// exactly one integer from the array
/*

Given an array of integers, find if it’s possible to remove exactly one integer from the array that divides
the array into two subarrays with the same sum.

*/
#include <iostream>
using namespace std;

// Utility function to print the sub-array
void printSubArray(int arr[], int start, int end)
{
    cout << "[ ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << "] ";
}

// Function that divides the array into two subarrays
// with the same sum
bool divideArray(int arr[], int n)
{
    // sum stores sum of all elements of the array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // sum stores sum till previous index of the array
    int sum_so_far = 0;

    for (int i = 0; i < n; i++)
    {
        // If on removing arr[i], we get equals left
        // and right half
        if (2 * sum_so_far + arr[i] == sum)
        {
            cout << "The array can be divided into two "
                    "subarrays with equal sum";
            return true;
        }
        // add current element to sum_so_far
        sum_so_far += arr[i];
    }

    // The array cannot be divided
    cout << "The array cannot be divided into two "
            "subarrays with equal sum";

    return false;
}

// Driver code
int main()
{
    int arr[] = {6, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    divideArray(arr, n);

    return 0;
}
