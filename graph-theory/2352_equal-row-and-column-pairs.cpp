class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt;
        for (auto row : grid) {
            cnt[row]++;
        }

        int res = 0;
        for (int j = 0; j < n; j++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                arr.emplace_back(grid[i][j]);
            }
            if (cnt.find(arr) != cnt.end()) {
                res += cnt[arr];
            }
        }
        return res;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs < rhs;
        };
        
        map<vector<int>, int, decltype(cmp)> rowsMap(cmp);
        int n = grid.size();
        for (auto row : grid) {  
            ++rowsMap[row];
        }
        
        int ans = 0;
        for (int col = 0; col < n; col++) {
            vector<int> vals(n, 0);
            for (int row = 0; row < n; row++) {
                vals[row] = grid[row][col];
            }
            if (rowsMap.count(vals)) {
                ans += rowsMap[vals];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (equal(row, col, grid)) {
                    res++;
                }
            }
        }
        return res;
    }

    bool equal(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (grid[row][i] != grid[i][col]) {
                return false;
            }
        }
        return true;
    }
};

