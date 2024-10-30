class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] > s[i + 1] && s[i] % 2 == s[i + 1] % 2) {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};


class Solution {
public:
    string getSmallestString(string s) {
       int len = s.length();

       for (int i = 1; i < len; i++) {
            int first = s[i - 1] - '0';
            int second = s[i] - '0';
            
            if (first <= second) {
                continue;
            }
            
            if (((first & 0x1) ^ (second & 0x1)) == 0) {
                swap(s[i - 1], s[i]);
                break;
            }
       }
       
       return s;
    }
};