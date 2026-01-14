/* Original Solution */
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        auto isEven = [](int value) {
            int digits = 0;
            
            while (value) {
                value /= 10;
                ++digits;
            }
            
            return  0 == (digits & 0x1);
        };
        
        for (int value : nums) {
            if (isEven(value) == true) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            if (to_string(num).size() % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            if ((int)(log10(num) + 1) % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
