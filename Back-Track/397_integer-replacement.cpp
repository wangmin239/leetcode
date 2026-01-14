class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        /* the value of n is even */
        if ((n & 1) == 0) {
            return integerReplacement(n >> 1) + 1;
        }
        if (n == INT_MAX) {
            return 32;
        }
        return min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
    }
};
class Solution {
private:
    unordered_map<int, int> memo;

public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        if (n % 2 == 0) {
            return memo[n] = 1 + integerReplacement(n / 2);
        }
        return memo[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};


class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                ++ans;
                n /= 2;
            }
            else if (n % 4 == 1) {
                ans += 2;
                n /= 2;
            }
            else {
                if (n == 3) {
                    ans += 2;
                    n = 1;
                }
                else {
                    ans += 2;
                    n = n / 2 + 1;
                }
            }
        }
        return ans;
    }
};
