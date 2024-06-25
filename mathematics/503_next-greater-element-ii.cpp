class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + n; j++) {
                if (nums[j % n] > nums[i]) {
                    ans[i] = nums[j % n];
                    break;
                }
            }
        }
        
        return ans;
    }
};

