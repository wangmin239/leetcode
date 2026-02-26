/* Original Solution 1 */
class Solution {
public:
    int numSteps(string s) {
        int len = s.length();
        int steps = 0;

        auto operOdd = [&s](int index) {
            int incr = 1;
            const int mod = 2;
            int sum = 0;
            while (index >= 0) {
                sum = s[index] - '0' + incr;
                incr = sum / mod;
                s[index] = '0' + sum % mod;
                --index;
            }


            return incr;
        };

        auto shiftRight = [&](int index) {
            while (index > 0) {
                s[index] = s[index - 1];
                --index;
            }
            s[index] = '1';
        };

        for (int right = len - 1; right > 0; ) {
            /* The number is even */
            if (s[right] == '0') {
                right--;
                ++steps;
                continue;
            }
            /* The number is odd */
            ++steps;

            /* The most significant bit (MSB) of the number increments upon adding 1 */
            if (operOdd(right) == 1) {
                ++steps;
                shiftRight(right);
            }
        }

        return steps;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            ++steps;
            if (s.back() == '0') {
                // 偶数的情况
                s.pop_back();
            } else {
                // 第一步：找出最低位的 0
                // 第二步：把这个 0 变成 1，并将后面所有的 1 变成 0，这样就实现了 +1
                // 特别地，如果 s 中全是 1，那么会有额外的进位
                for (int i = s.size() - 1; i >= 0; --i) {
                    if (s[i] == '1') {
                        s[i] = '0';
                        if (i == 0) {
                            s = "1" + s;
                            break;
                        }
                    }
                    else {
                        s[i] = '1';
                        break;
                    }
                }
            }
        }
        return steps;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        // meet1 记录我们有没有遇见过字符 1
        bool meet1 = false;
        // 从后向前遍历字符
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                // 如果当前字符为 0，分为两种情况
                // (1) 还没有遇见过字符 1，那么这个 0 是字符串低位的 0，需要一次除二操作
                // (2) 遇见过字符 1，那么这个 0 会因为它右侧的某次加一操作变为 1，因此它需要一次加一和一次除二操作
                ans += (meet1 ? 2 : 1);
            }
            else {
                // 如果当前字符为 1，分为两种情况
                // (1) 还没有遇见过字符 1，那么这个 1 需要一次加一和一次除二操作
                //     这里需要考虑一种特殊情况，就是这个 1 是字符串最左侧的 1，它并不需要任何操作
                // (2) 遇见过字符 1，那么这个 1 会因为它右侧的某次加一操作变为 0，因此它只需要一次除二操作
                if (!meet1) {
                    if (i != 0) {
                        ans += 2;
                    }
                    meet1 = true;
                }
                else {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
