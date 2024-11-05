class Solution {
public:
    string losingPlayer(int x, int y) {
       const int mod = 4; 
       int mul = min(x, y / mod);
       
       return (mul & 0x1)? "Alice" : "Bob"; 
    }
};

class Solution {
public:
    string losingPlayer(int x, int y) {
        int k = min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x && y >= 4 ? "Alice" : "Bob";
    }
};
