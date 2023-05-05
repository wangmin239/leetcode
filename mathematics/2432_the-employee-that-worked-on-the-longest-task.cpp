class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0], maxcost = logs[0][1];
        for (int i = 1; i < logs.size(); ++i) {
            int idx = logs[i][0];
            int cost = logs[i][1] - logs[i - 1][1];
            if (cost > maxcost || (cost == maxcost && idx < ans)) {
                ans = idx;
                maxcost = cost;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxTime = logs.front().back();
        int minId = logs.front().front();
        

        for (size_t id = 1; id < logs.size(); id++) {
            int timeSpec = logs[id].back() - logs[id - 1].back();
            if (timeSpec > maxTime) {
                maxTime = timeSpec;
                minId = logs[id].front();
            } else if (timeSpec == maxTime) {
                minId = min(logs[id].front(), minId);
            }
        }
        return minId;
    }
};

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxTime = INT_MIN;
        int minId = n;
        
        vector<int> prev {n, 0}
        for (const auto& log : logs) {
            int timeSpec = log.back() - prev.back();
            if (timeSpec > maxTime) {
                maxTime = timeSpec;
                minId = log.front();
            } else if (timeSpec == maxTime) {
                minId = min(log.front(), minId);
            }
            prev = move(log);
        }
        return minId;
    }
};