/* Official Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return 0;
        }

        const int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++) {
            const int value = nums[(start + i) % n];

            if (value != i) {
                asc = false;
            }
            if (value != n - i) {
                desc = false;
            }

            if (!asc && !desc) {
                return -1;
            }
        }

        if (asc) {
            return min(start, n - start + 2);
        }

        return min(n - start, start + 2);
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int d = nums[1] - nums[0];
        if (abs(d) != 1) {
            d = nums[2] - nums[1];
            if (abs(d) != 1) { // 不能有多个跳变位置
                return -1;
            }
        }

        int p = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] != d) {
                // i 是跳变位置
                if (p > 0) { // 不能有多个跳变位置
                    return -1;
                }
                p = i;
            }
        }

        if (d == 1) {
            return min(p, n - p + 2); // 递增
        }
        return min(p, n - p) + 1; // 递减
    }
};
