/* Original Solution 1 */
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n, false);
        int value = 0;
        const int mod = 5;

        for (int i = 0; i < n; i++) {
            value = (value << 1) + nums[i];
            value = value % mod;
            ans[i] = value == 0;
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int prefix = 0;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + nums[i]) % 5;
            answer.emplace_back(prefix == 0);
        }
        return answer;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x = (x << 1 | nums[i]) % 5;
            ans[i] = x == 0;
        }
        return ans;
    }
};
