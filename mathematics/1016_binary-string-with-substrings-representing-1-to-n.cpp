class Solution {
public:
    bool help(const string& s, int k, int mi, int ma) {
        unordered_set<int> st;
        int t = 0;
        for (int r = 0; r < s.size(); ++r) {
            t = t * 2 + (s[r] - '0');
            if (r >= k) {
                t -= (s[r - k] - '0') << k;
            }
            if (r >= k - 1 && t >= mi && t <= ma) {
                st.insert(t);
            }
        }
        return st.size() == ma - mi + 1;
    }

    bool queryString(string s, int n) {
        if (n == 1) {
            return s.find('1') != -1;
        }
        int k = 30;
        while ((1 << k) >= n) {
            --k;
        }
        if (s.size() < (1 << (k - 1)) + k - 1 || s.size() < n - (1 << k) + k + 1) {
            return false;
        }
        return help(s, k, 1 << (k - 1), (1 << k) - 1) && help(s, k + 1, 1 << k, n);
    }
};


class Solution {
public:
    bool queryString(string s, int n) {
        auto covertBinaryStr = [](int digit) {
            const int len = 32;
            char binaryArr[len] = {'0'};
            int i = len;
            
            while (digit != 0) {
                int mod = digit % 2;
                binaryArr[ --i ] = (mod == 0 ? '0' : '1');
                digit /= 2;
            }
            
            return string(binaryArr + i, len - i);
        };
        for (int i = 1; i <= n; i++) {
            string binaryStr(covertBinaryStr(i));
            if (s.find(binaryStr) == string::npos) {
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool queryString(string s, int n) {
        auto covertBinaryStr = [](int digit) {
            string binaryStr = bitset<32>(digit).to_string();
            int i;
            for (i = 0; i < 32; i++) {
                if (binaryStr[i] != '0') {
                    break;
                }
            }
            return binaryStr.substr(i);
        };
        for (int i = 1; i <= n; i++) {
            string binaryStr(covertBinaryStr(i));
            if (s.find(binaryStr) == string::npos) {
                return false;
            }
        }
        return true;
    }
};