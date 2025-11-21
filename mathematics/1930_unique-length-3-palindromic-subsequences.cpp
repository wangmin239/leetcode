/* Original Solution 1 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
      int n = s.length();
      const int chNum = 26;
      vector<int> startIndexs(chNum, -1);
      vector<int> endIndexs(chNum, -1);
      
      for (int i = 0; i < n; i++) {
          int  startId = s[i] - 'a';
          int endId = s[n - 1 -i] - 'a';
          
          if (startIndexs[startId] == -1) {
              startIndexs[startId] = i;
          }
          
          if (endIndexs[endId] == -1) {
              endIndexs[endId] = n - 1 - i;
          }
      }
      
      int sum = 0;
      
      for (int i = 0; i < chNum; i++) {
          int left = startIndexs[i];
          int right = endIndexs[i];
          
          if (left == -1 || right - left < 2) {
              continue;
          }
          
          unsigned int chMask = 0;
          for (int i = left + 1; i < right; i++) {
              chMask |= (1 << (s[i] - 'a'));
          }
          sum += popcount(chMask);
      }
      
      return sum;
    }
};


/* Official Solution  1 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int res = 0;
        // 前缀/后缀字符状态数组
        vector<int> pre(n), suf(n);
        for (int i = 0; i < n; ++i) {
            // 前缀 s[0..i-1] 包含的字符种类
            pre[i] = (i ? pre[i - 1] : 0) | (1 << (s[i] - 'a'));
        }
        for (int i = n - 1; i >= 0; --i) {
            // 后缀 s[i+1..n-1] 包含的字符种类
            suf[i] = (i != n - 1 ? suf[i + 1] : 0) | (1 << (s[i] - 'a'));
        }
        // 每种中间字符的回文子序列状态数组
        vector<int> ans(26);
        for (int i = 1; i < n - 1; ++i) {
            ans[s[i]-'a'] |= (pre[i - 1] & suf[i + 1]);
        }
        // 更新答案
        for (int i = 0; i < 26; ++i) {
            res += __builtin_popcount(ans[i]);
        }
        return res;
    }
};

/* Official Solution  2 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char alpha = 'a'; alpha <= 'z'; alpha++) { // 枚举两侧字母 alpha
            int i = s.find(alpha); // 最左边的 alpha 的下标
            if (i == string::npos) { // s 中没有 alpha
                continue;
            }
            int j = s.rfind(alpha); // 最右边的 alpha 的下标

            bool has[26]{};
            for (int k = i + 1; k < j; k++) { // 枚举中间字母 s[k]
                if (!has[s[k] - 'a']) {
                    has[s[k] - 'a'] = true; // 避免重复统计
                    ans++;
                }
            }
        }
        return ans;
    }
};

/* Official Solution  3 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        // 统计 [1,n-1] 每个字母的个数
        int suf_cnt[26]{};
        for (int i = 1; i < n; i++) {
            suf_cnt[s[i] - 'a']++;
        }

        bool pre_has[26]{};
        bool has[26][26]{};
        int ans = 0;
        for (int i = 1; i < n - 1; i++) { // 枚举中间字母 mid
            int mid = s[i] - 'a';
            suf_cnt[mid]--; // 撤销 mid 的计数，suf_cnt 剩下的就是后缀 [i+1,n-1] 每个字母的个数
            pre_has[s[i - 1] - 'a'] = true; // 记录前缀 [0,i-1] 有哪些字母
            for (int alpha = 0; alpha < 26; alpha++) { // 枚举两侧字母 alpha
                // 判断 mid 的左右两侧是否都有字母 alpha
                if (pre_has[alpha] && suf_cnt[alpha] && !has[mid][alpha]) {
                    has[mid][alpha] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};



/* Official Solution 4 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        // 统计 [1,n-1] 每个字母的个数
        int suf_cnt[26]{};
        int suf = 0;
        for (int i = 1; i < n; i++) {
            int ch = s[i] - 'a';
            suf_cnt[ch]++;
            suf |= 1 << ch; // 把 ch 记录到二进制数 suf 中，表示后缀有 ch
        }

        int pre = 0;
        int has[26]{}; // has[mid] = 由 alpha 组成的二进制数
        for (int i = 1; i < n - 1; i++) { // 枚举中间字母 mid
            int mid = s[i] - 'a';
            suf_cnt[mid]--; // 撤销 mid 的计数，suf_cnt 剩下的就是后缀 [i+1,n-1] 每个字母的个数
            if (suf_cnt[mid] == 0) { // 后缀 [i+1,n-1] 不包含 mid
                suf ^= 1 << mid; // 从 suf 中去掉 mid
            }
            pre |= 1 << (s[i - 1] - 'a'); // 把 s[i-1] 记录到二进制数 pre 中，表示前缀有 s[i-1]
            has[mid] |= pre & suf; // 计算 pre 和 suf 的交集，|= 表示把交集中的字母加到 has[mid] 中
        }

        int ans = 0;
        for (int mask : has) {
            ans += popcount((uint32_t) mask); // mask 中的每个 1 对应着一个 alpha
        }
        return ans;
    }
};

