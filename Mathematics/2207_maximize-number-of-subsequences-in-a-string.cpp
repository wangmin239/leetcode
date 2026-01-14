class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0;
        int cnt1 = 0, cnt2 = 0;
        for (char c: text) {
            if (c == pattern[1]) {
                res += cnt1;
                cnt2++;
            }
            if (c == pattern[0]) {
                cnt1++;
            }
        }
        return res + max(cnt1, cnt2);
    }
};




class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int len = text.length();
        int preCnt = 0;
        int suffixCnt = 0;
        
        /* calculate the frequency of the pattern's characters */
        for (int i = 0; i < len; i++) {
            if (text[i] == pattern[0]) {
                preCnt++;
            }
            
            if (text[i] == pattern[1]) {
                suffixCnt++;
            }
        }
        

        
        auto getCnt = [&](const string& str, const string& pattern) {
            long long total = 0;
            bool isFirst = false;

            if (preCnt > suffixCnt) {
                suffixCnt += 1;
            } else {
                isFirst = true;
            }
            
            for (int i = 0; i < len;) {
                int pre = 0;
                if (isFirst == true) {
                    isFirst = false;
                    pre = 1;
                }
                while (i < len && str[i] != pattern[1]) {
                    if (str[i] == pattern[0]) {
                        ++pre;
                    }
                    ++i;
                }
                
                total += static_cast<long long>(pre) * suffixCnt;
                int suffix = 0;
                while (i < len && str[i] != pattern[0]) {
                    if (str[i] == pattern[1]) {
                        ++suffix;
                    }
                    ++i;
                }
                suffixCnt -= suffix;
            }
            
            return total;
        };
        
        if (pattern[0] == pattern[1]) {
            return static_cast<long long>(1 + preCnt)*(preCnt) / 2;
        }       
        return getCnt(text, pattern);
    }
};




class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int len = text.length();
        string patStr(len, 0);
        int j = 0;
        

        for (int i = 0; i < len; i++) {
            if (text[i] == pattern[0] || text[i] == pattern[1]) {
                patStr[j++] = text[i];
            }
        }
        

        
        auto getCnt = [j](const string& str, const string& pattern) {
            long long total = 0;
            int preCnt = 0;
            
            for (char ch : str) {
                if (ch == pattern[0]) {
                    ++preCnt;
                }
            }
            int suffixCnt = j - preCnt;
            bool isFirst = false;
            if (preCnt > suffixCnt) {
                suffixCnt += 1;
            } else {
                isFirst = true;
            }
            
            for (int i = 0; i < j;) {
                int start = i;
                if (isFirst == true) {
                    isFirst = false;
                    start = -1;
                }
                while (i < j && str[i] == pattern[0]) {
                    i++;
                    
                }
                
                total += static_cast<long long>(i - start) * suffixCnt;
                start = i;
                while (i < j && str[i] == pattern[1]) {
                    i++;
                }
                suffixCnt -= i - start;
            }
            
            return total;
        };
        
        if (pattern[0] == pattern[1]) {
            return static_cast<long long>(1 + j)*j / 2;
        }       
        return getCnt(patStr, pattern);
    }
};



class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int len = text.length();
        string patStr(len + 2, 0);
        int j = 1;

        patStr[0] = pattern[0];
        for (int i = 0; i < len; i++) {
            if (text[i] == pattern[0] || text[i] == pattern[1]) {
                patStr[j++] = text[i];
            }
        }
        
        patStr[j] = pattern[1];
        

        
        auto getCnt = [&pattern](const string& str, int start, int end) {
            long long total = 0;
            
            while (start < end) {
                if (str[start++] != pattern[0]) {
                    continue;
                }
                int cnt = 0;
                for (int i = start; i <= end; i++) {
                    if (str[i] == pattern[1]) {
                        cnt++;
                    }
                }
                total += cnt;
            }
            return total;
        };
        
        if (pattern[0] == pattern[1]) {
            return static_cast<long long>((1 + j - 1))*(j - 1) / 2;
        }       
        return max(getCnt(patStr, 0, j - 1), getCnt(patStr, 1, j));
    }
};