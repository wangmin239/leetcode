/* Official Solution 1 */
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        struct Edge {
            int v, dis;
        };

        vector<bool> vis(n + 1, false);
        vector<vector<Edge>> graph(n + 1);

        for (const auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        int ans = INT_MAX;
        auto dfs = [&](auto& self, int u) -> void {
            if (vis[u] == false) {
                vis[u] = true;
            }

            for (const auto& edge : graph[u]) {
                ans = min(ans, edge.dis);
                if (vis[edge.v] == false) {
                    self(self, edge.v);
                }
            }
        };

        dfs(dfs, 1);
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;

        DSU(int size) {
            parent.resize(size);
            for (int i = 0; i < size; ++i) {
                parent[i] = i;
            }
            rank.assign(size, 0);
        }

        void join(int x, int y) {
            int rx = find(x);
            int ry = find(y);

            if (rx == ry) {
                return;
            }

            if (rank[rx] == rank[ry]) {
                rank[rx]++;
            } else if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }

            parent[ry] = rx;
        }

        int find(int x) {
            return parent[x] == x ? x : (parent[x] = find(parent[x]));
        }
    };

public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;

        DSU dsu(n + 1);
        for (const auto& road : roads) {
            dsu.join(road[0], road[1]);
        }

        int component = dsu.find(1);
        for (const auto& road : roads) {
            if (dsu.find(road[0]) == component) {
                ans = min(ans, road[2]);
            }
        }

        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        struct Edge {
            int v, dis;
            bool operator>(const Edge& other) const { return dis > other.dis; }
        };

        vector<vector<Edge>> graph(n + 1);
        vector<bool> vis(n + 1, false);

        int ans = INT_MAX;
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

        for (const auto& road : roads) {
            int u = road[0], v = road[1], dis = road[2];
            graph[u].push_back({v, dis});
            graph[v].push_back({u, dis});

            if (pq.empty() && (u == 1 || v == 1)) {
                pq.push({v, dis});
            }
        }

        while (!pq.empty()) {
            auto [u, dis] = pq.top();
            pq.pop();

            if (vis[u]) {
                continue;
            }

            ans = min(ans, dis);
            vis[u] = true;

            for (const auto& edge : graph[u]) {
                if (!vis[edge.v]) {
                    pq.push(edge);
                }
            }
        }

        return ans;
    }
};
