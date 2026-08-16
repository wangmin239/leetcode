/* Official Solution 1 */
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val: stones) {
            if (int type = val % 3; type == 0) {
                ++cnt0;
            }
            else if (type == 1) {
                ++cnt1;
            }
            else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};

/* Official Solution 2 */
class Solution {
private:
    bool check(int n, int cnt[3]) {
        if (cnt[1] == 0) {
            return false;
        }
        cnt[1]--;
        // 第一回合 Alice 移除 1，后面两人交替移除 1 和 2，中途可以插入 cnt[0] 个 0
        int rounds = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0];
        if (cnt[1] > cnt[2]) { // 可以再移除一个 1
            rounds++;
        }
        return rounds < n && rounds % 2 > 0;
    }

public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]{};
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int n = stones.size();
        // 小技巧：交换 cnt[1] 和 cnt[2] 再调用 check，相当于 Alice 第一回合移除了 2
        int cnt2[3] = {cnt[0], cnt[2], cnt[1]};
        return check(n, cnt) || check(n, cnt2);
    }
};
