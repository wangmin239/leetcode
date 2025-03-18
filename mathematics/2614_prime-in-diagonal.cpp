class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int rows = nums.size();
        int maxPrime = 0;

        auto isPrime = [] (const int num) {
            if (num == 1) {
                return false;
            }
            int limit = static_cast<int>(pow(num, 0.5)) + 1;
            for (int i = 2; i < limit; i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        };
        
        for (int row = 0; row < rows; row++) {
            if (isPrime(nums[row][row])) {
                maxPrime = max(maxPrime, nums[row][row]);
            }
            
            if (isPrime(nums[row][rows - row - 1])) {
                maxPrime = max(maxPrime, nums[row][rows - row - 1]);
            }
        }
        
        return maxPrime;
    }
};




class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) {
                res = max(res, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                res = max(res, nums[i][n - i - 1]);
            }
        }
        return res;
    }

    bool isPrime(int num) {
        if (num == 1) {
            return false;
        }
        int factor = 2;
        while (factor * factor <= num) {
            if (num % factor == 0) {
                return false;
            }
            factor++;
        }
        return true;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/prime-in-diagonal/solutions/3596904/dui-jiao-xian-shang-de-zhi-shu-by-leetco-0803/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。