/* Original Solution 1 */
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int depth = 0;
        int n = edges.size() + 2;
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            int u = edge.front();
            int v = edge.back();

            if (u > v) {
                swap(u, v);
            }
            adj[u].push_back(v);
        }
        queue<int> nextPoint;
        nextPoint.push(1);
        while (nextPoint.empty() == false) {
            int size = nextPoint.size();
            while (size--) {
                int point = nextPoint.front();

                nextPoint.pop();
                for (int adjPoint : adj[point]) {
                    nextPoint.push(adjPoint);
                }
            }
            ++depth;
        }

        long long ans = 1LL;
        const int mod = 1e9 + 7;
        const int intBits = 31;

        depth -= 2;

        while (depth > intBits) {
             ans *= (1LL << intBits);
             ans %= mod;
             depth -= intBits;
        }

        ans *= (1LL << depth);
        return ans % mod;
    }
};


/* Official Solution 1 */
class Solution {
    static constexpr int mod = 1e9 + 7;
    int qpow(int x, int y) {
        int res = 1; 
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }
    int dfs(vector<vector<int>> &g, int x, int f) {
        int max_dep = 0;
        for (auto &y : g[x]) {
            if (y == f) {
                continue;
            }
            max_dep = max(max_dep, dfs(g, y, x) + 1);
        }
        return max_dep;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int max_dep = dfs(g, 1, 0);
        return qpow(2, max_dep - 1);
    }
};



class Solution {
    const int MOD = 1'000'000'007;

    long long qpow(long long x, int n) {
        long long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        auto dfs = [&](this auto&& dfs, int x, int fa) -> int {
            int d = 0;
            for (int y : g[x]) {
                if (y != fa) { // 不递归到父节点
                    d = max(d, dfs(y, x) + 1);
                }
            }
            return d;
        };

        int k = dfs(1, 0);
        return qpow(2, k - 1);
    }
};
