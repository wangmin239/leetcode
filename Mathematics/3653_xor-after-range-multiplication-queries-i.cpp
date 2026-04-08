/* Official Solution 1 */
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        const int mod = 1e9 + 7;

        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            int step = query[2];
            int value = query[3];

            for (int idx = left; idx <= right; idx += step) {
                nums[idx] = (1LL * nums[idx] * value) % mod;
            }
        }

        for (const int elem : nums) {
            ans ^= elem;
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
    static const int mod = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = 1ll * nums[i] * v % mod;
            }
        }
        int res = 0;
        for (auto x : nums) {
            res ^= x;
        }
        return res;
    }
};
