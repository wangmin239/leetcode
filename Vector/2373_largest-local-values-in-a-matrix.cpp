class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        
        vector<vector<int>> ans(rows - 2, vector<int>(cols - 2, 0));
        
        auto getMax = [&](int i, int j) {
            int maxVal = 0;
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    maxVal = max(grid[i + row][j + col], maxVal);
                }
            }
            return maxVal;
        };
        
        
        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                ans[i][j] = getMax(i, j);
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        res[i][j] = max(res[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};

