/* Original Solution */
class Solution {
public:
    int minimumSum(int n, int k) {
        int mid = k / 2;
        int sum = 0;
        
        /* accumulate the front half of the k elements */
        for (int i = 1; i <= mid && n; ++i, --n) {
            sum += i;
        }
        
        /* add the remain element whose value is not less than k */
        while (n-- > 0) {
            sum += k++;
        }
        
        return sum;
    }
};

/* Official Solution */
class Solution {
public:
    int minimumSum(int n, int k) {
        if (n <= k / 2) {
            return arithmeticSeriesSum(1, 1, n);
        } else {
            return arithmeticSeriesSum(1, 1, k / 2) + arithmeticSeriesSum(k, 1, n - k / 2);
        }
    }

private:
    int arithmeticSeriesSum(int a1, int d, int n) {
        return (a1 + a1 + (n - 1) * d) * n / 2;
    }
};
