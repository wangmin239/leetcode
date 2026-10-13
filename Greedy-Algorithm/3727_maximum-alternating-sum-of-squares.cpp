/* Original Solution 1 */
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        for (int left = 0, right = n - 1; left < right; ++left, --right) {
            sum += 1LL * nums[left] * nums[left];
            sum -= 1LL * nums[right] * nums[right];
        }

        if (n & 0x1) {
            sum += 1LL * nums[n / 2] * nums[n / 2];
        }

        return sum;
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            num *= num;
        }
        ranges::sort(nums);
        return -accumulate(nums.begin(), nums.begin() + n / 2, 0LL) +
               accumulate(nums.begin() + n / 2, nums.end(), 0LL);
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& x : nums) {
            x *= x;
        }
        int m = nums.size() / 2;
        ranges::nth_element(nums, nums.begin() + m);

        // 交替和：减去小的，加上大的
        return -accumulate(nums.begin(), nums.begin() + m, 0LL)
               +accumulate(nums.begin() + m, nums.end(), 0LL);
    }
};
