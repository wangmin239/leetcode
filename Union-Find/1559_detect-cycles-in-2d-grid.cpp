/* Official Solution 1 */
/* Original Solution 1 */
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        const int chNum = 26;
        vector<pair<int, int>> chArr[chNum];

        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int id = grid[i][j] - 'a';
                
                chArr[id].push_back({i, j});
            }
        }
        
        auto backTrace = [&](int x, int y, int cnt, set<pair<int, int>>& chSet, const char ch, auto&& self) {
            if (chSet.count({x, y}) > 0 && cnt > 4) {
                return true;
            }
            
            const int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            bool isRing = false;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                
                if (nx < 0 || nx == rows || ny < 0 || ny == cols || grid[nx][ny] != ch || chSet.count({nx, ny}) > 0) {
                    continue;
                }
                
                chSet.insert({nx, ny});
                isRing |= self(nx, ny, cnt + 1, chSet, ch, self);
            }
            
            return isRing;         
        };
        
        for (int i = 0; i < chNum; i++) {
            auto& chVec = chArr[i];
            int size = chVec.size();
            set<pair<int, int>> chSet;
        
            for (int j = 0; j < size; j++) {
                if (chSet.count(chVec[j]) > 0) {
                    continue;
                }
                chSet.insert(chVec[j]);
                if (backTrace(chVec[j].first, chVec[j].second, 0, chSet, 'a' + i, backTrace) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


/* Official Solution 1 */
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    
    void unite(int x, int y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
    }
    
    bool findAndUnite(int x, int y) {
        int parentX = findset(x);
        int parentY = findset(y);
        if (parentX != parentY) {
            unite(parentX, parentY);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

