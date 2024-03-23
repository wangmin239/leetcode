class Solution {
public:
    int distinctIntegers(int n) {
        vector<int> nums(n + 1);
        nums[n] = 1;
        for (int k = 0; k < n; k++) {
            for (int x = 1; x <= n; x++) {
                if (nums[x] == 0) {
                    continue;
                }
                for (int i = 1; i <= n; i++) {
                    if (x % i == 1) {
                        nums[i] = 1;
                    }
                }
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1 ? 1 : n - 1;
    }
};


class Solution {
public:
    int distinctIntegers(int n) {
        vector<int> desktopNums(n + 1, 0);
        
        desktopNums[n] = 1;

        for (int x = n; x >= 0; x--) {
            if (desktopNums[x] == 0) {
                continue;
            }
            
            for (int i = 1; i <= n; i++) {
                if (x % i == 1) {
                    desktopNums[i] = 1;
                }
            }
            
        }
        
        
        int ans = 0;
        for (int x : desktopNums) {
            if (x == 1) {
                ++ans;
            }
        }
        
        return ans;
    }
};