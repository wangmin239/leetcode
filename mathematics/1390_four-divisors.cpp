/* Original Solution 1 */
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        auto getSumDivisors = [](int num) {
            int sum = 1 + num;
            int cnt = 2;
            const int maxCnt = 4;

            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    sum += i;
                    ++cnt;
                }
                if (cnt > maxCnt) {
                    return 0;
                }
            }

            if (cnt == maxCnt) {
                return sum;
            }

            return 0;
        };

        for (int num : nums) {
            sum += getSumDivisors(num);
        }

        return sum;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            // factor_cnt: 因数的个数
            // factor_sum: 因数的和
            int factor_cnt = 0, factor_sum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    ++factor_cnt;
                    factor_sum += i;
                    if (i * i != num) {   // 判断 i 和 num/i 是否相等，若不相等才能将 num/i 看成新的因数
                        ++factor_cnt;
                        factor_sum += num / i;
                    }
                }
            }
            if (factor_cnt == 4) {
                ans += factor_sum;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // C 是数组 nums 元素的上限，C3 是 C 的立方根
        int C = 100000, C3 = 46;
        
        vector<int> isprime(C + 1, 1);
        vector<int> primes;

        // 埃拉托斯特尼筛法
        for (int i = 2; i <= C; ++i) {
            if (isprime[i]) {
                primes.push_back(i);
            }
            for (int j = i + i; j <= C; j += i) {
                isprime[j] = 0;
            }
        }

        // 欧拉筛法
        /*
        for (int i = 2; i <= C; ++i) {
            if (isprime[i]) {
                primes.push_back(i);
            }
            for (int prime: primes) {
                if (i * prime > C) {
                    break;
                }
                isprime[i * prime] = 0;
                if (i % prime == 0) {
                    break;
                }
            }
        }
        */
        
        // 通过质数表构造出所有的四因数
        unordered_map<int, int> factor4;
        for (int prime: primes) {
            if (prime <= C3) {
                factor4[prime * prime * prime] = 1 + prime + prime * prime + prime * prime * prime;
            }
        }
        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i + 1; j < primes.size(); ++j) {
                if (primes[i] <= C / primes[j]) {
                    factor4[primes[i] * primes[j]] = 1 + primes[i] + primes[j] + primes[i] * primes[j];
                }
                else {
                    break;
                }
            }
        }

        int ans = 0;
        for (int num: nums) {
            if (factor4.count(num)) {
                ans += factor4[num];
            }
        }
        return ans;
    }
};
