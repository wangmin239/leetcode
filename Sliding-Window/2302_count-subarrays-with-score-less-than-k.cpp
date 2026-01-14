
/* Original Solution 1 */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        unique_ptr<long long[]> preSum(new long long [n + 1] {0});
        
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        
        long long cnt = 0;
        for (int left = 0, right = 0; right < n; right++) {
            while (left <= right && 1LL * (right - left + 1) * (preSum[right + 1] - preSum[left]) >= k) {
                ++left;
            }
            cnt +=  right - left + 1;
        }
        
        return cnt;
    }
};


/* Official Solution */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};



/* Original Solution 2 */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0;
        long long cnt = 0;

        for (int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            while (left <= right && 1LL * (right - left + 1) * sum >= k) {
                sum -= nums[left];
                ++left;
            }
            cnt +=  right - left + 1;
        }
        
        return cnt;
    }
};