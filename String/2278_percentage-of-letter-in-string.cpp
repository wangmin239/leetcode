/* Original Solution */
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int len = s.length();
        int cnt = 0;
        
        for (char ch : s) {
            cnt += static_cast<int>(ch == letter);
        }
        
        return cnt * 100 / len;
    }
};

/* Official Solution */
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = 0;
        for (char ch: s) {
            if (ch == letter) {
                ++cnt;
            }
        }
        return 100 * cnt / n;
    }
};
