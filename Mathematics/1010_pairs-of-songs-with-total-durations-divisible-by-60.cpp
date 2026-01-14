class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (int t : time) {
            cnt[t % 60]++;
        }
        long long res = 0;
        for (int i = 1; i < 30; i++) {
            res += cnt[i] * cnt[60 - i];
        }            
        res += (long long)cnt[0] * (cnt[0] - 1) / 2 + (long long)cnt[30] * (cnt[30] - 1) / 2;
        return (int)res;
    }
};


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        const int modVal = 60;
        unique_ptr<int[]> cntPtr(new int [modVal]);
        auto ptr = cntPtr.get();
        fill_n(ptr, modVal, 0);
        for (const int& timeSpec : time) {
            int mod = timeSpec % modVal;
            int remain = (mod == 0 ? 0 : modVal - mod);

            if (ptr[remain] != 0) {
                cnt += ptr[remain];
            }
            
            ptr[mod]++;
        }
        return cnt;
    }
};


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        unordered_map<int, int> modInfo;
        const int modVal = 60;
        for (const int& timeSpec : time) {
            int mod = timeSpec % modVal;
            int remain = (mod == 0 ? 0 : modVal - mod);

            if (modInfo.count(remain) != 0) {
                cnt += modInfo[remain];
            }
            
            modInfo[mod]++;
        }
        return cnt;
    }
};