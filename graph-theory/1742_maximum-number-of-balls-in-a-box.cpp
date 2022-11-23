class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        auto getSum = [](int digit) {
            int sum = 0;
            
            while (digit != 0) {
                sum += digit % 10;
                digit /= 10;
            }
            return sum;
        };
        
        unordered_map<int> sumFreq;
        int maxNum = INT_MIN;
        
        for (int digit = lowLimit; digit <= highLimit; digit++) {
            int sum = getSum(digit);
            ++sumFreq[sum];
            maxNum = max(sumFreq[sum], maxNum);
        }
        
        return maxNum;
    }
};


class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int box = 0, x = i;
            while (x) {
                box += x % 10;
                x /= 10;
            }
            count[box]++;
            res = max(res, count[box]);
        }
        return res;
    }
};
