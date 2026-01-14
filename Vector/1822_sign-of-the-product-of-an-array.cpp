class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negtiveCnt = 0;
        
        for (int val : nums) {
            if (val == 0) {
                return 0;
            }
            
            if (val < 0) {
                ++negtiveCnt;
            }
        }
        
        return negtiveCnt & 0x1 ? -1 : 1;
            
    }
};

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (auto num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                sign = -sign;
            }
        }
        return sign;
    }
};
