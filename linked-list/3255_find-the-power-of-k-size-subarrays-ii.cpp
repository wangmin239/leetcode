class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            cnt = (i == 0 || nums[i] - nums[i - 1] != 1) ? 1 : ++cnt;
            if (cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        
        for (int left = 0, right = 0; right < n; right++) {
            bool isContinuousIncr = true;
            /* check that the sub array is continuousincreasing */
            while (right - left < k) {
                if (nums[right] - nums[left] != right - left) {
                    isContinuousIncr = false;
                    break;
                }
                ++right;
            }
            /* meet the requirements */
            if (isContinuousIncr == true) {
                ans[left++] = nums[--right];
            } else {
                while (left < right && left < n - k + 1) {
                    ++left;
                }
            }
        }
        return ans;
    }
};
