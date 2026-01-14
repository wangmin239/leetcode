class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int count[2] = {0};
            for (int j = i; j < n; ++j) {
                count[s[j] - '0']++;
                if (count[0] > k && count[1] > k) {
                    break;
                }
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt0 = 0, cnt1 = 0;
        int n = s.size();
        int ans = 0;
        for (int left = 0, right = 0; right < n; ++right) {
            if (s[right] == '0')
                cnt0++;
            else
                cnt1++;
            
            while ((left <= right) && (cnt0 > k && cnt1 > k)) {
                if (s[left] == '0')
                    cnt0--;
                else
                    cnt1--;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};


class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int length = s.length();
        int total = 0;
        int curLen = length;

        auto check = [k](const string& s, int start, const int end) {
            int zeroCnt = 0;
            int oneCnt = 0;
            
            while (start < end) {
                if (s[start] == '0') {
                    ++zeroCnt;
                } else {
                    ++oneCnt;
                }
                ++start;
            }
            
            if (zeroCnt <= k || oneCnt <= k) {
                return 1;
            }
            return 0;
        };
        
        while (curLen > 0) {
            for (int i = 0; i < length - curLen + 1; i++) {
                total += check(s, i, curLen + i);
            }
            curLen--;
        }
        
        return total;
    }
};




class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int length = s.length();
        int total = (1 + length) * length / 2;
        int curLen = length;

        auto checkInvalid = [k](const string& s, int start, const int end) {
            int zeroCnt = 0;
            int oneCnt = end - start;
            
            while (start < end) {
                if (s[start] == '0') {
                    ++zeroCnt;
                }
                ++start;
            }
            
            oneCnt -= zeroCnt;
            if (zeroCnt > k && oneCnt > k) {
                return 1;
            }
            return 0;
        };
        
        while (curLen > 1) {
            for (int i = 0; i < length - curLen + 1; i++) {
                total -= checkInvalid(s, i, curLen + i);
            }
            curLen--;
        }
        
        return total;
    }
};