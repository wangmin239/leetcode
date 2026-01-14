
/* Original Solution 3 */
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> suffixMax(n);
        vector<int> prefixMax(n);
        
        prefixMax[0] = nums[0];
        suffixMax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            suffixMax[n - i - 1] = max(suffixMax[n - i], nums[n -i - 1]);
        }
        
        
        for (int j = 1; j < n - 1; j++) {
            if (prefixMax[j - 1] > nums[j]) {
                ans = max(ans,  (0LL + prefixMax[j - 1] - nums[j]) * suffixMax[j + 1]);
            }
        }
        
        return ans;
    }
};


/* Original Solution 2 */
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long diff = 0;
        int n = nums.size();
        vector<int> suffixMax(n);
        
        suffixMax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            suffixMax[n - i - 1] = max(suffixMax[n - i], nums[n -i - 1]);
        }
        
        
        for (int left = 0, right = 1; right < n - 1; right++) {
            if (nums[left] >= nums[right]) {
                diff = max(diff, 0LL + nums[left] - nums[right]);
                ans = max(ans, diff * suffixMax[right + 1]);
            } else {
                left = right;
            }
        }
        return ans;
    }
};




/* Original Solution 1 */
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long diff = 0;
        int n = nums.size();
        
        for (int left = 0, right = 1; right < n - 1; right++) {
            if (nums[left] >= nums[right]) {
                diff = max(diff, 0LL + nums[left] - nums[right]);
                int maxMul = *max_element(nums.begin() + right + 1, nums.end());
                ans = max(ans, diff * maxMul);
            } else {
                left = right;
            }
        }
        return ans;
    }
};