class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> flags(nums.size(), false);
        backTrace(nums, tmp, res, flags);
        return res;
    }

    void backTrace(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res, vector<bool> &flags) {
        if (tmp.size() == nums.size()) {
            res.emplace_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (flags[i]) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            flags[i] = true;
            backTrace(nums, tmp, res, flags);
            flags[i] = false;
            tmp.pop_back();
        }       

    }
};