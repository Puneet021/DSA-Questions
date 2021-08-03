// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

// Example :
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// For N = 3, return 3rd row i.e 1 2 1

// Example 1:

// Input:
// N = 4
// Output: 1 3 3 1
// Explanation: 4th row of pascal's triangle
// is 1 3 3 1.
// Example 2:

// Input:
// N = 5
// Output: 1 4 6 4 1
// Explanation: 5th row of pascal's triangle
// is 1 4 6 4 1.

// Your Task:
// Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. The elements can be large so return it modulo 109 + 7. You don't to print answer or take inputs.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 1000

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solve
{
public:
    vector<ll> pascalT(int n)
    {
        vector<ll> res(n);
        res[0] = 1;
        for (int i = 1; i < (n + 1) / 2; i++)
        {
            ll ans = 1;
            for (int j = 0; j < i; j++)
            {
                ans *= (n - 1 - j);
                ans /= (j + 1);
            }
            res[i] = res[n - 1 - i] = ans;
        }
        res[n - 1] = 1;
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> res;
    Solve obj;
    res = obj.pascalT(n);
    for (ll i : res)
    {
        cout << i << " ";
    }
    return 0;
}