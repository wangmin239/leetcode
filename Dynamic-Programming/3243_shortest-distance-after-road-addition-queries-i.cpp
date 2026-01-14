class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> neighbors(n);
        for (int i = 0; i < n - 1; i++) {
            neighbors[i].push_back(i + 1);
        }
        vector<int> res;
        for (auto &query : queries) {
            neighbors[query[0]].push_back(query[1]);
            res.push_back(bfs(n, neighbors));
        }
        return res;
    }

    int bfs(int n, const vector<vector<int>> &neighbors) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : neighbors[x]) {
                if (dist[y] >= 0) {
                    continue;
                }
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
        return dist[n - 1];
    }
};

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> prev(n);
        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            prev[i].push_back(i - 1);
            dp[i] = i;
        }
        vector<int> res;
        for (auto &query : queries) {
            prev[query[1]].push_back(query[0]);
            for (int v = query[1]; v < n; v++) {
                for (int u : prev[v]) {
                    dp[v] = min(dp[v], dp[u] + 1);
                }
            }
            res.push_back(dp[n - 1]);
        }
        return res;
    }
};




class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> dp(n, 0);
        int size = queries.size();
        vector<int> ans(size, 0);
        
        for(int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }
        
        
        auto dfs = [&](int start, auto&& Dfs) {
            int distance = n - 1;
            
            if (start == n - 1) {
                return 0;
            }
            
            for (auto& nextStart : graph[start]) {
                distance = min(distance, Dfs(nextStart, Dfs));
            }
            
            return distance + 1;
        };
        
        int i = 0;
        for (auto& query : queries) {
            int start = query.front();
            int end = query.back();
            
            graph[start].push_back(end); 
            ans[i++] = dfs(0, dfs);
        }
        return ans;
    }
};