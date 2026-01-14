/* Original Solution */
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> digits;
        
        /* calculating the total pairs */
        ans = 1LL * n * (n - 1) / 2;
        
        /* store the pairs which have the same value */
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            ++digits[diff];
        }
        /*subtract the goot pairs */
        for (auto [_, cnt] : digits) {
            long long pairs = 1LL * cnt * (cnt - 1) / 2;
            ans -= pairs;
        }
        
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    using ll = long long;
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        ll res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += i - mp[nums[i] - i];
            mp[nums[i] - i]++;
        }
        return res;
    }
};
 