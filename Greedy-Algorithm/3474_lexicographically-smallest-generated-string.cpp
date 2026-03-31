/* Official Solution 1 */
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, 'a');
        vector<int> fixed(n + m - 1, 0);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (fixed[j] && s[j] != str2[j - i]) {
                        return "";
                    } else {
                        s[j] = str2[j - i];
                        fixed[j] = 1;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool flag = false;
                int idx = -1;
                for (int j = i + m - 1; j >= i; j--) {
                    if (str2[j - i] != s[j]) {
                        flag = true;
                    }
                    if (idx == -1 && !fixed[j]) {
                        idx = j;
                    }
                }
                if (flag) {
                    continue;
                } else if (idx != -1) {
                    s[idx] = 'b';
                } else {
                    return "";
                }
            }
        }
        return s;
    }
};


/* Official Solution 2 */
class Solution {
    vector<int> calc_z(const string& s) {
        int n = s.size();
        vector<int> z(n);
        int box_l = 0, box_r = 0; // z-box 左右边界（闭区间）
        for (int i = 1; i < n; i++) {
            if (i <= box_r) {
                z[i] = min(z[i - box_l], box_r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                box_l = i;
                box_r = i + z[i];
                z[i]++;
            }
        }
        z[0] = n;
        return z;
    }

public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?');

        // 处理 T
        vector<int> z = calc_z(t);
        int pre = -m;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            int size = max(pre + m - i, 0);
            // t 的长为 size 的前后缀必须相同
            if (size > 0 && z[m - size] < size) {
                return "";
            }
            // size 后的内容都是 '?'，填入 t
            for (int j = size; j < m; j++) {
                ans[i + j] = t[j];
            }
            pre = i;
        }

        // 计算 <= i 的最近待定位置
        vector<int> pre_q(ans.size());
        pre = -1;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '?') {
                ans[i] = 'a'; // 待定位置的初始值为 a
                pre = i;
            }
            pre_q[i] = pre;
        }

        // 找 ans 中的等于 t 的位置，可以用 KMP 或者 Z 函数
        z = calc_z(t + ans);

        // 处理 F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // 子串必须不等于 t
            if (z[m + i] < m) {
                continue;
            }
            // 找最后一个待定位置
            int j = pre_q[i + m - 1];
            if (j < i) { // 没有
                return "";
            }
            ans[j] = 'b';
            i = j; // 直接跳到 j
        }

        return ans;
    }
};
