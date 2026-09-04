/* Original Solution 1 */
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n, nums.back());
        int preMax = INT_MIN;

        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            preMax = max(preMax, nums[i]);

            if (preMax - suffixMin[i] <= k) {
                return i;
            }

        }

        return -1;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int maxValue = nums[i], minValue = nums[i];
            for (int j = 0; j < i; ++j) {
                maxValue = max(maxValue, nums[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                minValue = min(minValue, nums[j]);
            }
            if (maxValue - minValue <= k) {
                return i;
            }
        }
        return -1;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf_min(n); // 后缀最小值
        suf_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf_min[i] = min(suf_min[i + 1], nums[i]);
        }

        int pre_max = 0; // 前缀最大值
        for (int i = 0; i < n; i++) {
            pre_max = max(pre_max, nums[i]);
            if (pre_max - suf_min[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
