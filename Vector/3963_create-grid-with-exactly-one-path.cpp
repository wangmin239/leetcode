/* Original Solution 1 */
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        vector<vector<string>> ans;
        auto dfs = [&](int x, int y, auto&& self) {
            if (x == m && y == n - 1 || x == m - 1 && y == n) {
                ans.push_back(grid);
                return;
            }

            if (x >= m || y >= n) {
                return;
            }

            grid[x][y] = '.';
            self(x + 1, y, self);
            self(x, y + 1, self);
            grid[x][y] = '#';

            return;
        };

        dfs(0, 0, dfs);
        int num = ans.size();

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, num);
        int randomInt = dist(gen);


        return ans[randomInt];
    }
};


/* Original Solution 1 */
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        for (int i = 0; i < n; i++) {
            grid[m - 1][i] = '.';
        }

        for (int i = 0; i < m; i++) {
            grid[i][0] = '.';
        }

        return grid;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);
        ans[0].resize(n, '.');
        for (int i = 1; i < m; i++) {
            ans[i].resize(n, '#');
            ans[i][n - 1] = '.';
        }
        return ans;
    }
};
