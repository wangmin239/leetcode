/* Official solution 1 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

/* Official solution 2 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (auto& num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};




/* Original Solution. failure. */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        /* The total is odd. */
        if (total & 0x1) {
            return false;
        }
        
        vector<int> suffix(n + 1, 0), prefix(n + 1, 0);
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        
        for (int left = 0, right = 1;  right <= n; ) {
            if (prefix[left] + suffix[right] > total / 2) {
                right++;
            } else if (prefix[left] + suffix[right] < total / 2) {
                left++;
            } else {
                return true;
            }
            
        }
        
        return false;
    }
};





/* Original Solution. Timeout. */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        /* The total is odd. */
        if (total & 0x1) {
            return false;
        }
        
        function<bool(int, int)> backTrace = [&](int idx, int sum) {
            if (idx == n) {
                return false;
            }
            
            if (sum == total / 2) {
                return true;
            }
            
            return backTrace(idx + 1, sum + nums[idx]) ||
                   backTrace(idx + 1, sum);
        };
        
        return backTrace(0, 0);
    }
};