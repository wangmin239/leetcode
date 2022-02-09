class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int len = nums.size();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] - nums[j] == k || nums[j] - nums[i] == k) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};



class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> diffMap;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            diffMap[nums[i]].push_back(i);
        }
        
        for (auto [val, indexVec] : diffMap) {
            
            if (diffMap.count(val + k) > 0) {
                cnt += validPairs(indexVec, diffMap[val + k]);
            }
            
            if (diffMap.count(val - k) > 0) {
                cnt += validPairs(indexVec, diffMap[val - k]);
            }
        }
        
        return cnt;
    }
    
    inline int validPairs(const vector<int>& indexVec, const vector<int>& vec) {
        int pairs = 0;
        
        for (int index : indexVec) {
            for (auto seq : vec) {
                if (seq > index) {
                    pairs++;
                }
            }
        }
        
        return pairs;
    }
};



class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> cnt;
        for (int j = 0; j < n; ++j) {
            res += (cnt.count(nums[j] - k) ? cnt[nums[j] - k] : 0);
            res += (cnt.count(nums[j] + k) ? cnt[nums[j] + k] : 0);
            ++cnt[nums[j]];
        }
        return res;
    }
};
