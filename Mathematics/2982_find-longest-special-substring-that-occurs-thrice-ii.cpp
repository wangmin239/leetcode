class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> cnt(26, vector<int>(3));
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }
            int index = s[i] - 'a';
            int len = j - i;
            if (len > cnt[index][0]) {
                cnt[index][2] = cnt[index][1];
                cnt[index][1] = cnt[index][0];
                cnt[index][0] = len;
            } else if (len > cnt[index][1]) {
                cnt[index][2] = cnt[index][1];
                cnt[index][1] = len;
            } else if (len > cnt[index][2]) {
                cnt[index][2] = len;
            }
        }
        
        int res = 0;
        for (auto vec : cnt) {
            res = max({res, vec[0] - 2, min(vec[0] - 1, vec[1]), vec[2]});
        }
        return res ? res : -1;
    }
};

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> cnt;
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }
            cnt[s[i]].emplace_back(j - i);
        }
        
        int res = -1;
        for (auto &[_, vec] : cnt) {
            int lo = 1, hi = n - 2;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int count = 0;
                for (int x : vec) {
                    if (x >= mid) {
                        count += x - mid + 1;
                    }
                }
                if (count >= 3) {
                    res = max(res, mid);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> strCnt;
        int len = s.length();
        
        /* Initialize the string map */
        for (int i = 0; i < len; ) {
            int cnt = 1;
            int j = i;
            /* get the length of the string that contains successive same character*/
            while (++i < len) {
                if (s[i] != s[j]) {
                    cnt = i - j;
                    break;
                }
            }
            
            if (i == len) {
                cnt = i - j;
            }
            
            /* construct a string by split the pattern string */
            for (int subLen = cnt; subLen > 0; subLen--) {
                string tmp(subLen, s[j]);
                strCnt[tmp] += cnt - subLen + 1;
                if (strCnt[tmp] > 2) {
                    break;
                }
            }
        }
        
        int maxLen = -1;
        for (const auto [str, freq] : strCnt) {
            if (freq < 3) {
                continue;
            }
            
            maxLen = max(maxLen, static_cast<int>(str.length()));
        }
        
        return maxLen;
    }
};