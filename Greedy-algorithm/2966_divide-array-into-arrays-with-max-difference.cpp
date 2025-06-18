
/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        const int elements = 3;
        int groups = n % elements;
        vector<vector<int>> ans(groups, vector<int>(elements));
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0, group = 0; i < n; i += elements, group++) {
            if (nums[i + elements - 1] - nums[i] > k) {
                return {{}};
            }
            for (int j = 0; j < elements; j++) {
                ans[group][j] = nums[i + j];
            }
        }
        
        return ans;
    }
};



/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            res.emplace_back(nums.begin() + i, nums.begin() + i + 3);
        }
        return res;
    }
};
