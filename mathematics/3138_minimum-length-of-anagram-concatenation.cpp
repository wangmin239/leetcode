class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        auto check = [&](int m) -> bool {
            vector<int> count0(26);
            for (int j = 0; j < n; j += m) {
                vector<int> count1(26);
                for (int k = j; k < j + m; k++) {
                    count1[s[k] - 'a']++;
                }
                if (j > 0 && count0 != count1) {
                    return false;
                }
                count0.swap(count1);
            }
            return true;
        };
        for (int i = 1; i < n; i++) {
            if (n % i != 0) {
                continue;
            }
            if (check(i)) {
                return i;
            }
        }
        return n;
    }
};













class Solution {
public:
    int minAnagramLength(string s) {
        const int charNum = 26;
        int charArr[charNum] = {0};
        
        for (char ch : s) {
            int index = static_cast<int>(ch - 'a');
            ++charArr[index];
        }
        
        /* get the min repeated times for every character */
        int minCnt = INT_MAX;
        for (int i = 0; i < charNum; i++) {
            if (charArr[i] > 0) {
                minCnt = min(minCnt, charArr[i]);
            }
        }
        

        /* form the min substring */
        int minLen = 0;
        int multipleChar[charNum] = {0};
        for (int i = 0; i < charNum; i++) {
            if (charArr[i] > 0) {
                if (charArr[i] % minCnt == 0) {
                    int multiple = charArr[i] / minCnt;
                    
                    minLen += multiple;
                    multipleChar[i] = multiple;
                } else {
                    return static_cast<int>(s.length());
                }
            }
        }
        
        /* Check equal */
        auto checkEqual = [charNum] (int tmp[charNum], int origin[charNum]) {
            for (int i = 0; i < charNum; i++) {
                if (tmp[i] != origin[i]) {
                    return false;
                }
            }
            return true;
        };        
        
        auto incrArr = [charNum] (int curArr[charNum], const int origin[charNum], const int k) {
            for (int i = 0; i < charNum; i++) {
                curArr[i] = origin[i] * k;
            }
        };

        int multi = static_cast<int>(s.length()) / minLen + 1;
        
        /* check substring equal to the origin substring */
        for (int k = 1; k < multi; k++) {
            bool isMatch = true;
            int curLen = minLen * k;
            int curCharArr[charNum] = {0};
            
            incrArr(curCharArr, multipleChar, k);
            for (int i = 0; i < static_cast<int>(s.length()); i += curLen) {
                int subStr[charNum] = {0};
                
                for (int j = 0; j < curLen; j++) {
                    int index = static_cast<int>(s[i + j] - 'a');
                    ++subStr[index];
                }
                
                if (checkEqual(subStr, curCharArr) == false) {
                    isMatch = false;
                    break;
                }  
            }
            
            if (isMatch == true) {
                return curLen;
            }
        }
        
        return static_cast<int>(s.length());
    }
};

