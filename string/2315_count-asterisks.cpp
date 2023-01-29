class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0, e = 1;
        for(char c: s) ans += ((e ^= (c=='|')) && c=='*');
        return ans;
    }
};


class Solution {
public:
    int countAsterisks(string s) {
        bool valid = true;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '|') {
                valid = !valid;
            } else if (c == '*' && valid) {
                res++;
            }
        }
        return res;
    }
};


class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        bool isPair = true;

        for (char ch : s) {
            if (isPair == true) {
                if (ch == '*') {
                    cnt++;
                }
                
                if (ch == '|') {
                    isPair = false;
                    continue;
                }
            }
            
            if (ch == '|') {
                isPair = true;
            }
        }
        
        return cnt;
        
    }
};