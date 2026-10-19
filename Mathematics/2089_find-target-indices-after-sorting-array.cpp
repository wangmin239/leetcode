/* Original Solution 1 */
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());

        auto iter = lower_bound(nums.begin(), nums.end(), target);

        if (iter == nums.end()) {
            return ans;
        }

        while (iter != nums.end() && *iter == target) {
            ans.push_back(iter - nums.begin());
            ++iter;
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < n; ++i){
            if (nums[i] == target){
                res.push_back(i);
            }
        }
        return res;
    }
};



/* Official Solution 2 */
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt1 = 0;   // 小于 target 的元素数量
        int cnt2 = 0;   // 等于 target 的元素数量
        for (const int num: nums){
            if (num < target){
                ++cnt1;
            }
            else if (num == target){
                ++cnt2;
            }
        }
        vector<int> res;   // 下标数组
        for (int i = cnt1; i < cnt1 + cnt2; ++i){
            res.push_back(i);
        }
        return res;
    }
};
