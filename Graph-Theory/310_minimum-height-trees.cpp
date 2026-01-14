class Solution {
public:
    int findLongestNode(int u, vector<int> & parent, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;
  
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto & v : adj[curr]) {
                if (!visit[v]) {
                    visit[v] = true;
                    parent[v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        
        vector<int> parent(n, -1);
        /* 找到与节点 0 最远的节点 x */
        int x = findLongestNode(0, parent, adj);
        /* 找到与节点 x 最远的节点 y */
        int y = findLongestNode(x, parent, adj);
        /* 求出节点 x 到节点 y 的路径 */
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};



class Solution {
public:
    void dfs(int u, vector<int> & dist, vector<int> & parent, const vector<vector<int>> & adj) {
        for (auto & v : adj[u]) {
            if (dist[v] < 0) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                dfs(v, dist, parent, adj); 
            }
        }
    }

    int findLongestNode(int u, vector<int> & parent, const vector<vector<int>> & adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        dist[u] = 0;
        dfs(u, dist, parent, adj);
        int maxdist = 0;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (dist[i] > maxdist) {
                maxdist = dist[i];
                node = i;
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        /* 找到距离节点 0 最远的节点  x */
        int x = findLongestNode(0, parent, adj);
        /* 找到距离节点 x 最远的节点  y */
        int y = findLongestNode(x, parent, adj);
        /* 找到节点 x 到节点 y 的路径 */
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (auto & edge : edges){
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                qu.emplace(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = qu.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (--degree[v] == 1) {
                        qu.emplace(v);
                    }
                }
            }
        }
        while (!qu.empty()) {
            ans.emplace_back(qu.front());
            qu.pop();
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge.front()].push_back(edge.back());
            graph[edge.back()].push_back(edge.front());
        }
        

        auto getHeight = [n] (const int node, vector<vector<int>>& graph) {
            unordered_set<int> visited;
            queue<int> q;
            int height = 0;
            
            visited.insert(node);
            q.push(node);
            
            while (visited.size() != n) {
                int size = q.size();
                while (size-- != 0) {
                    int parent = q.front();
                    
                    q.pop();
                    
                    for (const int& nextNode : graph[parent]) {
                        if (visited.count(nextNode) == 0) {
                            q.push(nextNode);
                            visited.insert(nextNode);
                        }
                    }
                    
                }
                ++height;
            }
            return height;
            
        };

        vector<int> heights(n);
        int minHeight = INT_MAX;
        vector<int> ans;
        
        for (int node = 0; node < n; node++) {
            int curHeight = getHeight(node, graph);
            
            if (curHeight > minHeight) {
                continue;
            }
            
            if (minHeight > curHeight) {
                minHeight = curHeight;
                ans.clear();
            } 
            ans.push_back(node);
             
        }
        
        return ans;
        
    }
};