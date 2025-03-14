/* Original Solution */
class Solution {
public:
    bool isBalanced(string num) {
        int len = num.length();
        int diff = 0;

        for (int i = 1; i < len; i += 2) {
            diff += num[i] - num[i - 1];
        }
        
        if (len & 0x1) {
            diff -= static_cast<int>(num[len - 1] - '0');
        }
        
        return diff == 0;
    }
};


/* Official Solution */
class Solution {
public:
    bool isBalanced(string num) {
        int diff = 0, sign = 1;
        for (char c : num) {
            int d = c - '0';
            diff += d * sign;
            sign = -sign;
        }
        return diff == 0;
    }
};

