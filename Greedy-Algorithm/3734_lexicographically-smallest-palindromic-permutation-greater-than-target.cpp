/* Official Solution 1 */
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        // 特殊情况：长度为1
        if (n == 1) {
            return s > target ? s : "";
        }
        
        // 统计每个字符的出现次数
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        // 检查是否能构成回文串，并记录奇数个的字符
        string oddChar = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                // 超过一个字符出现奇数次，无法构成回文
                if (oddChar != "") {
                    return "";
                }
                oddChar = string(1, 'a' + i);
            }
            cnt[i] /= 2;  // 只需要一半的字符来构造左半部分
        }
        
        string prefix = "";
        
        auto check = [&](char c) -> bool {
            string left = prefix;
            left.push_back(c);
            for (int i = 25; i >= 0; i--) {
                left.append(cnt[i], 'a' + i);
            }
            
            string palindrome = left + oddChar;
            string reversed_left = left;
            reverse(reversed_left.begin(), reversed_left.end());
            palindrome += reversed_left;
            
            return palindrome > target;
        };
        
        // 贪心构造左半部分的每一位
        for (int i = 0; i < n / 2; i++) {
            bool found = false;
            // 尝试放置字典序最小的字符
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }
                
                cnt[j]--;
                if (check('a' + j)) {
                    // 如果构造的回文串大于target，则选择该字符
                    prefix.push_back('a' + j);
                    found = true;
                    break;
                } else {
                    cnt[j]++;  // 不满足条件，恢复计数
                }
            }
            if (!found) {
                return "";  // 无法构造出大于target的回文串
            }
            
            if (prefix[i] > target[i]) {  // prefix已经大于target
                string left = prefix;
                for (int j = 0; j < 26; j++) {
                    left.append(cnt[j], 'a' + j);
                }
                string palindrome = left + oddChar;
                string reversed_left = left;
                reverse(reversed_left.begin(), reversed_left.end());
                palindrome += reversed_left;
                return palindrome;
            }
        }
        
        // 构造最终的回文串
        string ans = prefix + oddChar;
        string reversed_prefix = prefix;
        reverse(reversed_prefix.begin(), reversed_prefix.end());
        ans += reversed_prefix;
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int left[26]{};
        for (char b : s) {
            left[b - 'a']++;
        }
        auto valid = [&]() -> bool {
            for (int c : left) {
                if (c < 0) {
                    return false;
                }
            }
            return true;
        };

        string mid_ch;
        for (int i = 0; i < 26; i++) {
            int c = left[i];
            if (c % 2 == 0) {
                continue;
            }
            // s 不能有超过一个字母出现奇数次
            if (!mid_ch.empty()) {
                return "";
            }
            // 记录填在正中间的字母
            mid_ch = 'a' + i;
            left[i]--;
        }

        int n = s.size();
        // 先假设答案左半与 t 的左半（不含正中间）相同
        for (int i = 0; i < n / 2; i++) {
            left[target[i] - 'a'] -= 2;
        }

        if (valid()) {
            // 特殊情况：把 target 左半翻转到右半，能否比 target 大？
            string right_s = target.substr(0, n / 2);
            ranges::reverse(right_s);
            right_s = mid_ch + right_s;
            if (right_s > target.substr(n / 2)) { // 由于左半是一样的，所以只需比右半
                return target.substr(0, n / 2) + right_s;
            }
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            left[b] += 2; // 撤销消耗
            if (!valid()) { // [0,i-1] 无法做到全部一样
                continue;
            }

            // 把 target[i] 增大到 j
            for (int j = b + 1; j < 26; j++) {
                if (left[j] == 0) {
                    continue;
                }

                // 找到答案（下面的循环在整个算法中只会跑一次）
                left[j] -= 2;
                target.resize(i + 1);
                target[i] = 'a' + j;
    
                // 中间的空位可以随便填
                for (int k = 0; k < 26; k++) {
                    target += string(left[k] / 2, 'a' + k);
                }
    
                // 镜像翻转
                string right_s = target;
                ranges::reverse(right_s);
                target += mid_ch;
                target += right_s;
    
                return target;
            }
            // 增大失败，继续枚举
        }
        return "";
    }
};


/* Official Solution 3 */
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int left[26]{};
        for (char b : s) {
            left[b - 'a']++;
        }

        string mid_ch;
        for (int i = 0; i < 26; i++) {
            int c = left[i];
            if (c % 2 == 0) {
                continue;
            }
            // s 不能有超过一个字母出现奇数次
            if (!mid_ch.empty()) {
                return "";
            }
            // 记录填在正中间的字母
            mid_ch = 'a' + i;
            left[i]--;
        }

        int n = s.size();
        // 先假设答案左半与 t 的左半（不含正中间）相同
        for (int i = 0; i < n / 2; i++) {
            left[target[i] - 'a'] -= 2;
        }

        int neg = 0, left_max = 0;
        for (int i = 0; i < 26; i++) {
            if (left[i] < 0) {
                neg++; // 统计 left 中的负数个数
            } else if (left[i] > 0) {
                left_max = max(left_max, i); // 剩余可用字母的最大值
            }
        }

        if (neg == 0) {
            // 特殊情况：把 target 左半翻转到右半，能否比 target 大？
            string right_s = target.substr(0, n / 2);
            ranges::reverse(right_s);
            right_s = mid_ch + right_s;
            if (right_s > target.substr(n / 2)) { // 由于左半是一样的，所以只需比右半
                return target.substr(0, n / 2) + right_s;
            }
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            left[b] += 2; // 撤销消耗

            if (left[b] == 0) {
                neg--;
            } else if (left[b] == 2) {
                left_max = max(left_max, b);
            }

            // left 有负数 or 没有大于 target[i] 的字母
            if (neg > 0 || left_max <= b) {
                continue;
            }

            // 找到答案（下面的循环在整个算法中只会跑一次）
            int j = b + 1;
            while (left[j] == 0) {
                j++;
            }

            // 把 target[i] 增大到 j
            left[j] -= 2;
            target.resize(i + 1);
            target[i] = 'a' + j;

            // 中间的空位可以随便填
            for (int k = 0; k < 26; k++) {
                target += string(left[k] / 2, 'a' + k);
            }

            // 镜像翻转
            string right_s = target;
            ranges::reverse(right_s);
            target += mid_ch;
            target += right_s;

            return target;
        }
        return "";
    }
};
