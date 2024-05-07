class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> f(n, vector<int>(n, -1)), g(n, vector<int>(n, -1));
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int best = -1;
                    for (int dj1 = j1 - 1; dj1 <= j1 + 1; ++dj1) {
                        for (int dj2 = j2 - 1; dj2 <= j2 + 1; ++dj2) {
                            if (dj1 >= 0 && dj1 < n && dj2 >= 0 && dj2 < n && f[dj1][dj2] != -1) {
                                best = max(best, f[dj1][dj2] + (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]));
                            }
                        }
                    }
                    g[j1][j2] = best;
                }
            }
            swap(f, g);
        }

        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[j1][j2]);
            }
        }
        return ans;
    }
};

