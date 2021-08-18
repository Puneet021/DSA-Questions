// Write an efficient algorithm that searches for a value in an m x n matrix.

//This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

#include <bits/stdc++.h>
using namespace std;

// Method 1
class Solve
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n, m;
        n = matrix.size();
        m = matrix[0].size();
        int lo = 0, hi = (n * m) - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return false;
    }
};

// Method 2
// class Solve
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         int n, m;
//         n = matrix.size();
//         m = matrix[0].size();
//         int i = 0, j = m - 1;
//         while (i < n && j >= 0)
//         {
//             if (matrix[i][j] > target)
//                 j--;
//             else if (matrix[i][j] < target)
//                 i++;
//             else
//                 return true;
//         }
//         return false;
//     }
// };

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;
    Solve obj;
    if (obj.searchMatrix(matrix, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}