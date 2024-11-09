class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                pos[grid[i][j]] = {i, j};
            }
        }
        this->grid = move(grid);
    }
    
    int adjacentSum(int value) {
        return getSum(value, 0);
    }
    
    int diagonalSum(int value) {
        return getSum(value, 1);
    }

    int getSum(int value, int idx) {
        auto [x, y] = pos[value];
        int ans = 0;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[idx][d][0];
            int ny = y + dirs[idx][d][1];
            if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size()) {
                ans += grid[nx][ny];
            }
        }
        return ans;
    }

private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> pos;
    static constexpr int dirs[2][4][2] = {
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
        {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}
    };
};



class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& matrix) {
        grid = matrix;
        n = matrix.size();
        uniqPtr = make_unique<pair<int, int>[]>(n * n);
        pair<int, int>* ptr = uniqPtr.get();
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int index = grid[x][y];
                ptr[index] = make_pair(x, y);
            }
        }
    }
    
    int adjacentSum(int value) {
        auto ptr = uniqPtr.get();
        int x = ptr[value].first;
        int y = ptr[value].second;
        int sum = 0;
        int adj[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < 4; i++) {
            if (x + adj[i][0] >= 0 && x + adj[i][0] < n && y + adj[i][1] >= 0 && y + adj[i][1] < n) {
                sum += grid[x + adj[i][0]][y + adj[i][1]];
            }
        }
        
        return sum;
    }
    
    int diagonalSum(int value) {
        auto ptr = uniqPtr.get();
        int x = ptr[value].first;
        int y = ptr[value].second;
        int sum = 0;
        int adj[4][2] = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        
        for (int i = 0; i < 4; i++) {
            if (x + adj[i][0] >= 0 && x + adj[i][0] < n && y + adj[i][1] >= 0 && y + adj[i][1] < n) {
                sum += grid[x + adj[i][0]][y + adj[i][1]];
            }
        }
        
        return sum;        
    }
    
    unique_ptr<pair<int, int>[]> uniqPtr;
    vector<vector<int>> grid;
    int n;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */