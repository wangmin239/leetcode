/* Original Solution 1 */
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        int turns = n - 2;
        const int decimal = 10;

        for (int turn = 0; turn < turns; turn++) {
            for (int i = 1; i < n - turn; i++) {
                s[i - 1] = (s[i] + s[i - 1] - '0') % decimal; 
            }
        }

        return s[0] == s[1];
    }
};


/* Original Solution 2 */
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        
        if (n == 2) {
            return s.front() == s.back();
        }
        
        for (int i = 1; i < n; i++) {
            s[i - 1] = (s[i] + s[i - 1] - '0') % 10;
        }
        
        s.pop_back();
        
        return hasSameDigits(s);
    }
};