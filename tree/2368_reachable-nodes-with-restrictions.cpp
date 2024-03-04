class UnionFind {
public:
    UnionFind(int n):f(n), rank(n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] > rank[ry]) {
                f[ry] = rx;
            } else if (rank[rx] < rank[ry]) {
                f[rx] = ry;
            } else {
                f[ry] = rx;
                rank[rx]++;
            }
        }
    }

    int find(int x) {
        if (x != f[x]) {
            x = find(f[x]);
        }
        return f[x];
    }

    int count() {
        int cnt = 0;
        int rt = find(0);
        for (int i = 0; i < f.size(); i++) {
            if (rt == find(i)) {
                cnt++;
            }
        }
        return cnt;
    }
private:
    vector<int> f;
    vector<int> rank;
};
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> isrestricted(n);
        for (auto &x : restricted) {
            isrestricted[x] = 1;
        }
        
        UnionFind uf = UnionFind(n);
        for (auto &v : edges) {
            if (isrestricted[v[0]] || isrestricted[v[1]]) {
                continue;
            }
            uf.merge(v[0], v[1]);
        }
        return uf.count();
    }
};




class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> isrestricted(n);
        for (auto x : restricted) {
            isrestricted[x] = 1;
        }

        vector<vector<int>> g(n);
        for (auto &v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int cnt = 0;
        function<void(int, int)> dfs = [&](int x, int f) {
            cnt++;
            for (auto &y : g[x]) {
                if (y != f && !isrestricted[y]) {
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);
        return cnt;
    }
};



class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> resSet(restricted.begin(), restricted.end());
        vector<vector<int>> graph(n, vector<int>());
        
        for (auto edge : edges) {
            graph[edge.front()].push_back(edge.back());
            graph[edge.back()].push_back(edge.front());
        }
        
        int maxCnt = 0;
        for (int i = 0; i < n; i++) {
            if (resSet.count(i) != 0) {
                continue;
            }
            maxCnt = max(maxCnt, dfs(i, graph, resSet));   
        }
        
        return maxCnt;
    }
    
    int dfs(int node, vector<vector<int>>& graph, unordered_set<int>& resSet) {
        int maxDepth = 0;
        
        for(int nextNode : graph[node]) {
            if (resSet.count(nextNode) != 0) {
                continue;
            }
            maxDepth = max(maxDepth, dfs(nextNode, graph, resSet));
        }
        
        return 1 + maxDepth;
    }
};