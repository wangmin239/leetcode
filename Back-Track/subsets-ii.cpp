class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end(), less<int>());
        backTrace(nums, 0, tmp, res);
        return res;
    }

    void backTrace(vector<int> &nums, int startIndex, vector<int> &tmp, vector<vector<int>> &res) {
        if (startIndex > nums.size()) {
            return;
        }

        res.emplace_back(tmp);
        for (int index = startIndex; index < nums.size(); index++) {
            if (index > startIndex && nums[index] == nums[index - 1]) {
                continue;
            }
            tmp.push_back(nums[index]);
            backTrace(nums, index + 1, tmp, res);
            tmp.pop_back();
        }
    }
};