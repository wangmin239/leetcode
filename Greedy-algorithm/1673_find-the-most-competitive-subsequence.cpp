class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!res.empty() && n - i + res.size() > k && res.back() > nums[i]) {
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};



class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans(k);
        int offset = 0;
        int n = nums.size();
        auto curIter = nums.begin();

        for (int i = 0; i < k; i++) {
            auto iter = min_element(nums.begin() + offset, nums.end());
            offset = iter - nums.begin();
            if (n - offset > k - i) {
                ans[i] = *iter;
            }
            
            if (remain > k -
            if (n - offset > k - i) {
                curIter = min_element(nums.begin() + offset, nums.end());
                offset = iter - nums.begin() + 1;
                ans[i] = *iter;
            } else if (n - offset == k - i) {
                while (i < k) {
                    ans[i++] = nums[offset++];
                }
            } else {
                break;
            }
        }
        
        return ans;
    }
};