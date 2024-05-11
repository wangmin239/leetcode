class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> distance;
        int res = 0, cur_dis = 0;
        for (int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            if (i > 0) {
                cur_dis += travel[i - 1];
            }
            for (auto c : garbage[i]) {
                distance[c] = cur_dis;
            }
        }
        for (auto &[k, v] : distance) {
            res += v;
        }
        return res;
    }
};




class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> distance(n, 0);
        

        for (int i = 0; i < n - 1; i++) {
            distance[i + 1] = distance[i] + travel[i];
        }
        
        int steps = 0;
        string garbageKinds("MPG");
        
        for (const char kind : garbageKinds) {
            steps += collectGarbageStep(garbage, distance, kind);
        }
        
        return steps;
    }
    
    int collectGarbageStep(const vector<string>& garbage,  const vector<int>& distance, const char kind) {
        int steps = 0;
        int n = garbage.size();
        int lastIndex = 0;
        auto processGarbageKind = [](const string& garbageStr, const char kind) {
            int cnt = 0;
            for (char ch : garbageStr) {
                if (ch == kind) {
                    ++cnt;
                }
            }
            return cnt;
        };
        
        
        for (int i = 0; i < n; i++) {
            int processSteps = processGarbageKind(garbage[i], kind);
            if (processSteps > 0) {
                steps += processSteps;
                lastIndex = i;
            }
        }
        
        return steps + distance[lastIndex];
    }
};