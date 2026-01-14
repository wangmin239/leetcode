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


class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(bool choosePre, int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};







class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        auto backTrace = [&ans](vector<int>& nums, set<vector<int>>& bits,
                         vector<int>& tmp, int len, int index, auto&& backTrace) {
                if (tmp.size() == len) {
                    if (bits.count(tmp) == 0) {
                        ans.push_back(tmp);
                        bits.insert(tmp);
                    }
                    
                    return;
                }
                
                const int offset = 10;
                for (int i = index; i < nums.size(); i++) {
                    tmp.push_back(nums[i]);
                    backTrace(nums, bits, tmp, len, i + 1, backTrace);
                    tmp.pop_back();
                }
                
                return;
            };
            
        ans.push_back({});
        
        sort(nums.begin(), nums.end());
        for (int len = 1; len <= n; len++) {
            set<vector<int>> bits;
            vector<int> tmp;
            backTrace(nums, bits, tmp, len, 0, backTrace);
            
        }
        

        
        return ans;
    }
};
