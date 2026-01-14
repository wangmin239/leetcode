class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i + 1 < grid.size() && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                if (j + 1 < grid[0].size() && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};



class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (const auto& row : grid) {
            if (row != grid.front()) {
                return false;
            }
        }
        
        int preVal = grid[0][0];
        
        for (size_t i = 1; i < grid[0].size(); i++) {
            if (preVal == grid[0][i]) {
                return false;
            }
            preVal = grid[0][i];
        }
        
        return true;
    }
};





class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (const auto& row : grid) {
            if (row != grid.front()) {
                return false;
            }
        }
        
        int preVal = grid.front().front();
        
        for (size_t i = 1; i < grid.front().size(); i++) {
            if (preVal == grid.front()[i]) {
                return false;
            }
            preVal = grid.front()[i];
        }
        
        return true;
    }
};