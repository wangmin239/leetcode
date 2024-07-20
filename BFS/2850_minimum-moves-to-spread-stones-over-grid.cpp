class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> more, less;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] > 1) {
                    for (int k = 2; k <= grid[i][j]; ++k) {
                        more.emplace_back(i, j);
                    }
                }
                else if (grid[i][j] == 0) {
                    less.emplace_back(i, j);
                }
            }
        }

        int ans = INT_MAX;
        do {
            int steps = 0;
            for (int i = 0; i < more.size(); ++i) {
                steps += abs(more[i].first - less[i].first) + abs(more[i].second - less[i].second);
            }
            ans = min(ans, steps);
        } while (next_permutation(more.begin(), more.end()));
        return ans;
    }
};



class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int rows = grid.size();
        int cols = grid.front().size();

        /* enqueue the stones that are greater than one*/
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] > 1) {
                    que.push({row, col});
                }
            }
        }
        
        int minTotalSteps = 0;
        int steps = 1;
        auto moveStones = [&](int x, int y, int& stones, const int steps) {
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    if (stones == 1) {
                        return;
                    }
                    /* calculate the total steps of one stone is moved */
                    if (grid[row][col] == 0 && abs(row - x) + abs(col - y) == steps ) {
                        --stones;
                        grid[row][col] = 1;
                        minTotalSteps += steps;
                    }
                }
            }
        };
        
        /* move the stones to the grid that has none */
        while (que.empty() == false) {
            for (int size = que.size(); size > 0; size--) {
                auto [x, y] = que.front();
                int stones = grid[x][y];
                
                que.pop();
                moveStones(x, y, stones, steps);
                if (stones > 1) {
                    que.push({x, y});
                }
                grid[x][y] = stones;
            }
            ++steps;
        }
        return minTotalSteps;
    }
};