//   Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example 1:

// Input:
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.
// Example 2:

// Input:
// N = 3
// arr[] = {0 1 0}
// Output:
// 0 0 1
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 10^6
// 0 <= A[i] <= 2

#include <bits/stdc++.h>
using namespace std;

class Sort
{
public:
    void sort012(int a[], int n)
    {
        int i = 0, j = 0, k = n - 1;
        while (i <= k)
        {
            switch (a[i])
            {
            // if the element is 0.
            case 0:
                swap(a[i++], a[j++]);
                break;

            // if the element is 1.
            case 1:
                i++;
                break;

            // if the element is 2.
            case 2:
                swap(a[i], a[k--]);
                break;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Sort obj;
    obj.sort012(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}