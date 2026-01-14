class Solution {
public:
    int binaryGap(int n) {
        int last = -1, ans = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return ans;
    }
};




class Solution {
public:
    int binaryGap(int n) {
        int bitArr[32] = {0};
        int i = 0;
        
        while (n > 0) {
            bitArr[i] = n % 2;
            n /= 2;
            i++;
        }
        
        int maxDist = 0;
        int preOneIndex;
        int curOneIndex;
        int i;
        for (i = 0; i < 32 ; i++) {
            if (bitArr[i] == 1) {
                preOneIndex = i;
                break;
            }
        }
        
        for (i = i + 1; i < 32; i++) {
            if (bitArr[i] == 1) {
                curOneIndex = i;
                maxDist = max(curOneIndex - preOneIndex, maxDist);
                preOneIndex = curOnedex;
            }
        }
        return maxDist;
    }
};