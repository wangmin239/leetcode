/* Original Solution 1 */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int upLimit = 1000000000;
        unordered_map<int, int> freq;
        int ans = 0;

        for (int num : nums) {
            ++freq[num];
        }

        for (auto& [num, cnt] : freq) {

            if (num == 1) {
                ans = max(ans, cnt & 0x1 ? cnt : cnt - 1);
                continue;
            }

            long long curNum = num;
            int curCnt = cnt;
            int steps = 1;

            while (curCnt > 1 && curNum < upLimit) {
                curNum *= curNum;
                if (freq.count(curNum) == 0) {
                    break;
                }

                curCnt = freq[curNum];
                ++steps;
            }

             ans = max(ans, 2 * steps - 1);

        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        int ans = 0;
        // ans 至少是 1 的数量，向下取奇数
        if (cnt[1] % 2 == 0) {
            ans = cnt[1] - 1;
        } else {
            ans = cnt[1];
        }
        cnt.erase(1);
        for (auto& [num, _] : cnt) {
            int res = 0;
            long long x = num;
            for (; cnt.contains(x) && cnt[x] > 1; x *= x) {
                res += 2;
            }
            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
        }
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }

        int ans = (cnt[1] - 1) | 1; // 保证 ans 是奇数（奇数不变，偶数减一）
        cnt.erase(1);

        for (auto& [num, _] : cnt) {
            int res = 0;
            auto x = num;
            while (cnt.contains(x) && cnt[x] >= 2) {
                res += 2;
                x *= x;
            }
            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
        }

        return ans;
    }
};
