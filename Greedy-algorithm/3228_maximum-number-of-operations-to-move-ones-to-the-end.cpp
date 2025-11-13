/* Original Solution 1 */
class Solution {
public:
    int maxOperations(string s) {
      int n = s.length();
      int ops = 0;
      int oneCnt = 0;

      for (int i = 0; i < n - 1; i++) {
          if (s[i] == '0') {
              continue;
          }
          /* Get the count of consecutive '1's in a partition */
          while (i < n - 1 && s[i] == '1') {
              ++oneCnt;
              ++i;
          }
          
          if (s[i] == '0') {
              ops += oneCnt;
          }
      }
      
      return ops;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxOperations(string s) {
        int countOne = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                while ((i + 1) < s.length() && s[i + 1] == '0') {
                    i++;
                }
                ans += countOne;
            } else {
                countOne++;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cnt1++;
            } else if (i > 0 && s[i - 1] == '1') {
                ans += cnt1;
            }
        }
        return ans;
    }
};
