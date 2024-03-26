class Graph {
public:
    using pii = pair<int, int>;
    Graph(int n, vector<vector<int>>& edges) {
        this->graph = vector<vector<pii>>(n);
        for (auto &vec : edges) {
            int x = vec[0];
            int y = vec[1];
            int cost = vec[2];
            graph[x].emplace_back(y, cost);
        }
    }
    
    void addEdge(vector<int> edge) {
        int x = edge[0];
        int y = edge[1];
        int cost = edge[2];
        graph[x].emplace_back(y, cost);
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(graph.size(), INT_MAX);
        dist[node1] = 0;
        pq.emplace(0, node1);
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();
            if (cur == node2) {
                return cost;
            }
            for (auto [next, ncost] : graph[cur]) {
                if (dist[next] > cost + ncost) {
                    dist[next] = cost + ncost;
                    pq.emplace(cost + ncost, next);
                }
            }
        }
        return -1;
    }
private:
    vector<vector<pii>> graph;
};


/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto &e: edges) {
            dist[e[0]][e[1]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int x = edge[0], y = edge[1], cost = edge[2];
        if (cost >= dist[x][y]) {
            return;
        }
        int n = dist.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][x] != INT_MAX && dist[y][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][x] + cost + dist[y][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        int res = dist[node1][node2];
        return res == INT_MAX ? -1 : res;
    }
private:
    vector<vector<int>> dist;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */