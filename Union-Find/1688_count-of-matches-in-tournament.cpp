class Solution {
public:
    int numberOfMatches(int n) {
        int rounds = 0;
        
        while (n != 1) {
            int remain = n & 0x1;
            n /= 2;
            rounds += n;
            n += remain;
        }
        
        return rounds;
    }
};


class Solution {
public:
    int numberOfMatches(int n) {
        
        return n - 1;
    }
};