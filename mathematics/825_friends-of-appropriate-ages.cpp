class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int cnt = 0;
        int n = ages.size();
        const int limit = 121;
        int ageArr[limit] = {0};
        
        fill(ageArr, ageArr + limit, 0);
        auto check = [](int x, int y) {
            if (1.0 * y <= (0.5 * x + 7.0)  || (y > 100 && x < 100)) {
                return false;
            }
            return true;
        };
        
        for (int age : ages) {
            ++ageArr[age];
        }
        
        for (int i = 1; i < limit; i++) {
            for (int j = i + 1; j < limit; j++) {

                if (check(j, i) == true) {
                    cnt += ageArr[i] * ageArr[j];
                }
            }

            if (check(i, i) == true) {
                cnt += ageArr[i] * (ageArr[i] - 1);
            }
        }
        
        return cnt;
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int left = 0, right = 0, ans = 0;
        for (int age: ages) {
            if (age < 15) {
                continue;
            }
            while (ages[left] <= 0.5 * age + 7) {
                ++left;
            }
            while (right + 1 < n && ages[right + 1] <= age) {
                ++right;
            }
            ans += right - left;
        }
        return ans;
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121);
        for (int age: ages) {
            ++cnt[age];
        }
        vector<int> pre(121);
        for (int i = 1; i <= 120; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        int ans = 0;
        for (int i = 15; i <= 120; ++i) {
            if (cnt[i]) {
                int bound = i * 0.5 + 8;
                ans += cnt[i] * (pre[i] - pre[bound - 1] - 1);
            }
        }
        return ans;
    }
};
