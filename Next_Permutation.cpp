// Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation
//  of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e.
// sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

// Example 1:

// Input: N = 6
// arr = {1, 2, 3, 6, 5, 4}
// Output: {1, 2, 4, 3, 5, 6}
// Explaination: The next permutation of the
// given array is {1, 2, 4, 3, 5, 6}.
// Example 2:

// Input: N = 3
// arr = {3, 2, 1}
// Output: {1, 2, 3}
// Explaination: As arr[] is the last
// permutation. So, the next permutation
// is the lowest one.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function nextPermutation() which takes N and arr[ ] as input parameters and returns a list of numbers containing the next permutation.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 10000

#include <bits/stdc++.h>
using namespace std;

class NextPermutation
{
public:
    void nextPermutation(int n, vector<int> &nums)
    {
        int i, j;
        for (i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
                break;
        }
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (j = n - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    NextPermutation obj;
    obj.nextPermutation(n, nums);
    for (int i : nums)
        cout << nums[i] << " ";
    return 0;
}