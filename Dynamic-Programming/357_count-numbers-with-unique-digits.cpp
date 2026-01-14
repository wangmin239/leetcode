class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        int maxVal = pow(10, n);
        
        for (int i = 0; i < maxVal; i++) {
            if (isDiff(i) == true) {
                ans++;
            }
        }
        
        return ans;
    }
    
    inline bool isDiff(int n) {
        int digitArr[10] = {0};
        
        while (n > 0) {
            digitArr[n % 10]++;
            n /= 10;
        }
        
        for (int i = 0; i < 10; i++) {
            if (digitArr[i] > 1) {
                return false;
            }
        }
        
        return true;
    }
};
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int ans = 10, cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur *= 9 - i;
            ans += cur;
        }
        return ans;
    }
};


class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + (dp[i-1] - dp[i-2])*(10-(i-1));
        }
        return dp[n];
    }
}

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1, b = 9;
        for(int i = 1; i <= min(10, n); b *= (10 - i++)) ans += b;
        return ans;
    }
};