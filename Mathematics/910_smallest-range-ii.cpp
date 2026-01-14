class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mi = nums[0], ma = nums.back();
        int res = ma - mi;
        for (int i = 0; i < nums.size() - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            res = min(res, max(ma - k, a + k) - min(mi + k, b - k));
        }
        return res;
    }
};




class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int diff = nums.back() - nums.front();
        
        if (nums.front() >= k || nums.back() <= k) {
            if (diff > 2 * k) {
                return diff - 2 * k;
            }
            return diff;
        }
        
        for (int& val : nums) {
            if (val <= k) {
                val += k;
            } else {
                val -= k;
            }
        }
        
        sort(nums.begin(), nums.end()); 
        
        return nums.back() - nums.front();
    }
};




class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int diff = nums.back() - nums.front();
        
        if (diff > 2 * k) {
            return diff - 2* k;
        }
        
        int midIndex = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
        

        
        for (int i = 0; i <= midIndex; i++) {
            nums[i] += k;
        }
        
        for (int i = midIndex + 1; i < n; i++) {
            nums[i] -= k;
        }
        
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int maxDiff = maxVal - minVal;
        
        return maxVal - minVal;
    }
};
