class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int k = 0; k <= n; k++) {
            // 前 k 个元素的最大值是否小于 k
            if (k > 0 && nums[k - 1] >= k) {
                continue;
            }
            // 后 n - k 个元素的最小值是否大于 k
            if (k < n && nums[k] <= k) {
                continue;
            }
            res++;
        }
        return res;            
    }
};
