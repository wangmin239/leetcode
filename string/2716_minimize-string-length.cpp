/* Original Solution */
class Solution {
public:
    int minimizedStringLength(string s) {
        int len = s.length();
        const int num = 26;
        bool chArr[num] = {false};
        
        for (char ch : s) {
            int id = static_cast<int>(ch - 'a');
            if (chArr[id] == true) {
                --len;
            }
            chArr[id] = true;
        }
        
        return len;
    }
};

/* Official Solution */
class Solution {
public:
    int minimizedStringLength(string s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return __builtin_popcount(mask);
    }
};