class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> degrees(n + 1);
        for (auto & edge : edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (degrees[i] == n - 1) {
                return i;
            }
        }
        return 0;
    }
};



class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> graph;
        int n = edges.size();
        int centralVal;
        
        for (auto& edge : edges) {
            for (int val : edge) {
                graph[val]++;
            
                if (graph[val] > 1) {
                    return val;
                }
            }
        }
        
        return centralVal;
            
    }
};




class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> graph;
        int n = edges.size();
        int centralVal;
        
        for (auto& edge : edges) {
            for (int val : edge) {
                graph[val]++;
            }
        }
        
        for (auto [val, count] : graph) {
            if (count == n) {
                centralVal = val;
            }
        }
        
        return centralVal;
            
    }
};