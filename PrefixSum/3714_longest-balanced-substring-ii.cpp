/* Official Solution 1 */
class Solution {
    int case2Helper(string &s, char x, char y) {
        int n = s.size();
        int res = 0;
        unordered_map<int, int> h;
        for (int i = 0; i < n; i++) {
            if (s[i] != x && s[i] != y) {
                continue;
            }
            
            h.clear();
            // 分割后的子串开头，两种字符出现次数之差为 0，需要提前存放至哈希表中
            h[0] = i - 1;
            int diff = 0;
            while (i < n && (s[i] == x || s[i] == y)) {
                diff += (s[i] == x) ? 1 : -1;
                if (h.contains(diff)) {
                    res = max(res, i - h[diff]);
                } else {
                    h[diff] = i;
                }
                i++;
            }
        }
        return res;
    }
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        // 情况一，仅包括一种字符
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                last++;
            } else {
                last = 1;
            }
            res = max(res, last);
        }

        // 情况二，包含两种字符
        res = max(res, case2Helper(s, 'a', 'b'));
        res = max(res, case2Helper(s, 'b', 'c'));
        res = max(res, case2Helper(s, 'a', 'c'));
        
        // 情况三，包含三种字符

        // 将二元组压缩成长整型，方便作为键值存放至哈希表
        // 由于前缀和之差存在负数，所以统一增加 n
        auto getId = [&](int x, int y) -> long long {
            return 1ll * (x + n) << 32 | (y + n);
        };

        // 字符串开头，位置为 -1 的地方，键值为 getId(0, 0)
        unordered_map<long long, int> h = {{getId(0, 0), -1}};
        int pre[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            pre[s[i] - 'a']++;
            long long id = getId(pre[1] - pre[0], pre[1] - pre[2]);
            if (h.contains(id)) {
                res = max(res, i - h[id]);
            } else {
                h[id] = i;
            }
        }
        return res;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        
        // 一种字母
        for (int i = 0; i < n;) {
            int start = i;
            for (i++; i < n && s[i] == s[i - 1]; i++);
            ans = max(ans, i - start);
        }

        // 两种字母
        auto f = [&](char x, char y) -> void {
            for (int i = 0; i < n; i++) {
                unordered_map<int, int> pos = {{0, i - 1}}; // 前缀和数组的首项是 0，位置相当于在 i-1
                int d = 0; // x 的个数减去 y 的个数
                for (; i < n && (s[i] == x || s[i] == y); i++) {
                    d += s[i] == x ? 1 : -1;
                    if (pos.contains(d)) {
                        ans = max(ans, i - pos[d]);
                    } else {
                        pos[d] = i;
                    }
                }
            }
        };
        f('a', 'b');
        f('a', 'c');
        f('b', 'c');

        // 三种字母
        // 把 (x, y) 压缩成一个 long long，方便保存至哈希表
        // (x, y) 变成 (x + n) << 32 | (y + n)，其中 +n 避免出现负数
        unordered_map<long long, int> pos = {{1LL * n << 32 | n, -1}}; // 前缀和数组的首项是 0，位置相当于在 -1
        int cnt[3]{};
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            long long p = 1LL * (cnt[0] - cnt[1] + n) << 32 | (cnt[1] - cnt[2] + n);
            if (pos.contains(p)) {
                ans = max(ans, i - pos[p]);
            } else {
                pos[p] = i;
            }
        }
        return ans;
    }
};
