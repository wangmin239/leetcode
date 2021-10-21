class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto iter = digits.rbegin();
        int carry = 1;
        
        while (iter != digits.rend()) {
            *iter += 1;
            carry = *iter / 10;
            *iter %= 10;
            iter++;
            if (carry != 1) {
                break;
            }
        }
        
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        // all the element of the digits are 9. 
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};
