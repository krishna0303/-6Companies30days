// { Driver Code Starts
/*

Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

Example 1:

Input:
N = 4
A[] = {8,3,1,2}
Output: 29
Explanation: Above the configuration
possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 

this is tricky question watch this video to understand the concept:
https://www.youtube.com/watch?v=reayIgOJO0Y

*/
#include <bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}
// } Driver Code Ends

/*You are required to complete this method*/
int max_sum(int A[], int N)
{
    //Your code here
    int sum_val = 0;
    int curr_val = 0;
    for (int i = 0; i < N; i++)
    {
        sum_val += A[i];
        curr_val += (i * A[i]);
    }
    int maxm = curr_val;
    for (int i = 0; i < N; i++)
    {
        int next_val = curr_val - (sum_val - A[i]) + A[i] * (N - 1);
        curr_val = next_val;
        maxm = max(maxm, curr_val);
    }
    return maxm;
}