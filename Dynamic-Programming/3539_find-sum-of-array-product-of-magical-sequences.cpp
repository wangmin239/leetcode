/* Official Solution 1 */
class Solution {
public:
    long long quickmul(long long x, long long y, long long mod) {
        long long res = 1, cur = x % mod;
        while(y) {
            if(y & 1) {
                res = res * cur % mod;
            }
            y >>= 1;
            cur = cur * cur % mod;
        }
        return res;
    };

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        const long long mod = 1e9 + 7;
        vector<long long> fac(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
        vector<long long> ifac(m + 1, 1);
        for (int i = 2; i <= m; i++) {
            ifac[i] = quickmul(i, mod - 2, mod);
        }
        for (int i = 2; i <= m; i++) {
            ifac[i] = ifac[i - 1] * ifac[i] % mod;
        }
        vector numsPower(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod;
            }
        }

        vector f(n, vector(m + 1, vector(m * 2 + 1, vector<long long>(k + 1, 0))));
        for (int j = 0; j <= m; j++) {
            f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod;
        }
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        int q2 = p % 2 + q;
                        if (q2 > k) {
                            break;
                        }
                        for (int r = 0; r + j <= m; r++) {
                            int p2 = p / 2 + r;
                            f[i + 1][j + r][p2][q2] += f[i][j][p][q] * numsPower[i + 1][r] % mod * ifac[r] % mod;
                            f[i + 1][j + r][p2][q2] %= mod;
                        }
                    }
                }
            }
        }
        long long res = 0;
        for (int p = 0; p <= m * 2; p++) {
            for (int q = 0; q <= k; q++) {
                if (__builtin_popcount(p) + q == k) {
                    res = (res + f[n - 1][m][p][q] * fac[m] % mod) % mod;
                }
            }
        }
        return res;
    }
};



/* Official Solution 2 */
static constexpr int MOD=1e9+7;
static int C[31][31]={{0}}; 
static int dp[31][31][50][31];

class Solution {
    int m, k, n;
    void Pascal(){ 
        if (C[0][0]==1) return; // compute only once 
        for(int i=1; i<=30; i++){ 
            C[i][0]=C[i][i]=1; 
            for(int j=1; j<=i/2; j++){ 
                C[i][j]=C[i][i-j]=C[i-1][j-1]+C[i-1][j]; 
            } 
        }
    }

    int dfs(int m, int k, int i, unsigned flag, vector<int>& nums) {
        const int bz=__builtin_popcount(flag);
        if (m<0 || k<0 || m+bz<k)
            return 0;
        if (m==0)
            return (k==bz)?1:0;
        if (i>=n) return 0;

        if (dp[m][k][i][flag]!=-1) return dp[m][k][i][flag];

        long long ans=0, powX=1;
        const int x=nums[i];
        for (int f=0; f<=m; f++) {
            long long perm=C[m][f]*powX%MOD;
            unsigned newFlag=flag+f;
            unsigned nextFlag=newFlag>>1;
            bool bitSet=newFlag&1;
            ans=(ans+perm*dfs(m-f, k-bitSet, i+1, nextFlag, nums))%MOD;
            powX=(powX*x)%MOD;
        }

        return dp[m][k][i][flag]=ans;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        Pascal();
        this->m=m; this->k=k; n=nums.size();
        for(int i=0; i<=m; i++)
            for(int j=0; j<=m; j++)
                for(int s=0; s<n; s++)
                    memset(dp[i][j][s], -1, sizeof(int)*(m+1));
        return dfs(m, k, 0, 0, nums);
    }
};


/* Official Solution 3 */

/* Official Solution 2 */
static constexpr int MOD=1e9+7;
static int C[31][31]={{0}}; 
static int dp[31][31][50][31];

class Solution {
    int m, k, n;
    void Pascal(){ 
        if (C[0][0]==1) return; // compute only once 
        for(int i=1; i<=30; i++){ 
            C[i][0]=C[i][i]=1; 
            for(int j=1; j<=i/2; j++){ 
                C[i][j]=C[i][i-j]=C[i-1][j-1]+C[i-1][j]; 
            } 
        }
    }

    int dfs(int m, int k, int i, unsigned flag, vector<int>& nums) {
        const int bz=__builtin_popcount(flag);
        if (m<0 || k<0 || m+bz<k)
            return 0;
        if (m==0)
            return (k==bz)?1:0;
        if (i>=n) return 0;

        if (dp[m][k][i][flag]!=-1) return dp[m][k][i][flag];

        long long ans=0, powX=1;
        const int x=nums[i];
        for (int f=0; f<=m; f++) {
            long long perm=C[m][f]*powX%MOD;
            unsigned newFlag=flag+f;
            unsigned nextFlag=newFlag>>1;
            bool bitSet=newFlag&1;
            ans=(ans+perm*dfs(m-f, k-bitSet, i+1, nextFlag, nums))%MOD;
            powX=(powX*x)%MOD;
        }

        return dp[m][k][i][flag]=ans;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        Pascal();
        this->m=m; this->k=k; n=nums.size();
        for(int i=0; i<=m; i++)
            for(int j=0; j<=m; j++)
                for(int s=0; s<n; s++)
                    memset(dp[i][j][s], -1, sizeof(int)*(m+1));
        return dfs(m, k, 0, 0, nums);
    }
};