/* Official Solution 1 */
class LCA {
public:
    LCA(const vector<vector<int>>& edges, const int root = 1) {
        n = edges.size() + 1;
        m = (log(n) / log(2)) + 1;
        e.resize(n + 1);
        d.resize(n + 1);
        f.resize(n + 1, vector<int>(m, 0));
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(root, 0);
        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                f[x][i] = f[f[x][i - 1]][i - 1];
            }
        }
    }
    void dfs(int x, int fa) {
        f[x][0] = fa;
        for (auto &y : e[x]) {
            if (y == fa) {
                continue;
            }
            d[y] = d[x] + 1;
            dfs(y, x);
        }
    }
    
    int lca(int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (d[x] <= d[f[y][i]]) {
                y = f[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = m - 1; i >= 0; i--) {
            if (f[y][i] != f[x][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }

    int dis(int x, int y) {
        return d[x] + d[y] - d[lca(x, y)] * 2;
    }
private:
    int n;
    int m;
    vector<int> d;
    vector<vector<int>> e;
    vector<vector<int>> f;
};

const int MOD = 1e9 + 7;
const int N = 100010;
int p2[N];
auto init = [] {
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCA lca(edges, 1);
        int m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x != y) {
                res[i] = p2[lca.dis(x, y) - 1];
            }
        }
        return res;
    }
};

/* Official Solution 2 */
class LcaBinaryLifting {
    vector<int> depth;
    vector<vector<int>> pa;

public:
    LcaBinaryLifting(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int m = bit_width((unsigned) n); // n 的二进制长度
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        depth.resize(n);
        pa.resize(n, vector<int>(m, -1));
        auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
            pa[x][0] = fa;
            for (int y : g[x]) {
                if (y != fa) {
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                if (int p = pa[x][i]; p != -1) {
                    pa[x][i + 1] = pa[p][i];
                }
            }
        }
    }

    int get_kth_ancestor(int node, int k) {
        for (; k; k &= k - 1) {
            node = pa[node][countr_zero((unsigned) k)];
        }
        return node;
    }

    // 返回 x 和 y 的最近公共祖先（节点编号从 0 开始）
    int get_lca(int x, int y) {
        if (depth[x] > depth[y]) {
            swap(x, y);
        }
        y = get_kth_ancestor(y, depth[y] - depth[x]); // 使 y 和 x 在同一深度
        if (y == x) {
            return x;
        }
        for (int i = pa[x].size() - 1; i >= 0; i--) {
            int px = pa[x][i], py = pa[y][i];
            if (px != py) {
                x = px;
                y = py; // 同时往上跳 2^i 步
            }
        }
        return pa[x][0];
    }

    // 返回 x 到 y 的距离（最短路长度）
    int get_dis(int x, int y) {
        return depth[x] + depth[y] - depth[get_lca(x, y)] * 2;
    }
};

const int MOD = 1'000'000'007;
const int MX = 100'000;

int pow2[MX];

auto init = [] {
    // 预处理 2 的幂
    pow2[0] = 1;
    for (int i = 1; i < MX; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LcaBinaryLifting g(edges);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0] - 1;
            int y = queries[i][1] - 1;
            if (x != y) {
                ans[i] = pow2[g.get_dis(x, y) - 1];
            }
        }
        return ans;
    }
};

研究生毕业后没找到好工作，就在他导师的公司上班了两年，突然就辞职了