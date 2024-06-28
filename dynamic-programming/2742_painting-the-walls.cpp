class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> f(n * 2 + 1, INT_MAX / 2);
        f[n] = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> g(n * 2 + 1, INT_MAX / 2);
            for (int j = 0; j <= n * 2; ++j) {
                // 付费
                g[min(j + time[i], n * 2)] = min(g[min(j + time[i], n * 2)], f[j] + cost[i]);
                // 免费
                if (j > 0) {
                    g[j - 1] = min(g[j - 1], f[j]);
                }
            }
            f = move(g);
        }
        return *min_element(f.begin() + n, f.end());
    }
};

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> f(n + 2, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n + 1; j >= 0; --j) {
                f[min(j + time[i], n) + 1] = min(f[min(j + time[i], n) + 1], f[j] + cost[i]);
            }
        }
        return min(f[n], f[n + 1]);
    }
};


class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> ids(n);
        
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
             if (cost[lhs] < cost[rhs]) {
                 return true;
             }
             
             if (cost[lhs] == cost[rhs]) {
                 return time[lhs] > time[rhs];
             }
             return false;
        });
        

        int costTime = 0;
        int freeTime = n;
        int i;
        for (i = 0; i < n; i++) {
            if (costTime + time[ids[i]] >= n - i) {
                break;
            }
            costTime += time[ids[i]];
        }

        int minCost = 0;
        for (int j = 0; j <= i; j++) {
            minCost += cost[ids[j]];
        }
        
        return minCost;
    }
};
