/* Original Solution 1 */
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0;
        int n = nums.size();

        for (int& num : nums) {
            num %= p;
            remainder = (remainder + num) % p;
        }

        if (remainder == 0) {
            return 0;
        }


        int ans = n;

        for (int k = 0; k < 20; k++) {
            long long multplex = 1LL * k * p;
            int left, right;
            long long sum = 0;
            for (left = 0, right = 0; right < n; right++) {
                sum += nums[right];

                while (sum > multplex + remainder) {
                    sum -= nums[left++];
                }

                if (sum % p == remainder) {
                    while (nums[left] == 0) {
                        ++left;
                    }
                    ans = min(ans, right - left + 1);
                }
            }

            while (left < n) {
                sum -= nums[left++];
                if (sum % p == remainder) {
                    ans = min(ans, n - left);
                }
            }
        }

        return ans != n ? ans : -1;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num : nums) {
            x = (x + num) % p;
        }
        if (x == 0) {
            return 0;
        }
        unordered_map<int, int> index;
        int y = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            index[y] = i; // f[i] mod p = y，因此哈希表记录 y 对应的下标为 i
            y = (y + nums[i]) % p;
            if (index.count((y - x + p) % p) > 0) {
                res = min(res, i - index[(y - x + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};
