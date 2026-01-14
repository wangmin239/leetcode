/* Original Solution 1 */
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> ans;
        
        for (size_t i = 0; i < size; i++) {
            while (ans.empty() == false) {
                int backVal = ans.back();
                /* These two adjacent numbers have no common divisor. */
                if (gcd(backVal, nums[i]) == 1) {
                    break;
                }
                /* Update the value of the last number in an array. */
                ans.pop_back();
                nums[i] = lcm(backVal, nums[i]);
            }
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            while (!ans.empty()) {
                int g = gcd(ans.back(), num);
                if (g > 1) {
                    num = ans.back() / g * num;
                    ans.pop_back();
                }
                else {
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};
