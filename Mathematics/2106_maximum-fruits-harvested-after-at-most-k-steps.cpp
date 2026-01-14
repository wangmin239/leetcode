class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* 向左走 x 步，再向右走 k - x 步 */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
            int end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, sum[end] - sum[start]);
            /* 向右走 x 步，再向左走 k - x 步 */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
            end = upper_bound(indices.begin(), indices.end(), right) - indices.begin();
            ans = max(ans, sum[end] - sum[start]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;

        auto step = [&](int left, int right) -> int {
            if (fruits[right][0] <= startPos) {
                return startPos - fruits[left][0];
            } else if (fruits[left][0] >= startPos) {
                return fruits[right][0] - startPos;
            } else {
                return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) + \
                       fruits[right][0] - fruits[left][0];
            }
        };
        // 每次固定住窗口右边界
        while (right < n) {
            sum += fruits[right][1];
            // 移动左边界
            while (left <= right && step(left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};
