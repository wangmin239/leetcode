class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int best = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; ++i) {
            if (int delta = arr[i + 1] - arr[i]; delta < best) {
                best = delta;
                ans = {{arr[i], arr[i + 1]}};
            }
            else if (delta == best) {
                ans.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int len = arr.size();      
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        
        sort(arr.begin(), arr.end(), less<int>());
        
        for (int i = 1; i < len; i++) {
            int diff = arr[i] - arr[i - 1];
            
            if (minDiff > diff) {
                minDiff = diff;
                ans = {{arr[i - 1], arr[i]}};
            } else if (minDiff == diff) {
                ans.push_back(initializer_list<int>{arr[i - 1], arr[i]});
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int len = arr.size();      
        int minDiff = INT_MAX;
        
        sort(arr.begin(), arr.end(), less<int>());
        
        for (int i = 1; i < len; i++) {
            int diff = arr[i] - arr[i - 1];
            minDiff = minDiff > diff ? diff : minDiff;
        }
        
        vector<vector<int>> ans;
        
        for (int i = 1; i < len; i++) {
            int diff = arr[i] - arr[i - 1];
            
            if (minDiff == diff) {
                ans.push_back(vector<int> {arr[i - 1], arr[i]});
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        using pii = pair<int, int>;
        int len = arr.size();      
        unordered_map<int, vector<vector<int>>> diffMap;
        
        sort(arr.begin(), arr.end(), greater<int>());
        
        for (int i = 1; i < len; i++) {
           int diff = arr[i] - arr[i - 1];
           vector<int> tmpVec {arr[i - 1], arr[i]};
           diffMap[diff].push_back(tmpVec);
        }
        
        int minDiff = INT_MAX;
        
        for (const auto [diff, vec] : diffMap) {
            if (minDiff > diff) {
                minDiff = diff;
            }
        }
        
        return diffMap[minDiff];
        
    }
};