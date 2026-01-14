class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), res = 1000, mn = 1000;
        vector<int> left(n);
        for (int i = 1; i < n; i++) {
            left[i] = mn = min(nums[i - 1], mn);
        }

        int right = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            if (left[i] < nums[i] && nums[i] > right) {
                res = min(res, left[i] + nums[i] + right);
            }
            right = min(right, nums[i]);
        }

        return res < 1000 ? res : -1;
    }
};




class Solution {
public:
    int minimumSum(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MAX;
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[j] <= nums[i]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] >= nums[j]) {
                        continue;
                    }
                    ans = min(ans, nums[i] + nums[j] + nums[k]);
                    
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
};


class Solution {
public:
    int minimumSum(vector<int>& nums) {

        int n = nums.size();
        stack<pair<int, int>> increase;
        stack<pair<int, int>> decrease;
        
        for (int i = 0; i < n; i++) {
            while (increase.empty() == false && nums[i] < increase.top().first) {
                increase.pop();
            }
            
            increase.push(make_pair(nums[i], i));
            
            while (decrease.empty() == false && nums[n - i - 1] < decrease.top().first) {
                decrease.pop();
            }
            decrease.push({nums[n - i - 1], n - i -1});
        }
        
        int incrVal = calMinVal(increase, nums);
        int decrVal = calMinVal(decrease, nums);
        
        int ans = min(incrVal, decrVal);
        
        return ans == INT_MAX ? -1 : ans;
    }
    
    int calMinVal(stack<pair<int, int>>& increase, vector<int>& nums) {      
        while (increase.empty() == false) {
            auto cur = increase.top();
            
            increase.pop();
            
            if (increase.empty() == true) {
                continue;
            }
            auto pre = increase.top();
            
            int right = max(cur.second, pre.second);
            int left = min(cur.second, pre.second);
            
            if (right - left < 2) {
                continue;
            }
            
            int minVal = *min_element(nums.begin() + left + 1, nums.begin() + right - 1);
            return minVal + cur.first + pre.first;
        }
        
        return INT_MAX;
    }
};