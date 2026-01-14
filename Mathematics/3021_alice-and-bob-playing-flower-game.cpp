/* Original Solution 1 */
class Solution {
public:
    long long flowerGame(int n, int m) {
        int nEven = n / 2;
        int nOdd = (n + 1) / 2;
        int mEven = m / 2;
        int mOdd = (m + 1) / 2;
        
        long long ans = 0;
        
        ans += 1LL * nEven * mOdd;
        ans += 1LL * nOdd * mEven;
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long)m * n / 2;
    }
};

