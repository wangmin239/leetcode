class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int negativeCount = 0, zeroCount = 0, positiveCount = 0;
        long long prod = 1;
        int maxNegative = INT_MIN;
        for (int num : nums) {
            if (num < 0) {
                negativeCount++;
                prod *= num;
                maxNegative = max(maxNegative, num);
            } else if (num == 0) {
                zeroCount++;
            } else {
                prod *= num;
                positiveCount++;
            }
        }

        if (negativeCount == 1 && zeroCount == 0 && positiveCount == 0) {
            return nums[0];
        }
        if (negativeCount <= 1 && positiveCount == 0) {
            return 0;
        }
        if (prod < 0) {
            return prod / maxNegative;
        } else {
            return prod;
        }
    }
};



class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        
        sort(nums.begin(), nums.end());
        
        auto negIter = lower_bound(nums.begin(), nums.end(), 0);
        int negCnt = negIter - nums.begin();
        long long mul = 1;

        negCnt = (negCnt >> 1) << 1;
        bool isEmpty = true;
        if (negCnt != 0) {
            isEmpty = false;
        }
        
        auto iter = nums.begin();
        while (negCnt--) {
            mul *= *iter;
            ++iter;
        }
        /* find the element whose value is greater than 1 */
        for (auto iter = negIter; iter != nums.end(); ++iter) {
            if (*iter == 0) {
                continue;
            }
            isEmpty = false;
            mul *= *iter;
        }
        
        return isEmpty? *negIter: mul;
    }
};

