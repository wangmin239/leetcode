class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sqrtVal = static_cast<int>(sqrt(num));
        int sum = 1;
        
        if (num == 1) {
            return false;
        }
        for (int i = 2; i < sqrtVal; i++) {
            if (num % i == 0) {
                sum += i;
                sum += num / i;
            }
        }
        
        return  sum == num;
    }
};