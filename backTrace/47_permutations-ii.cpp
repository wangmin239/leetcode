class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);

        // 对数组进行排序，方便去重
        std::sort(nums.begin(), nums.end());

        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // 当当前排列的长度等于数组的长度时，说明找到了一个全排列
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前元素已经被使用过，跳过
            if (used[i]) continue;

            // 剪枝条件：如果当前元素和前一个元素相同，并且前一个元素未被使用，跳过
            if (i > 0 && nums[i] == nums[i - 1] &&!used[i - 1]) continue;

            // 标记当前元素已被使用
            used[i] = true;
            // 将当前元素加入当前排列
            current.push_back(nums[i]);

            // 递归调用，继续生成排列
            backtrack(nums, used, current, result);

            // 回溯操作，撤销当前选择
            used[i] = false;
            current.pop_back();
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