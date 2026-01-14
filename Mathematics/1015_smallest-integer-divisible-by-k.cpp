/* Original Solution 1 */
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> remainderSet;
        int initVal = 0;
        int len = 0;
        const int multiple = 10;
        
        auto getInitVal = [](int k, int& len) {
            int val = 0;
            
            while (k != 0) {
                val = multiple * val + 1;
                k /= multiple;
                ++len;
            }
            return val;
        }

        initVal = getInitVal(k, len);
        int mod = initVal % k;
        while (mod % k != 0 && remainderSet.count(mod) == 0) {
            remainderSet.insert(mod);
            ++len;
            
            mod = multiple *  mod + 1;
            mod = mod % k;
        }
        
        if (mod % k == 0) {
            return len;
        }
        
        return -1;
    }
};




/* Original Solution 2 */
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int len = 1;
        unordered_set<int> remainderSet;
        int mod = 1;
        const int multiple = 10;

        while (mod % k != 0 && remainderSet.count(mod) == 0) {
            remainderSet.insert(mod);
            ++len;
            
            mod = multiple *  mod + 1;
            mod = mod % k;
        }
        
        if (mod % k == 0) {
            return len;
        }
        
        return -1;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int resid = 1 % k, len = 1; // resid为余数，len为数字长度，初始值为1
        unordered_set<int> st; // 创建一个无序集合，用于存储余数
        st.insert(resid); // 插入余数1
        while (resid != 0) { // 当余数为0时退出循环
            resid = (resid * 10 + 1) % k; // 计算下一个余数
            len++; // 数字长度+1
            if (st.find(resid) != st.end()) { // 如果余数重复出现，则无解
                return -1;
            }
            st.insert(resid); // 将余数插入集合
        }
        return len; // 返回数字长度
    }
};


/* Official Solution 2 */
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        int x = 1 % k;
        for (int i = 1; ; i++) { // 一定有解
            if (x == 0) {
                return i;
            }
            x = (x * 10 + 1) % k;
        }
    }
};


/* Official Solution 3 */
class Solution {
    // 计算欧拉函数（n 以内的与 n 互质的数的个数）
    int phi(int n) {
        int res = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                res = res / i * (i - 1);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) {
            res = res / n * (n - 1);
        }
        return res;
    }

    // 快速幂，返回 pow(x, n) % mod
    long long pow(long long x, int n, long long mod) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int m = phi(k * 9);

        // 从小到大枚举不超过 sqrt(m) 的因子
        int i = 1;
        for (; i * i <= m; i++) {
            if (m % i == 0 && pow(10, i, k * 9) == 1) {
                return i;
            }
        }

        // 从小到大枚举不低于 sqrt(m) 的因子
        for (i--; ; i--) {
            if (m % i == 0 && pow(10, m / i, k * 9) == 1) {
                return m / i;
            }
        }
    }
};
