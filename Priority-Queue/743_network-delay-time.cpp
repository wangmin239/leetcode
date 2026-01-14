class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<bool> isVisited(n, false);
        
        for (const auto &time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        
        auto check = [](const vector<bool>& isVisited) {
            for(int visited : isVisited) {
                if (visited == false) {
                    return false;
                }
            }
            return true;
        };
        
        int elapsedTime = 0;
        pq.push(make_pair(0, k));
        
        while (pq.empty() == false) {
            auto parent = pq.top();
            pq.pop();

            elapsedTime = parent.first;
            isVisited[parent.second - 1] = true;
            
            for (auto& child : adj[parent.second]) {
                if (isVisited[child.first - 1] == false) {
                    pq.push({child.second + elapsedTime, child.first});
                }
            }
            
            if (check(isVisited) == true) {
                break;
            }
        }
        
        return check(isVisited) == true? elapsedTime : -1;
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; ++y) {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};
