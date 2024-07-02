class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int> primes = {
            2, 3, 5, 7, 11,
            13, 17, 19, 23, 29,
            31, 37, 41, 43, 47,
            53, 59, 61, 67, 71,
            73, 79, 83, 89, 97
        };

        int n = nums.size();
        int first = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (primes.count(nums[i])) {
                if (first != -1) {
                    ans = max(ans, i - first);
                }
                else {
                    first = i;
                }
            }
        }
        return ans;
    }
};





class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int len = nums.size();
        int begin = 0, end = len - 1;
        auto isPrime = [](const int value) {
            bool flag = true;
            for (int i = 2; i <= static_cast<int>(sqrt(value)); i++) {
                if (value % i == 0) {
                    flag = false;
                    break;
                }
            }
            return flag;
        };
        
        while (begin < len) {         
            if (nums[begin] > 1 && isPrime(nums[begin]) == true) {
                break;
            }
            ++begin;
        }
 
        while (end >= 0) {         
            if (nums[end] > 1 && isPrime(nums[end]) == true) {
                break;
            }
            --end;
        } 
        return end - begin;
    }
};
