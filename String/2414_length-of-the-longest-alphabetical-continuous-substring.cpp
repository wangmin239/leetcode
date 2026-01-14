class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) {
                cur++;
            } else {
                cur = 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};


class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = s.length();
        int maxLen = 0;
        int left, right;

        for (left = 0, right = 0; right < len; ++right) {
            if (s[right] - s[left] != right - left) {
                maxLen = max(maxLen, right - left);
                left = right;
            } 
        }
        
        return max(maxLen, right - left);
    }
};




class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len = s.length();
        int maxLen = 0;
        int curLen = 0;

        for (int left = 0, right = 0; right < len; ++right) {
            if (s[right] - s[left] == right - left) {
                ++curLen;
            } else {
                maxLen = max(maxLen, curLen);
                left = right;
                curLen = 1;
            }
        }
        
        return max(maxLen, curLen);
    }
};