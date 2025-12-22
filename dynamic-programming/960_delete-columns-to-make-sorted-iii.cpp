/* Official Solution 1 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) { 
        // 对于每一行，j 列的字母都 <= i 列的字母？
        auto less_eq = [&](int j, int i) -> bool {
            for (auto& s : strs) {
                if (s[j] > s[i]) {
                    return false;
                }
            }
            return true;
        };

        int m = strs[0].size();
        vector<int> f(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                // 如果 f[j] <= f[i]，就不用跑 O(n) 的 less_eq 了
                if (f[j] > f[i] && less_eq(j, i)) {
                    f[i] = f[j];
                }
            }
            f[i]++;
        }
        return m - ranges::max(f);
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // 边界条件：空数组或字符串长度为0，无需删除
        if (strs.empty() || strs[0].size() == 0) {
            return 0;
        }

        int n = strs.size();       // 字符串的行数
        int m = strs[0].size();    // 每个字符串的列数（总列数）
        vector<int> dp(m, 1);      // dp[j]表示以第j列为最后保留列的最长序列长度

        // 遍历每一列j（作为当前最后保留列）
        for (int j = 1; j < m; ++j) {
            // 遍历所有i < j的列，判断是否能接在i后面
            for (int i = 0; i < j; ++i) {
                // 检查所有行，判断i列是否可以接在j列前面（所有行的i列≤j列）
                bool valid = true;
                for (int row = 0; row < n; ++row) {
                    if (strs[row][i] > strs[row][j]) {
                        valid = false;
                        break; // 只要有一行不满足，i就不能接在j前面
                    }
                }
                // 若有效，更新dp[j]的最大值
                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        // 找到最长的保留列序列长度
        int max_keep = *max_element(dp.begin(), dp.end());
        // 最少删除列数 = 总列数 - 最长保留列数
        return m - max_keep;
    }
};

