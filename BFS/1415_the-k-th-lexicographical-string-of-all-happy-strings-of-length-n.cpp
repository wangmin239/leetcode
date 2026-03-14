/* Original Solution 1 */
class Solution {
public:
    string getHappyString(int n, int k) {
        const int chNum = 3;
        int maxCnt = chNum << (n - 1);

        if (k > maxCnt) {
            return "";
        }

        const char chArr[chNum] = {'a', 'b', 'c'};
        string ans(n, 'a');
        string happyStr(n, 'a');
        
        auto dfs = [&] (int pos, int index, auto&& self, int& cnt) {
            if (pos == n) {
                ++cnt;
                if (cnt == k) {
                    happyStr = ans;
                }
                return;
            }

            for (int i = 0; i < chNum; i++) {
                if (i == index) {
                    continue;
                }
                ans[pos] = chArr[i];
                self(pos + 1, i, self, cnt);
                   
            }
        };
        int cnt = 0;
        dfs(0, chNum, dfs, cnt);
        return happyStr;

    }
};


/* Official Solution 1 */
class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3 << (n - 1)) {
            return "";
        }
        k--; // 改成从 0 开始，方便计算
        string ans(n, 'a');
        ans[0] += k >> (n - 1);
        for (int i = 1; i < n; i++) {
            ans[i] += k >> (n - 1 - i) & 1;
            if (ans[i] >= ans[i - 1]) {
                ans[i]++;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<char> chs = {'a', 'b', 'c'};
        string res;
        if (k > 3 * (1 << (n - 1))) {
            return res;
        }
        for (int i = 0; i < n; i++) {
            int count = 1 << (n - i - 1);
            for (char c : chs) {
                if (!res.empty() && res.back() == c) {
                    continue;
                }
                if (k <= count) {
                    res.push_back(c);
                    break;
                }
                k -= count;
            }
        }
        return res;
    }
};
