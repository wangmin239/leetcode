class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (long long) (1 + n) * n / 2 % mod;
        }
        return ((long long) (1 + m) * m / 2 + 
                ((long long) target + target + (n - m) - 1) * (n - m) / 2) % mod;
    }
};



class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long sum = 0;
        const int mod = 1e9 + 7;
        
        long limit = (target / 2;
        
        if (n <= limit) {
            sum = (1 + n) * n/ 2;
            return sum % mod;
        }
        
        sum = (1 + limit) * limit / 2;
        sum %= mod;
        
        
        sum += (target + (target + n - limit - 1))*(n - limit)/2;
        
        
        
        return sum % mod;
    }
};
