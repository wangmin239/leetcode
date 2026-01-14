class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_digit_sum = 0;
        int double_digit_sum = 0;
        for (auto num : nums) {
            if (num < 10) {
                single_digit_sum += num;
            } else {
                double_digit_sum += num;
            }
        }
        return single_digit_sum != double_digit_sum;
    }
};

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = 0;
        const int ten = 10;

        for (const int val : nums) {
            if (val < ten) {
                sum += val;
            } else {
                sum -= val;
            }
        }
        
        return sum != 0;
    }
};