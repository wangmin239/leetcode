class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for (int i = left; i <= right; i++) {
            int num = i;
            while (num != 0) {
                int mod = num % 10;
                if (mod == 0 || i % mod != 0) {
                    break;
                }
                num /= 10;
            }
            /* if the num is able to be divided */
            if (num == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for (int i = left; i <= right; i++) {
            int num = i;
            bool isDivid = true;
            while (num != 0) {
                int mod = num % 10;
                if (mod == 0 || i % mod != 0) {
                    isDivid = false;
                    break;
                }
                num /= 10;
            }
            
            if (isDivid == true) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};