/* Original Solution */
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> digits;
        long long  cnt = 0;
        int n = nums.size();
        int pairs = 0;
        
        for (int left = 0, right = 0; right < n; right++) {
            /* the num existed in the previous, add the increament */
            if (digits.count(nums[right])) {
                pairs += digits[nums[right]];
            }
            /* increase the counter of every num */
            ++digits[nums[right]];
            
            if (pairs < k) {
                continue;
            }
            
            /* add the suffix subarray */
            while (pairs >= k) {
                --digits[nums[left]];
                pairs -= digits[nums[left]];
                cnt += n - right;
                ++left;
            }
        }
        
        return cnt;
    }
};

/* Official Solution */
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt[nums[right]];
                ++cnt[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --cnt[nums[left]];
            same -= cnt[nums[left]];
        }
        return ans;
    }
};
