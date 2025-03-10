
/* Original Solution */
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int value = num;
        const int dec= 10;
        int divisor = 0;
        long multi = 1;
        int ans = 0;

        for (int i = 0; num != 0; num /= 10, i++) {
            divisor += (num % dec) * multi;
            multi *= dec;
            if (i < k - 1) {
                continue;
            }
            
            if (divisor && (value % divisor == 0)) {
                ++ans;
            }
            divisor /= 10;
            multi /= 10;
        }
        
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);   // num 十进制表示字符串
        int n = s.size();
        int res = 0;
        for (int i = 0; i <= n - k; ++i) {
            // 枚举所有长度为 k 的子串
            int tmp = stoi(s.substr(i, k));
            if (tmp && num % tmp == 0) {
                ++res;
            }
        }
        return res;
    }
};
