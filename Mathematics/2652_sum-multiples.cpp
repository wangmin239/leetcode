class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                sum += i;
                continue;
            }
            
            if (i % 5 == 0) {
                sum += i;
                continue;
            }
            if (i % 7 == 0) {
                sum += i;
            }
        }
        return sum;
    }
};


class Solution {
public:
    int sumOfMultiples(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                res += i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int f(int n, int m) {
        return (m + n / m * m) * (n / m) / 2;
    }

    int sumOfMultiples(int n) {
        return f(n, 3) + f(n, 5) + f(n, 7) - f(n, 3 * 5) - f(n, 3 * 7) - f(n, 5 * 7) + f(n, 3 * 5 * 7);
    }
};
