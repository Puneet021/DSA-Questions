// Consider a big party where N guests came to it and a log register for guest’s entry and exit times was maintained.
// Find the minimum time at which there were maximum guests at the party. Note that entries in the register are not
// in any order.

// Example 1:

// Input:
// N = 5
// Entry= {1, 2,10, 5, 5}
// Exit = {4, 5, 12, 9, 12}
// Output: 3 5
// Explanation: At time 5 there were
//              guest number 2, 4 and 5 present.
// Example 2:

// Input:
// N = 7
// Entry= {13, 28, 29, 14, 40, 17, 3}
// Exit = {107, 95, 111, 105, 70, 127, 74}
// Output: 7 40
// Explanation: At time 40 there were
//              all 7 guests present in the party.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMaxGuests() which takes 3 arguments(Entry array, Exit array, N) and returns the maximum number of guests present at a particular time and that time as a pair.

// Expected Time Complexity: O(N*Log(N) ).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 105
// 1 <= Entry[i],Exit[i] <= 105

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

class Solve
{
public:
    vector<int> Merge(vi &a1, vi &a2, int n)
    {
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        int i = 0, j = 0, count = 0, maxCount = 0, time = 0;
        while (i < n)
        {
            while (a2[j] < a1[i])
            {
                j++;
                count--;
            }
            count++;
            if (count > maxCount)
            {
                maxCount = count;
                time = a1[i];
            }
            i++;
        }
        return vector<int>{maxCount, time};
    }
};

int main()
{
    ll n;
    cin >> n;
    vi a1(n), a2(n);
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < n; i++)
        cin >> a2[i];
    Solve obj;
    vector<int> res = obj.Merge(a1, a2, n);
    cout << res[0] << " " << res[1];
    return 0;
}