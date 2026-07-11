/* Official Solution 1 */
class DSU {
public:
    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[y] > rank[x]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto& edge : edges) {
            dsu.unionSet(edge[0], edge[1]);
        }

        vector<int> numV(n, 0);
        vector<int> numE(n, 0);
        for (int i = 0; i < n; i++) {
            numV[dsu.find(i)]++;
        }
        for (auto& edge : edges) {
            numE[dsu.find(edge[0])]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                ans += numE[i] == (numV[i] * (numV[i] - 1) / 2);
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> visit(n, 0);
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0, V, E;
        auto dfs = [&](this auto&& dfs, int u) -> void{
            visit[u] = 1;
            V++;
            E += g[u].size();
            for (int v : g[u]) {
                if (!visit[v]) {
                    dfs(v);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                V = 0;
                E = 0;
                dfs(i);
                ans += E == V * (V - 1);
            }
        }
        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        int ans = 0, V, E;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        auto bfs = [&](int s) -> bool {
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (vis[u]) {
                    continue;
                }
                vis[u] = 1;
                V++;
                E += g[u].size();
                for (auto v : g[u]) {
                    q.push(v);
                }
            }
            return E == V * (V - 1);
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                V = 0;
                E = 0;
                if (bfs(i)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};