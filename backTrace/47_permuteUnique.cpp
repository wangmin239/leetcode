class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> flags(nums.size(), false);
        sort(nums.begin(), nums.end(), less<int>());
        backTrace(nums, tmp, res, flags);
        return res;
    }

    void backTrace(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res, vector<bool> &flags) {
        if (tmp.size() == nums.size()) {
            res.emplace_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && flags[i - 1] == false) {
                continue;
            }
            if (flags[i] == false) {
                tmp.emplace_back(nums[i]);
                flags[i] = true;
                backTrace(nums, tmp, res, flags);
                flags[i] = false;
                tmp.pop_back();
            }
        }       

    }
};



class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};
