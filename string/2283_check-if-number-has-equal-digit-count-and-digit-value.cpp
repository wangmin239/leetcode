class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> h;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            h[digit]++;
        }
        for (int i = 0; i < n; i++) {
            int v = num[i] - '0';
            if (h[i] != v) {
                return false;
            }
        }
        return true;
    }
};

。



class Solution {
public:
    bool digitCount(string num) {
        int len = num.length();
        unique_ptr<int[]> digitPtr(new int [len]);
        int sum = 0;

        for (int i = 0; i < len; i++) {
            int val = num[i] - '0';
            if (val > len / 2) {
                return false;
            }
            *digitPtr[i] = val; 
            sum += val;
        }
        
        if (sum != len) {
            return false;
        }
        
        for (int i = 0; i < len; i++) {
            int cnt = *digitPtr[i];
            int turn = 0;
            for (int j = 0; j < len; j++) {
                if (*digitPtr[j] == i) {
                    turn++;
                }
            }
            
            if (turn != cnt) {
                return false;
            }
        }
        return true;
    }
};