class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    bool check(int mask, int k, int n) {
        temp.clear();
        for (int i = 0; i < 9; ++i) {
            if ((1 << i) & mask) {
                temp.push_back(i + 1);
            }
        }
        return temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == n; 
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for (int mask = 0; mask < (1 << 9); ++mask) {
            if (check(mask, k, n)) {
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int sum) {
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) {
            return;
        }
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<int> digits {1, 2, 3, 4, 5, 6, 7, 8, 9};
        dfs(0, k, n, tmp, digits, ans);

        return ans;
    }
    
    void dfs(int index, int k, int n, vector<int>& tmp, const vector<int>& digits, vector<vector<int>>& ans) {

        if (k < 0 || n < 0) {
            return;
        }
        
        if (k == 0 && n == 0) {
            ans.push_back(tmp);
            return;
        }
        
        for (int i = index; i < digits.size(); i++) {
            if (n < digits[i]) {
                continue;
            }
            tmp.push_back(digits[i]);
            dfs(i + 1, k - 1,  n - digits[i], tmp, digits, ans);
            tmp.pop_back();
        }
    }
};