/* Original Solution */
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> minVals(n); 
        int minVal = INT_MAX;
        int sum = 0;
        int preMax = INT_MIN;
        
        /* from back of the input vector forward to the front vector */
        for (int i = 1; i < n; i++) {
            minVal = min(minVal, nums[n - i]);
            minVals[n - i] = minVal;
        }    
        /* traverse the every element of the nums */
        for (int i = 1; i < n - 1; i++) { 
            preMax = max(preMax, nums[i - 1]);
            if (preMax < nums[i] &&  nums[i] < minVals[i + 1]) {
                sum += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                sum += 1;
            }
        }
        
        return sum;
    }
};

/* Official Solution */
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> state(n);
        int pre_max = nums[0];

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > pre_max) {
                state[i] = 1;
                pre_max = nums[i];
            }
        }

        int suf_min = nums[n - 1];
        int res = 0;
        for (int i = n - 2; i > 0; i--) {
            if (state[i] && nums[i] < suf_min) {
                res += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                res += 1;
            }
            suf_min = min(suf_min, nums[i]);
        }
        return res;
    }
};
