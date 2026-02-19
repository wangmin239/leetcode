/* Original Solution 1 */
class Solution {
public:
    int countBinarySubstrings(string s) {
      int len = s.length();
      int ans = 0;
      int prevNum = 0;
      int curNum = 0;
      int left = 0, right = 0;
      
      while (right < len) {
          if (s[left] == s[right]) {
              ++right;
              continue;
          }

          curNum = right - left;
          ans += min(prevNum, curNum);
          prevNum = curNum;
          left = right;
      }
      return ans + min(prevNum, right - left);
    }
};




/* Original Solution 1 */
class Solution {
public:
    int countBinarySubstrings(string s) {
      int len = s.length();
      int ans = 0;
      int prevNum = 0;
      int curNum = 0;

      for (int left = 0, right = 0; right < len; left = right) {
          while (right < len && s[left] == s[right]) {
              ++right;
          }

          curNum = right - left;
          ans += min(prevNum, curNum);
          prevNum = curNum;
      }
      return ans;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ptr = 0, n = s.size();
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for (int i = 1; i < counts.size(); ++i) {
            ans += min(counts[i], counts[i - 1]);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};
