/* Official Solution 1 */
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans = 0;

        // 返回子树 x 的点权和
        auto dfs = [&](this auto&& dfs, int x, int fa) -> long long {
            long long sum = values[x];
            for (int y : g[x]) {
                if (y != fa) { // 避免访问父节点
                    // 加上子树 y 的点权和，得到子树 x 的点权和
                    sum += dfs(y, x);
                }
            }
            ans += sum % k == 0;
            return sum;
        };

        dfs(0, -1);
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int result = 0;
        auto dfs = [&](auto&& innerDfs, int node, int parent) -> long long {
            long long sum = values[node];
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    sum += innerDfs(innerDfs, neighbor, node);
                }
            }

            result += sum % k == 0;
            return sum;
        };
        dfs(dfs, 0, -1);
        return result;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int result = 0;
        function<long long(int, int)> dfs = [&](int node, int parent) -> long long {
            long long sum = values[node];
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    sum += dfs(neighbor, node);
                }
            }
            if (sum % k == 0) {
                ++result;
            }
            return sum;
        };
        dfs(0, -1);
        return result;
    }
};

