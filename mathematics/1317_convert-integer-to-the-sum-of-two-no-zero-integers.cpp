/* Original Solution 1 */
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2, 0);
        const int decimal = 10;
        const int half = 2;
        int multiply = 1;

        while (n) {
            int mod = n % decimal;

            if (mod < half & n >= decimal) {
                n -= decimal;
                mod += decimal;
            }

            
            if (mod & 0x1) {
                ans.front() +=  multiply;
            }
            
            ans.front() += mod / half * multiply;
            ans.back() += mod / half * multiply;
            n /= decimal;
            multiply *= decimal;
        }
        
        return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2);
        function<bool(int)> check = [](int num) {
            const int decimal = 10;
            
            while (num != 0) {
                int mod = num % decimal;
                if (mod == 0) {
                    return false;
                }
                num /= decimal;
            }
            
            return true;
        };
        
        for (int a = 1; a < n; a++) {
            if (check(a) == true) {
                int b = n - a;
                if (check(b) == true) {
                    ans = move(vector<int> {a, b});
                    break;
                }
            }
        }
        return ans;
    }
};