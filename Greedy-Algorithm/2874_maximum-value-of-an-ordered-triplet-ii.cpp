/* Official Solution 1 */
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int maxDiff = 0;
        int maxPrefix = 0;
        
        for (int num : nums) {
            ans = max(ans, 1LL * maxDiff * num);
            maxDiff = max(maxDiff, maxPrefix - num);
            maxPrefix = max(maxPrefix, num);
        }

        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMax(n + 1);
        long long ans = 0;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            suffixMax[n - i - 1] = max(suffixMax[n - i], nums[n - i - 1]);
        }
        
        for (int left = 0, right = 1; right < n - 1; right++) {
            if (nums[left] > nums[right]) {
                maxDiff = max(nums[left] - nums[right], maxDiff);
                ans = max(ans, 1LL * maxDiff * suffixMax[right + 1]);
            } else {
                left = right;
            }  
        }
        
        return ans;
    }
};


/* Original Solution 3 */
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        }
        long long res = 0;
        for (int j = 1; j < n - 1; j++) {
            res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
};
