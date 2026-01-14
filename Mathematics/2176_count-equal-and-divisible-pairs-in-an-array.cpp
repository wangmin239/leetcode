/* Official Solution */
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;   // 符合要求数对个数
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((i * j) % k == 0 && nums[i] == nums[j]) {
                    ++res;
                }
            }
        }
        return res;
    }
};


/* Original Solution */
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> digits;
        int ans = 0;
       
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            digits[nums[i]].push_back(i);
        }
        
        for (auto [_, indexVec] : digits) {
            if (indexVec.size() == 1 ) {
                continue;
            }
            
            for (int i = 0; i < indexVec.size() - 1; i++) {
                for (int j = i + 1; j < indexVec.size(); j++) {
                    if ((indexVec[i] * indexVec[j]) % k == 0) {
                        ++ans;
                    }
                }
            }
        }
        
        return ans;
    }
};
