class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> resVec;
        vector<int> tmp;
        backTrace(0, target, candidates, tmp, resVec);
        return resVec;

    }
    void backTrace(int start, int target, vector<int>& candidates, \
                    vector<int>& tmp, vector<vector<int>>& res) {
        if (target == 0) {
            res.emplace_back(tmp);
            return;
        } else if (target > 0) {
            for (int i = start; i < candidates.size(); i++) {
                tmp.emplace_back(candidates[i]);
                //backTrace(i + 1, target - candidates[i] , candidates, tmp, res);
                backTrace(i, target - candidates[i], candidates, tmp, res);
                tmp.pop_back();
            }
            return;
        }
        return;
    }
};



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> tmp;

        dfs(candidates, 0, target, tmp, ans);
        return ans;
    }
    
    void dfs(vector<int>& candidates, int index, int target,  vector<int>& tmp, vector<vector<int>>& ans) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i],  tmp, ans);
            tmp.pop_back();
        }
        
    }
};