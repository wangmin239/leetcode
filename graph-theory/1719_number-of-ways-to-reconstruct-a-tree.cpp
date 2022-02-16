class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto &p : pairs) {
            adj[p[0]].emplace(p[1]);
            adj[p[1]].emplace(p[0]);
        }
        /* 检测是否存在根节点*/
        int root = -1;
        for (auto &[node, neighbours] : adj) {
            if (neighbours.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        if (root == -1) {
            return 0;
        }

        int res = 1;
        for (auto &[node, neighbours] : adj) {
            if (node == root) {
                continue;
            }
            int currDegree = neighbours.size();
            int parent = -1;
            int parentDegree = INT_MAX;

            /* 根据 degree 的大小找到 node 的父节点 parent */
            for (auto &neighbour : neighbours) {
                if (adj[neighbour].size() < parentDegree && adj[neighbour].size() >= currDegree) {
                    parent = neighbour;
                    parentDegree = adj[neighbour].size();
                }
            }
            if (parent == -1) {
                return 0;
            }

            /* 检测 neighbours 是否是 adj[parent] 的子集 */
            for (auto &neighbour : neighbours) {
                if (neighbour == parent) {
                    continue;
                }
                if (!adj[parent].count(neighbour)) {
                    return 0;
                }
            }
            if (parentDegree == currDegree) {
                res = 2;
            }
        }
        return res;
    }
};



class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> edges;
        vector<pair<int, int>> c1;
        int m = pairs.size();
        for (int i = 0; i < m; ++i) {
            int x = pairs[i][0];
            int y = pairs[i][1];
            ++freq[x];
            ++freq[y];
            edges[x].push_back(y);
            edges[y].push_back(x);
            c1.emplace_back(x, y);
        }
        
        vector<int> id;
        for (const auto& [k, _]: freq) {
            id.push_back(k);
        }
        
        unordered_map<int, int> order;
        unordered_map<int, int> parent;
        
        sort(id.begin(), id.end(), [&](int i, int j) {return freq[i] > freq[j];});
        
        order[id[0]] = 0;
        parent[id[0]] = -1;
        
        bool arbi = false;
        for (int i = 1; i < id.size(); ++i) {
            int u = id[i];
            int fa = -1;
            for (int v: edges[u]) {
                if (freq[v] > freq[u]) {
                    if (!order.count(v)) {
                        return 0;
                    }
                }
                if (freq[v] >= freq[u] && order.count(v)) {
                    if (fa == -1 || order[v] > order[fa]) {
                        fa = v;
                    }
                    if (freq[v] == freq[u]) {
                        arbi = true;
                    }
                }
            }
            if (fa == -1) {
                return 0;
            }
            
            order[id[i]] = i;
            parent[u] = fa;
        }
        
        vector<pair<int, int>> c2;
        for (const auto& [u, _]: order) {
            int v = parent[u];
            while (v != -1) {
                if (u < v) {
                    c2.emplace_back(u, v);
                }
                else {
                    c2.emplace_back(v, u);
                }
                v = parent[v];
            }
        }
        
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        
        if (c1 != c2) {
            return 0;
        }
        
        return arbi ? 2 : 1;
    }
};
