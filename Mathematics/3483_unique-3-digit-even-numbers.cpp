
/* Original Solution 1 */
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<bool> visited(n, false);
        const int decimal = 10;
        const int digitNum = 3;
        vector<vector<bool>> tripleDigits(digitNum, vector<bool>(decimal, 0));

        auto dfs = [&](int field, vector<vector<bool>> fillDigits, auto&& self) {
            int sum = 0;

            if (field == 0) {
                return 1;
            }

            for (int i = 0; i < n; i++) {
                if (visited[i] == true) {
                    continue;
                }

                if ((field == 3 && digits[i] == 0) || (field == 1 && (digits[i] & 0x1))) {
                    continue;
                }

                if (fillDigits[field - 1][digits[i]]) {
                    continue;
                }

                visited[i] = true;
                fillDigits[field - 1][digits[i]] = true;
                sum += self(field - 1, fillDigits, self);
                visited[i] = false;

            }

            return sum;
        };

        return dfs(digitNum, tripleDigits, dfs);
    }
};


/* Official Solution 1 */
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        bool vis[1000]{};
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j || digits[k] % 2 != 0) {
                        continue;
                    }
                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (!vis[x]) {
                        vis[x] = true;
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10]{};
        for (int d : digits) {
            cnt[d]++;
        }

        int non_zeros = 0, kinds = 0, singles = 0;
        for (int d = 0; d < 10; d++) {
            if (cnt[d] == 0) {
                continue;
            }
            kinds++;
            if (d > 0) {
                non_zeros++;
                singles += cnt[d] == 1;
            }
        }

        int ans = 0;

        // 枚举个位填偶数 d
        for (int d = 0; d < 10; d += 2) {
            int c = cnt[d];
            if (c == 0) {
                continue;
            }

            // 十位填任意数字
            int k = kinds - (c == 1);

            // 百位填任意非零数字
            int nz = non_zeros - (d > 0 && c == 1);

            // 恰好出现一次的非零数字，不能同时填入十位和百位
            int s = singles;
            if (d > 0) {
                if (c == 1) {
                    s--;
                } else if (c == 2) {
                    s++; // 个位数填入 d 后，d 恰好出现一次
                }
            }

            ans += k * nz - s;
        }

        return ans;
    }
};
