class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> cnt;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        int res = 0;
        for (string word : words) {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (cnt.count(prev)) {
                    cnt[word] = max(cnt[word], cnt[prev] + 1);
                }
            }
            res = max(res, cnt[word]);
        }
        return res;
    }
};

["ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"]

class Solution {
public:
    int longestStrChain(vector<string>& words) {
      int n = words.size();
      vector<int> dp(n, 1);
      
      sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
          return lhs.length() < rhs.length();
      });
      for (int i = 1; i < n; i++) {
          for (int j = 0; j < i; j++) {
            if (isPrefix(words[j], words[i]) == true) {
                dp[i] = max(dp[i], dp[j] + 1);
            } else {
                dp[i] = max(dp[i], dp[j]);
            }
          }
        }
        return dp[n - 1];
    }
    
    bool isPrefix(const string& pattern, const string& str) {
        int len = pattern.length();
        int strLen = str.length();
        
        if (strLen - len != 1) {
            return false;
        }
        
        int i;
        for (i = 0; i < len; i++) {
            if (pattern[i] != str[i]) {
                break;
            }
        }
        
        for (i = i + 1; i < strLen; i++) {
            if (str[i] != pattern[i - 1]) {
                return false;
            }
        }
        return true;
    }
};