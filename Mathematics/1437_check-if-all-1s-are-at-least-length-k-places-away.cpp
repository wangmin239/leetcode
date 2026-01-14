/* Original Solution 1 */
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -k - 1;
        
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - pre <= k) {
                    return false;
                }
                pre = i;
            }
        }
        
        return true;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (prev != -1 && i - prev - 1 < k) {
                    return false;
                }
                prev = i;
            }
        }
        return true;
    }
};
