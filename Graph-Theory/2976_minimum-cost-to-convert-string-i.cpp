/* Original Solution 1 */
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<long long, long long> charPair;
        int n = original.size();
        int len = source.length();
        
        for (int i = 0; i < n; i++) {
            long long key =  (1LL << ((original[i] - 'a') + 32)) | ( 1 << (changed[i] - 'a'));
            if (charPair.count(key)) {
                charPair[key] = min(charPair[key], static_cast<long long>(cost[i]));
            } else {
                charPair[key] = cost[i];
            }
        }
        
        unordered_map<long long, long long> convertCost;
        auto getCost = [&](int mask, const int originalCh, int cur, int curTotal, auto&& self) {
            if (mask & cur) {
                return;
            }
            cur = cur == 0 ? originalCh : cur;
            for (const auto& [key, costVal] : charPair) {
                int high = (key & 0xFFFFFFF00000000) >> 32;
                if (high == cur) {
                    int nextHi = key & 0xFFFFFFF;
                    long long nextKey = (static_cast<long long>(originalCh) << 32) | nextHi; 
                    if (convertCost.count(nextKey)) {
                        convertCost[nextKey] = min(convertCost[nextKey], curTotal + costVal);
                    } else {
                        convertCost[nextKey] = curTotal + costVal;
                    }
                    self(mask | cur, originalCh, nextHi, curTotal + costVal, self);
                }
                
            }
            
        };
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            getCost(0, 1 << (ch - 'a'), 0, 0, getCost);       
        }
        
        
        long long total = 0;
        for (int i = 0; i < len; i++) {
            if (source[i] == target[i]) {
                continue;
            }
            
            long long key = (1LL << ((source[i] - 'a') + 32)) | ( 1 << (target[i] - 'a'));
            if (convertCost.count(key) == 0) {
                return -1LL;
            }
            
            total += convertCost[key];
        }
        return total;
    }
};


/* Official Solution 1 */
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> G(26, vector<int>(26, inf));
        for (int i = 0; i < 26; ++i) {
            G[i][i] = 0;
        }

        int m = original.size();
        for (int i = 0; i < m; ++i) {
            int idx = original[i] - 'a';
            int idy = changed[i] - 'a';
            G[idx][idy] = min(G[idx][idy], cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        int n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = source[i] - 'a';
            int idy = target[i] - 'a';
            if (G[idx][idy] == inf) {
                return -1;
            }
            ans += G[idx][idy];
        }

        return ans;
    }

private:
    static constexpr int inf = INT_MAX / 2;
};



/* Official Solution 2 */
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 0x3f3f3f3f;
        int dis[26][26];
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 0; i < 26; i++) {
            dis[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            dis[x][y] = min(dis[x][y], cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (dis[i][k] == INF) {
                    continue; // 巨大优化！
                }
                for (int j = 0; j < 26; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            int d = dis[source[i] - 'a'][target[i] - 'a'];
            if (d == INF) {
                return -1;
            }
            ans += d;
        }
        return ans;
    }
};
