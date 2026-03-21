/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int bottom = x, top = x + k - 1; bottom < top; bottom++, top--) {
            for (int i = 0; i < k; i++) {
                swap(grid[bottom][y + i], grid[top][y + i]);
            }
        }

        return grid;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int l = x, r = x + k - 1;
        while (l < r) {
            for (int j = y; j < y + k; j++) {
                swap(grid[l][j], grid[r][j]);
            }
            l++;
            r--;
        }
        return grid;
    }
};
