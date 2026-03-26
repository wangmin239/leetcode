/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long sum;
        long long tag;
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<long long> exist;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 4; k++) {
            exist.clear();
            exist.insert(0);
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            if (m < 2) {
                grid = rotation(grid);
                continue;
            }
            if(n == 1){
                for(int i = 0; i < m - 1; i++){
                    sum += grid[i][0];
                    tag = sum * 2 - total;
                    if(tag == 0 || tag == grid[0][0] || tag == grid[i][0]){
                        return true;
                    }
                }
                grid = rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for(int j = 0; j < n; j++){
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }
                tag = sum * 2 - total;
                if(i == 0){
                    if(tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1]){
                        return true;
                    }
                    continue;
                }
                if(exist.contains(tag)){
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};


/* Official Solution 2 */
class Solution {
    // 顺时针旋转矩阵 90°
    vector<vector<int>> rotate(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector b(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for (auto& row : grid) {
            for (int x : row) {
                total += x;
            }
        }

        auto check = [&](vector<vector<int>> a) -> bool {
            int m = a.size(), n = a[0].size();

            auto f = [&]() -> bool {
                unordered_set<long long> st = {0}; // 0 对应不删除数字
                long long s = 0;
                for (int i = 0; i < m - 1; i++) {
                    auto& row = a[i];
                    for (int j = 0; j < n; j++) {
                        int x = row[j];
                        s += x;
                        // 第一行，不能删除中间元素
                        if (i > 0 || j == 0 || j == n - 1) {
                            st.insert(x);
                        }
                    }
                    // 特殊处理只有一列的情况，此时只能删除第一个数或者分割线上那个数
                    if (n == 1) {
                        if (s * 2 == total || s * 2 - total == a[0][0] || s * 2 - total == row[0]) {
                            return true;
                        }
                        continue;
                    }
                    if (st.contains(s * 2 - total)) {
                        return true;
                    }
                    // 如果分割到更下面，那么可以删第一行的元素
                    if (i == 0) {
                        for (int x : row) {
                            st.insert(x);
                        }
                    }
                }
                return false;
            };

            // 删除上半部分中的一个数
            if (f()) {
                return true;
            }
            ranges::reverse(a);
            // 删除下半部分中的一个数
            return f();
        };

        // 水平分割 or 垂直分割
        return check(grid) || check(rotate(grid));
    }
};
