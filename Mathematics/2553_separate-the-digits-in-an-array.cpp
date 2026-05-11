/* Original Solution 1 */
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        const int decimal = 10;
        int i = 0, j = 0;

        for (int num : nums) {
            while (num != 0) {
                digits.push_back(num % decimal);
                num /= decimal;
                j++;
            }

            --j;
            while (i < j) {
                swap(digits[i], digits[j]);
                ++i;
                --j;
            }
            i = j = digits.size();
        }

        return digits;
    }
};


/* Official Solution 1 */ 
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            for (char ch : to_string(x)) {
                ans.push_back(ch - '0');
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.push_back(x % 10);
                x /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
