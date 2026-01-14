class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        int sum = 0;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for (const auto val : nums) {
            if (sum > total) {
                break;
            }
            sum += val;
            total -= val;
            ans.push_back(val);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int curr = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            curr += nums[i];
            ans.emplace_back(nums[i]);
            if (total - curr < curr) {
                break;
            }
        }
        return ans;
    }
};
