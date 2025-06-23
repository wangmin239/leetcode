
/* Official Solution 1 */
class Solution {
private:
    int digit[100];

public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int length = -1;
            while (x) {
                ++length;
                digit[length] = x % k;
                x /= k;
            }
            for (int i = 0, j = length; i < j; ++i, --j) {
                if (digit[i] != digit[j]) {
                    return false;
                }
            }
            return true;
        };

        int left = 1, count = 0;
        long long ans = 0;
        while (count < n) {
            int right = left * 10;
            // op = 0 表示枚举奇数长度回文，op = 1 表示枚举偶数长度回文
            for (int op = 0; op < 2; ++op) {
                // 枚举 i'
                for (int i = left; i < right && count < n; ++i) {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(combined)) {
                        ++count;
                        ans += combined;
                    }
                }
            }
            left = right;
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
private:
    static constexpr long long ans[][30] = {
        {1, 3, 5, 7, 9, 33, 99, 313, 585, 717, 7447, 9009, 15351, 32223, 39993, 53235, 53835, 73737, 585585, 1758571, 1934391, 1979791, 3129213, 5071705, 5259525, 5841485, 13500531, 719848917, 910373019, 939474939},
        {1, 2, 4, 8, 121, 151, 212, 242, 484, 656, 757, 29092, 48884, 74647, 75457, 76267, 92929, 93739, 848848, 1521251, 2985892, 4022204, 4219124, 4251524, 4287824, 5737375, 7875787, 7949497, 27711772, 83155138},
        {1, 2, 3, 5, 55, 373, 393, 666, 787, 939, 7997, 53235, 55255, 55655, 57675, 506605, 1801081, 2215122, 3826283, 3866683, 5051505, 5226225, 5259525, 5297925, 5614165, 5679765, 53822835, 623010326, 954656459, 51717171715},
        {1, 2, 3, 4, 6, 88, 252, 282, 626, 676, 1221, 15751, 18881, 10088001, 10400401, 27711772, 30322303, 47633674, 65977956, 808656808, 831333138, 831868138, 836131638, 836181638, 2512882152, 2596886952, 2893553982, 6761551676, 12114741121, 12185058121},
        {1, 2, 3, 4, 5, 7, 55, 111, 141, 191, 343, 434, 777, 868, 1441, 7667, 7777, 22022, 39893, 74647, 168861, 808808, 909909, 1867681, 3097903, 4232324, 4265624, 4298924, 4516154, 4565654},
        {1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596, 9470749, 61255216, 230474032, 466828664, 485494584, 638828836, 657494756, 858474858, 25699499652, 40130703104, 45862226854, 61454945416, 64454545446},
        {1, 2, 3, 4, 5, 6, 7, 9, 121, 292, 333, 373, 414, 585, 3663, 8778, 13131, 13331, 26462, 26662, 30103, 30303, 207702, 628826, 660066, 1496941, 1935391, 1970791, 4198914, 55366355},
        {1, 2, 3, 4, 5, 6, 7, 8, 191, 282, 373, 464, 555, 646, 656, 6886, 25752, 27472, 42324, 50605, 626626, 1540451, 1713171, 1721271, 1828281, 1877781, 1885881, 2401042, 2434342, 2442442}
    };

public:
    long long kMirror(int k, int n) {
        return accumulate(ans[k - 2], ans[k - 2] + n, 0LL);
    }
};

const int MAX_N = 30;
vector<long long> ans[10];

// 力扣 9. 回文数
bool is_k_palindrome(long long x, int k) {
    if (x % k == 0) {
        return false;
    }
    int rev = 0;
    while (rev < x / k) {
        rev = rev * k + x % k;
        x /= k;
    }
    return rev == x || rev == x / k;
}

bool do_palindrome(long long x) {
    bool done = true;
    for (int k = 2; k < 10; k++) {
        if (ans[k].size() < MAX_N && is_k_palindrome(x, k)) {
            ans[k].push_back(x);
        }
        if (ans[k].size() < MAX_N) {
            done = false;
        }
    }
    if (!done) {
        return false;
    }

    for (int k = 2; k < 10; k++) {
        // 原地求前缀和
        partial_sum(ans[k].begin(), ans[k].end(), ans[k].begin());
    }
    return true;
}

auto init = []() {
    for (int base = 1; ; base *= 10) {
        // 生成奇数长度回文数，例如 base = 10，生成的范围是 101 ~ 999
        for (int i = base; i < base * 10; i++) {
            long long x = i;
            for (int t = i / 10; t > 0; t /= 10) {
                x = x * 10 + t % 10;
            }
            if (do_palindrome(x)) {
                return 0;
            }
        }
        // 生成偶数长度回文数，例如 base = 10，生成的范围是 1001 ~ 9999
        for (int i = base; i < base * 10; i++) {
            long long x = i;
            for (int t = i; t > 0; t /= 10) {
                x = x * 10 + t % 10;
            }
            if (do_palindrome(x)) {
                return 0;
            }
        }
    }
}();

class Solution {
public:
    long long kMirror(int k, int n) {
        return ans[k][n - 1];
    }
};
