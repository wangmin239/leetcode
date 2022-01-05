class Solution {
public:
    string modifyString(string s) {
        int len = s.length();
        int left, right;

        
        for (int i = 0; i < len;) {
            if (s[i] != '?') {
                ++i;
                continue;
            }
            
            right = i;   
            while (right < len && s[right] == '?') {
                ++right;
            }

            int ch;
            left = i;
            
            if (left == 0) {
                ch = 'a' - 1;
            } else {
                ch = s[left - 1];
            }
            
            while (left < right) {
                s[left++] = ((++ch) - 'a') % 26 + 'a';
            }
            
            if (right < len && s[right] == s[right - 1]) {
                s[right - 1] = (s[right] - 'a' + 1) % 26 + 'a';
            }
            
            i = right;
        }    
        return s;
    }
};


class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'c'; ++ch) {
                    if ((i > 0 && s[i - 1] == ch) || (i < n - 1 && s[i + 1] == ch)) {
                        continue;
                    }
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
