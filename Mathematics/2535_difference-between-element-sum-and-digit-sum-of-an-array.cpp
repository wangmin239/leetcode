class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int diff = 0;
        
        for (int num : nums) {
            diff += num;
            while (num) {
                diff -= num % 10;
                num /= 10;
            }
        }
        
        return diff;
    }
};

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans += x; // 累加元素和
            while (x) {
                ans -= x % 10; // 减去数位和
                x /= 10;
            }
        }
        return ans;
    }
};

