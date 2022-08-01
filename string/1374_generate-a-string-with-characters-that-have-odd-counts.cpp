class Solution {
public:
    string generateTheString(int n) {
        if ((n & 0x1) == 1) {
            return string(n, 'a');
        }
        
        return "a" + string(n - 1, 'b);
    }
};