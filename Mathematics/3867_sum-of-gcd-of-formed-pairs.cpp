/* Original Solution 1 */
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxNum = 0;
        long long sum = 0LL;

        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxNum);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
        }

        return sum;

    }
};

/* Official Solution 1 */
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx;
        int prefixMax = INT_MIN;

        for (int x : nums) {
            prefixMax = max(prefixMax, x);
            mx.push_back(prefixMax);
        }

        vector<int> prefixGcd;
        for (int i = 0; i < n; ++i) {
            prefixGcd.push_back(gcd(nums[i], mx[i]));
        }

        ranges::sort(prefixGcd);

        long long ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            ++left;
            --right;
        }

        return ans;
    }
};
