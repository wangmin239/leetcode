class Solution {
    static constexpr int mod = 1e9 + 7;

public:
    vector<vector<int>> mul(const vector<vector<int>> &lth, const vector<vector<int>> &rth) {
        vector<vector<int>> res(lth.size(), vector<int>(rth[0].size(), 0));
        for (int k = 0; k < lth[0].size(); k++) {
            for (int i = 0; i < lth.size(); i++) {
                for (int j = 0; j < rth[0].size(); j++) {
                    res[i][j] = (res[i][j] + 1ll * lth[i][k] * rth[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }

    int knightDialer(int n) {
        vector<vector<int>> base = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };
        vector<vector<int>> res = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

        vector<vector<int>> base2 = vector<vector<int>>(10, vector<int>(10, 0));
        for (int i = 0; i < 10; i++) {
            base2[i][i] = 1;
        }
        n--;
        while (n > 0) {
            if (n & 1) {
                base2 = mul(base2, base);
            }
            base = mul(base, base);
            n >>= 1;
        }
        res = mul(res, base2);
        int ret = 0;
        for (auto x : res[0]) {
            ret = (ret + x) % mod;
        }

        return ret;
    }
};


class Solution {
    static constexpr int mod = 1e9 + 7;

public:
    int knightDialer(int n) {
        vector<vector<int>> moves = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        vector<vector<int>> d(2, vector<int>(10, 0));
        fill(d[1].begin(), d[1].end(), 1);
        for (int i = 2; i <= n; i++) {
            int x = i & 1;
            for (int j = 0; j < 10; j++) {
                d[x][j] = 0;
                for (int k : moves[j]) {
                    d[x][j] = (d[x][j] + d[x ^ 1][k]) % mod;
                }
            }
        }
        int res = 0;
        for (auto x : d[n % 2]) {
            res = (res + x) % mod;
        }
        return res;
    }
};



/* memory recursive */
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> nextDigits(10);
        const int mod = 1e9 + 7;
        vector<vector<int>> layers(10, vector<int>(n + 1, 0));
        getNextDigits(nextDigits);
        
        auto dfs = [&](int layerId, int curVal, auto&& innerDfs) {
            if (layerId == 0) {
                return 1;
            }
            
            auto next = nextDigits[curVal];
            int sum = 0;
            for (int nextVal : next) {
                if (layers[nextVal][layerId - 1] != 0) {
                    sum += layers[nextVal][layerId - 1];
                } else {
                    sum += innerDfs(layerId - 1, nextVal, innerDfs);
                }
                sum %= mod;
            }
            
            layers[curVal][layerId] = sum;
            return sum;
        };
        
        int total = 0;
        for (int i = 0; i < 10; i++) {
            total += dfs(n - 1, i, dfs);
            total %= mod;
        }
        
        return total;
    }
    
    void getNextDigits(vector<vector<int>>& nextDigits) {
        vector<vector<char>> chessBoard(4, vector<char>(3));
        
        for (int i = 0; i < 9; i++) {
            chessBoard[i / 3][i % 3] = '0' + 1 + i;
        }
        
        chessBoard[3][0] = '*';
        chessBoard[3][1] = '0';
        chessBoard[3][2] = '#';
        
        int directions[8][2] = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
        
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                char ch = chessBoard[row][col];
                if (!isdigit(ch)) {
                    continue;
                }
                
                int digit = static_cast<int>(ch - '0');
                for (int i = 0; i < 8; i++) {
                    int x = row + directions[i][0];
                    int y = col + directions[i][1];
                    if (x >= 0 && x < 4 && y >=0 && y < 3) {
                        if (isdigit(chessBoard[x][y])) {
                            nextDigits[digit].push_back(static_cast<int>(chessBoard[x][y] - '0'));
                        }
                    }
                }
            }
        }
        
    }
};



/* crude recursivel */
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> nextDigits(10);
        const int mod = 1e9 + 7;

        getNextDigits(nextDigits);
        
        auto dfs = [&](int n, int curVal, auto&& innerDfs) {
            if (n == 0) {
                return 1;
            }
            
            auto next = nextDigits[curVal];
            int sum = 0;
            for (int nextVal : next) {
                sum += innerDfs(n - 1, nextVal, innerDfs);
            }
            return sum % mod;
        };
        
        int total = 0;
        for (int i = 0; i < 10; i++) {
            total += dfs(n - 1, i, dfs);
            total %= mod;
        }
        
        return total;
    }
    
    void getNextDigits(vector<vector<int>>& nextDigits) {
        vector<vector<char>> chessBoard(4, vector<char>(3));
        
        for (int i = 0; i < 9; i++) {
            chessBoard[i / 3][i % 3] = '0' + 1 + i;
        }
        
        chessBoard[3][0] = '*';
        chessBoard[3][1] = '0';
        chessBoard[3][2] = '#';
        
        int directions[8][2] = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
        
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                char ch = chessBoard[row][col];
                if (!isdigit(ch)) {
                    continue;
                }
                
                int digit = static_cast<int>(ch - '0');
                for (int i = 0; i < 8; i++) {
                    int x = row + directions[i][0];
                    int y = col + directions[i][1];
                    if (x >= 0 && x < 4 && y >=0 && y < 3) {
                        if (isdigit(chessBoard[x][y])) {
                            nextDigits[digit].push_back(static_cast<int>(chessBoard[x][y] - '0'));
                        }
                    }
                }
            }
        }
        
    }
};