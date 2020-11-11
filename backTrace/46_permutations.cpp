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

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
