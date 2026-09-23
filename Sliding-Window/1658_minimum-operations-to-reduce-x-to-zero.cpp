/* Official Solution 2 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = reduce(nums.begin(), nums.end()) - x;
        if (target < 0) {
            return -1; // 全部移除也无法满足要求
        }

        int ans = -1, left = 0, sum = 0, n = nums.size();
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++; // 缩小子数组长度
            }
            if (sum == target) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans < 0 ? -1 : n - ans;
    }
};




/* Official Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < x) {
            return -1;
        }

        int right = 0;
        int lsum = 0, rsum = sum;
        int ans = n + 1;

        for (int left = -1; left < n; ++left) {
            if (left != -1) {
                lsum += nums[left];
            }
            while (right < n && lsum + rsum > x) {
                rsum -= nums[right];
                ++right;
            }
            if (lsum + rsum == x) {
                ans = min(ans, (left + 1) + (n - right));
            }
        }

        return ans > n ? -1 : ans;
    }
};



/* Original Solution 3 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int maxRange = 0;
        int remain = accumulate(nums.begin(), nums.end(), 0) - x;
        int sum = 0;


        if (remain < 0) {
            return -1;
        }

        if (remain == 0) {
            return n;
        }

        for (int left = 0, right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > remain) {
                sum -= nums[left++];
            }

            if (sum == remain) {
                maxRange = max(maxRange, right - left + 1);
            }

        }

        return maxRange == 0 ? -1: n - maxRange;
    }
};



/* Original Solution 2, Accepted 97 / 97 testcases passed */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        vector<int> sufSum(n + 1, 0);

        unordered_map<int, int> preMap;
        unordered_map<int, int> sufMap;
        int minOpers = INT_MAX;

        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
            sufSum[n - i - 1] = sufSum[n - i] + nums[n - i - 1];


             preMap[preSum[i + 1]] = i + 1;
             sufMap[sufSum[n - i - 1]] = n - i - 1;
        }

        if (preSum.back() < x) {
            return -1;
        }

        if (preSum.back() == x) {
            return n;
        }

        for (int i = 0; i < n; i++) {
            int remain = x - preSum[i];

            if (sufMap.count(remain) > 0) {
                minOpers = min(minOpers, i + (n - sufMap[remain]));
            }

            remain = x - sufSum[n - i];

            if (preMap.count(remain) > 0) {
                minOpers = min(minOpers, i + preMap[remain]);
            }
        }


         return minOpers != INT_MAX ? minOpers : -1;
    }
};



/* Original Solution 1, Time Limit Exceeded 10 / 97 testcases passed */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        auto dfs = [&](int left, int right, int remain, int opers, auto&& self) {
            if (remain == 0) {
                return opers;
            }

            if (remain < 0 || left > right) {
                return INT_MAX;
            }

            int minOpers = self(left + 1, right, remain - nums[left], opers + 1, self);
            minOpers = min(minOpers, self(left, right - 1, remain - nums[right], opers + 1, self));

            return minOpers;
        };

         int minSteps = dfs(0, n - 1, x, 0, dfs);

         return minSteps != INT_MAX ? minSteps : -1;
    }
};