class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1);
        vector<int> outDegrees(n + 1);
        for (auto& edge : trust) {
            int x = edge[0], y = edge[1];
            ++inDegrees[y];
            ++outDegrees[x];
        }
        for (int i = 1; i <= n; ++i) {
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1;
        
        unique_ptr<int[]> uniqPtr = make_unique<int[]>(n);
        int* ptr = uniqPtr.get();

        fill(ptr, ptr + n, 0);

        for (const auto& vec : trust) {
            ptr[vec.back() - 1] += 1;
        }

        
        for (int i = 0; i < n; i++) {
            if (ptr[i] == n - 1) {
                ans = i + 1;
                break;                
            }
        }
        
        for (const auto& vec : trust) {
            if (vec.front() == ans) {
                return -1;
            }
        }
        
        return ans;
    }
};






class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1;
        
        unique_ptr<pair<bool, int>[]> uniqPtr = make_unique<pair<bool,int>[]>(n);
        pair<bool, int>* ptr = uniqPtr.get();

        for (int i = 0; i < n; i++) {
            ptr[i] = make_pair(false, 0);
        }

        for (const auto& vec : trust) {
            ptr[vec.back() - 1].second += 1;
            ptr[vec.front() - 1].first = true; 
        }

        int cntN = 0;
        for (int i = 0; i < n; i++) {
            if (ptr[i].second == n - 1 && ptr[i].first == false) {
                return i + 1;
            }
        }

        return -1;
    }
};