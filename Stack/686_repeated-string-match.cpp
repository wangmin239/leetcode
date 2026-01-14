class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        auto lenA = a.length();
        auto lenB = b.length();
        
        int multiple = lenB / lenA + 3;
        
        string multiStr(a);
        for (int i = 1; i < multiple; i++) {
            auto matchPos = multiStr.find(b, 0);
            if (matchPos == string::npos) {
                multiStr += a;
            } else {
                return i;
            }
        }

        return -1;     
        
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }

        long long k1 = 1e9 + 7;
        long long k2 = 1337;
        srand((unsigned)time(NULL));
        long long kMod1 = rand() % k1 + k1;
        long long kMod2 = rand() % k2 + k2;

        long long hash_needle = 0;
        for (auto c : needle) {
            hash_needle = (hash_needle * kMod2 + c) % kMod1;
        }
        long long hash_haystack = 0, extra = 1;
        for (int i = 0; i < m - 1; i++) {
            hash_haystack = (hash_haystack * kMod2 + haystack[i % n]) % kMod1;
            extra = (extra * kMod2) % kMod1;
        }
        for (int i = m - 1; (i - m + 1) < n; i++) {
            hash_haystack = (hash_haystack * kMod2 + haystack[i % n]) % kMod1;
            if (hash_haystack == hash_needle) {
                return i - m + 1;
            }
            hash_haystack = (hash_haystack - extra * haystack[(i - m + 1) % n]) % kMod1;
            hash_haystack = (hash_haystack + kMod1) % kMod1;
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        int an = a.size(), bn = b.size();
        int index = strStr(a, b);
        if (index == -1) {
            return -1;
        }
        if (an - index >= bn) {
            return 1;
        }
        return (bn + index - an - 1) / an + 2;
    }
};



class Solution {
public:
    int strStr(string &haystack, string &needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i - j < n; i++) { // b 开始匹配的位置是否超过第一个叠加的 a
            while (j > 0 && haystack[i % n] != needle[j]) { // haystack 是循环叠加的字符串，所以取 i % n
                j = pi[j - 1];
            }
            if (haystack[i % n] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        int an = a.size(), bn = b.size();
        int index = strStr(a, b);
        if (index == -1) {
            return -1;
        }
        if (an - index >= bn) {
            return 1;
        }
        return (bn + index - an - 1) / an + 2;
    }
};
