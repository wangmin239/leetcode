class Solution {
public:
    int maxVal;
    int cnt;
    int countMaxOrSubsets(vector<int>& nums) {
        this->maxVal = 0;
        
        for (int val : nums) {
            this->maxVal |= val;
        }
        
        int n = nums.size();
        cnt = 0;
        dfs(nums, 0, 0);
        return cnt;
    }
    
    void dfs(const vector<int>& nums, int start, int sum) {
        if (sum == maxVal) {
            cnt++;
        }

        
        for (int i = start; i < nums.size(); i++) {
            dfs(nums, visited, i + 1, sum | nums[i]);
        }
    }
};


class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue) {
                cnt++;
            } else if (cur > maxValue) {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};



class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }

    void dfs(int pos, int orVal) {
        if (pos == nums.size()) {
            if (orVal > maxOr) {
                maxOr = orVal;
                cnt = 1;
            } else if (orVal == maxOr) {
                cnt++;
            }
            return;
        }
        dfs(pos + 1, orVal| nums[pos]);
        dfs(pos + 1, orVal);
    }

private:
    vector<int> nums;
    int maxOr, cnt;
};
