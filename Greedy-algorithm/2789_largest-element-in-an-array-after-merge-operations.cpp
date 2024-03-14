class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            sum = nums[i] <= sum ? nums[i] + sum : nums[i];
        }
        return sum;
    }
};

。



class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int end = nums.size();
        int start = 0;
        vector<long long> ans(end);
        
        for (int i = 0; i < end; i++) {
            ans[i] = static_cast<long long>(nums[i]);
        }
        
        for (int i = end - 2; i >= 0; i--) {
            if (ans[i + 1] >= ans[i]) {
                ans[i] += ans[i + 1];
            }
        }
        
        return *max_element(ans.begin(), ans.end());
    }
};