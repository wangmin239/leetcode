class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx, grid[i][j]);
            }
            res += mx;
        }
        return res;
    }
};


class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum = 0;
        
        for (auto& row : grid) {
            sort(row.begin(), row.end(), greater<int>());
        }
        
        for (size_t col = 0; col < grid.front().size(); col++) {
            int maxVal = INT_MIN;
            for (size_t row = 0; row < grid.size(); row++) {
                maxVal = max(maxVal, grid[row][col]);
            }
            sum += maxVal;
        }
        return sum;
    }
};

