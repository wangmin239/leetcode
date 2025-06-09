/* Original Solution 1 */
class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        int number = 1;
        constexpr int decimal = 10;
        
        for (int i = 1; k && i <= n; i++, k--) {
            ans = number;
            
            if (1LL * decimal * number <= 1LL * n) {
                number *= decimal;
                continue;
            }
            
            while (number % decimal == 9 || number + 1 > n) {
                number /= decimal;
            }
            number++;
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};
