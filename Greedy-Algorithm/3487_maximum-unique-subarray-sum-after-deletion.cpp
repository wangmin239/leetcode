class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        int preVal;
        
        sort(nums.begin(), nums.end(), greater<int>());
        sum += nums.front();
        preVal = sum;
        
        for (int i = 1; i < len; i++) {
            if (nums[i] <= 0) {
                return sum;
            }
            
            if (nums[i] != preVal) {
                sum += nums[i];
                preVal = num[i];
            }
        }
        
        return sum;
    }
};


class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = nums.front();
        int maxSubSum = nums.front();
        int len = nums.size();
        unordered_map<int, int> digits;
        
        ++digits[nums.front()];
        for (int left = 0, right = 1; right < len; right++) {
            int curVal = nums[right];
            

            
            if (sum < 0 && sum < curVal) {
                sum = 0;
                digits.clear();
            }
            
            sum += curVal;
            ++digits[curVal];
            

            
            while (digits[curVal] > 1) {
                sum -= nums[left];
                --digits[nums[left++]];
            }
            
            maxSubSum = max(maxSubSum, sum);
        }
        
        return maxSubSum;
    }
};