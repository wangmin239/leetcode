/* Original Solution 1 */
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        auto check = [&](int start, int end) {
            int prod = nums[start];
            int gcdVal = nums[start];
            int lcmVal = nums[start];

            while (++start < end) {
                gcdVal = gcd(gcdVal, nums[start]);
                lcmVal = lcm(lcmVal, nums[start]);
                prod *= nums[start];
                if (prod > gcdVal * lcmVal) {
                    return false;
                }
            }

            return prod == lcmVal * gcdVal;
        };

        for (int left = 0; left < n; left++) {
            for (int right = n; right > left; right--) {
                if (check(left, right) == true) {
                    ans = max(right - left, ans);
                }
            }
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 2;
        int prodVal = 1;
        int n = nums.size();
        int start = 0, end = 0;
        
        while (end < n) {
            while (gcd(prodVal, nums[end]) > 1) {
                prodVal /= nums[start];
                start++;
            }
            prodVal *= nums[end];
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};
