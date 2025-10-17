/* Official Solution 1 */
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> memo;
        auto dfs = [&](this auto&& dfs, int i, int mask, bool changed) -> int {
            if (i == s.length()) {
                return 1;
            }

            // 把参数压缩到一个 long long 中，方便作为哈希表的 key
            long long args = (long long) i << 32 | mask << 1 | changed;
            auto it = memo.find(args);
            if (it != memo.end()) { // 之前计算过
                return it->second;
            }

            int res;
            // 不改 s[i]
            int bit = 1 << (s[i] - 'a');
            int new_mask = mask | bit;
            if (popcount((uint32_t) new_mask) > k) {
                // 分割出一个子串，这个子串的最后一个字母在 i-1
                // s[i] 作为下一段的第一个字母，也就是 bit 作为下一段的 mask 的初始值
                res = dfs(i + 1, bit, changed) + 1;
            } else { // 不分割
                res = dfs(i + 1, new_mask, changed);
            }

            if (!changed) {
                // 枚举把 s[i] 改成 a,b,c,...,z
                for (int j = 0; j < 26; j++) {
                    if (j == s[i[ - 'a') {
                        continue;
                    }
                    new_mask = mask | (1 << j);
                    if (popcount((uint32_t) new_mask) > k) {
                        // 分割出一个子串，这个子串的最后一个字母在 i-1
                        // j 作为下一段的第一个字母，也就是 1<<j 作为下一段的 mask 的初始值
                        res = max(res, dfs(i + 1, 1 << j, true) + 1);
                    } else { // 不分割
                        res = max(res, dfs(i + 1, new_mask, true));
                    }
                }
            }

            return memo[args] = res; // 记忆化
        };
        return dfs(0, 0, false);
    }
};



/* Official Solution 2 */
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        if (k == 26) {
            return 1;
        }

        int seg = 1, mask = 0, size = 0;
        auto update = [&](int i) -> void {
            int bit = 1 << (s[i] - 'a');
            if (mask & bit) {
                return;
            }
            if (++size > k) {
                seg++; // s[i] 在新的一段中
                mask = bit;
                size = 1;
            } else {
                mask |= bit;
            }
        };

        int n = s.length();
        vector<pair<int, int>> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            update(i);
            suf[i] = {seg, mask};
        }

        int ans = seg; // 不修改任何字母
        seg = 1; mask = 0; size = 0;
        for (int i = 0; i < n; i++) {
            auto [suf_seg, suf_mask] = suf[i + 1];
            int res = seg + suf_seg; // 情况 3
            int union_size = popcount((uint32_t) mask | suf_mask);
            if (union_size < k) {
                res--; // 情况 1
            } else if (union_size < 26 && size == k && popcount((uint32_t) suf_mask) == k) {
                res++; // 情况 2
            }
            ans = max(ans, res);
            update(i);
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.length();
        vector<vector<int>> left(n, vector<int>(3)), right(n, vector<int>(3));
        int num = 0, mask = 0, count = 0;
        for (int i = 0; i < n - 1; i++) {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary)) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0, mask = 0, count = 0;
        for (int i = n - 1; i > 0; i--) {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary)) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        int Max = 0;
        for (int i = 0; i < n; i++) {
            int seg = left[i][0] + right[i][0] + 2;
            int totMask = left[i][1] | right[i][1];
            int totCount = 0;
            while (totMask) {
                totMask = totMask & (totMask - 1);
                totCount++;
            }
            if (left[i][2] == k && right[i][2] == k && totCount < 26) {
                seg++;
            } else if (min(totCount + 1, 26) <= k) {
                seg--;
            }
            Max = max(Max, seg);
        }
        return Max;
    }
};
