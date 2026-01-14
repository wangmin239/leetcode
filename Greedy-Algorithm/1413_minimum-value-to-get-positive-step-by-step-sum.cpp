class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = INT_MAX;
        int sum = 0;
        
        for (auto val : nums) {
            sum += val;
            minVal = min(minVal, sum);
        }
        
        minVal = minVal > 0 ? 1 : 1 - minVal;
        return minVal;
    }
};



class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int accSum = 0, accSumMin = 0;
        for (int num : nums) {
            accSum += num;
            accSumMin = min(accSumMin, accSum);
        }
        return -accSumMin + 1;
    }
};


class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        if (m >= 0) {
            return 1;
        }
        int left = 1, right = -m * nums.size() + 1;
        while (left < right) {
            int medium = (left + right) / 2;
            if (valid(medium, nums)) {
                right = medium;
            } else {
                left = medium + 1;
            }
        }
        return left;
    }

    bool valid(int startValue, vector<int>& nums) {
        for (int num : nums) {
            startValue += num;
            if (startValue <= 0) {
                return false;
            }
        }
        return true;
    }
};
