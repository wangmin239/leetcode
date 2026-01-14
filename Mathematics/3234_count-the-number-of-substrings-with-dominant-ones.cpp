/* Official Solution 1 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0';
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};


/* Official Solutio 2 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> pos0 = {-1}; // 加个 -1 哨兵，方便处理 cnt0 达到最大时的计数
        int total1 = 0; // [0,r] 中的 1 的个数
        int ans = 0;
        for (int r = 0; r < s.size(); r++) {
            if (s[r] == '0') {
                pos0.push_back(r); // 记录 0 的下标
            } else {
                total1++;
                ans += r - pos0.back(); // 单独计算不含 0 的子串个数
            }

            int m = pos0.size();
            // 倒着遍历 pos0，那么 cnt0 = m - i
            for (int i = m - 1; i > 0 && (m - i) * (m - i) <= total1; i--) {
                int p = pos0[i - 1], q = pos0[i];
                int cnt0 = m - i;
                int cnt1 = r - q + 1 - cnt0; // [q,r] 中的 1 的个数 = [q,r] 的长度 - cnt0
                ans += max(q - max(cnt0 * cnt0 - cnt1, 0) - p, 0);
            }
        }
        return ans;
    }
};
