/* Original Solution 1 */
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n + 1, 0);

        
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        
        long long ans = preSum[k];

        for (int i = 0; i < k; i++) {
            for (int left = i; left < n + 1 - k; left += k) {
                for (int right = left + k; right < n + 1; right += k) {
                    ans = max(ans, preSum[right] - preSum[left]);
                }
            }
        }
        
        return ans;
    }
};

/* Original Solution 2 */
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n + 1, 0);

        
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        
        long long ans = preSum[k];

        for (int i = 0; i < k; i++) {
            for (int left = i; left < n + 1 - k; left += k) {
                for (int right = left + k; right < n + 1; right += k) {
                    ans = max(ans, preSum[right] - preSum[left]);
                }
            }
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        vector<long long> min_s(k, LLONG_MAX / 2); // 防止下面减法溢出
        long long ans = LLONG_MIN;
        for (int j = 0; j < sum.size(); j++) {
            int i = j % k;
            ans = max(ans, sum[j] - min_s[i]);
            min_s[i] = min(min_s[i], sum[j]);
        }
        return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n + 1, 0);

        
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        
        long long ans = preSum[k];
        
        for (int i = 0; i < n + 1 - k; i++) {
            for (int j = i + k; j < n + 1; j += k) {
                ans = max(ans, preSum[j] - preSum[i]);
            }
        }
        
        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0, maxSum = LONG_LONG_MIN;
        vector<long long> kSum(k, LONG_LONG_MAX / 2);
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
};




/* Official Solution 4 */
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0LL;
        long long maxSum = 0LL;
        vector<long long> kSum(k);

        for (int i = 0; i < k; i++) {
            prefixSum += nums[i];
            kSum[i] = prefixSum;
        }
        
        kSum[k - 1] = maxSum > 0 ? 0: maxSum;
        maxSum = prefixSum;
        
        for (int i = k ; i < n; i++) {
            prefixSum += nums[i];
            int  = i % k;
            maxSum = max(maxSum, prefixSum - kSum[j]);
            kSum[j] = min(kSum[j], prefixSum);
        }
        return maxSum;
    }
};

