// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Example 1:

// Input:
// n = 4, arr1[] = [1 3 5 7]
// m = 5, arr2[] = [0 2 6 8 9]
// Output:
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two
// non-decreasing arrays, we get,
// 0 1 2 3 5 6 7 8 9.
// Example 2:

// Input:
// n = 2, arr1[] = [10, 12]
// m = 3, arr2[] = [5 18 20]
// Output:
// arr1[] = [5 10]
// arr2[] = [12 18 20]
// Explanation:
// After merging two sorted arrays
// we get 5 10 12 18 20.

// Your Task:
// You don't need to read input or print anything. You only need to complete the function merge() that takes arr1, arr2, n and m as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.

// Expected Time Complexity:  O((n+m) log(n+m))
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= n, m <= 5*104
// 0 <= arr1i, arr2i <= 107

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

class Solve
{
public:
    int nextGap(int x)
    {
        if (x <= 1)
            return 0;
        return (x / 2) + (x % 2);
    }

    void Merge(vi &a1, vi &a2, int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            // traversing first array
            for (i = 0; i + gap < n; i++)
            {
                if (a1[i] > a1[i + gap])
                    swap(a1[i], a1[i + gap]);
            }

            for (j = gap > n ? gap - n : 0; j < m && i < n; i++, j++)
            {
                if (a1[i] > a2[j])
                    swap(a1[i], a2[j]);
            }

            for (j = 0; j + gap < m; j++)
            {
                if (a2[j] > a2[j + gap])
                    swap(a2[j], a2[j + gap]);
            }
        }
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    vi a1(n), a2(m);
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < m; i++)
        cin >> a2[i];
    Solve obj;
    obj.Merge(a1, a2, n, m);
    for (int i = 0; i < n; i++)
        cout << a1[i] << " ";
    cout << endl;
    for (int i = 0; i < m; i++)
        cout << a2[i] << " ";
    return 0;
}