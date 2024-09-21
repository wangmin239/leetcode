class Solution {
public:
    using ll = long long;
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<ll> points(n);
        for (int i = 0; i < n; i++) {
            points[edges[i]] += i;
        }
        ll max_points = -1;
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (points[i] > max_points) {
                max_points = points[i];
                res = i;
            }
        }
        return res;
    }
};





class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            int dest = edges[i];
            graph[dest].push_back(i);
        }
        
        long long maxScore = 0;
        int id;
        for (int i = 0; i < n; i++) {
            long long score = accumulate(graph[i].begin(), graph[i].end(), static_cast<long long>(0));
            if (score > maxScore) {
                maxScore = score;
                id = i;
            }
        }
        
        return id;
    }
};







class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int, vector<int>> graph;
        int n = edges.size();

        for (int i = 0; i < n; i++) {
            int dest = edges[i];
            graph[dest].push_back(i);
        }
        
        long long maxScore = 0;
        int id;
        for (auto [dest, start] : graph) {
            long long score = accumulate(start.begin(), start.end(), static_cast<long long>(0));
            if (score > maxScore) {
                maxScore = score;
                id = dest;
            }
        }
        
        return id;
    }
};