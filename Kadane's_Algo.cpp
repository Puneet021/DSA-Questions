// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which
// is a contiguous subarray.
// Example 2:

// Input:
// N = 4
// arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1
// of element (-1)

// Your Task:
// You don't need to read input or print anything. The task is to complete the function maxSubarraySum() which takes arr and N as input parameters and returns the sum of subarray with maximum sum.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// -107 ≤ A[i] ≤ 107

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solve
{
public:
    int kadane(vi &a, int n)
    {
        int c = a[0], res = a[0];
        for (int i = 0; i < n; i++)
        {
            c = max(c + a[i], a[i]);
            res = max(res, c);
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solve obj;
    int res = obj.kadane(a, n);
    cout << res;
    return 0;
}