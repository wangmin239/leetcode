class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 0, pos = 0;
        while (pos < s.size()) {
            if (isdigit(s[pos])) {
                int cur = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    cur = cur * 10 + s[pos] - '0';
                    pos++;
                }
                if (cur <= pre) {
                    return false;
                }
                pre = cur;
            } else {
                pos++;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool areNumbersAscending(string s) {
        int len = s.length();
        int preVal = -1;
        
        for (int i = 0; i < len; i++) {
            if (!isdigit(s[i])) {
                continue;
            }
            
            int j = i;
            while (i < len && s[i] != ' ') {
                i++;
            }
            
            int curVal = stoi(s.substr(i, i - j));
            if (curVal <= preVal) {
                return false;
            }
            
            preVal = curVal;
        }
        
        return true;
    }
};



class Solution {
public:
    bool areNumbersAscending(string s) {
        int len = s.length();
        int preVal = -1;
        
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j < len && s[j] != ' ') {
                j++;
            }
            
            if (isdigit(s[i])) {
                int curVal = stoi(s.substr(i, j - i));
                if (curVal <= preVal) {
                    return false;
                }
                preVal = curVal;
            }
            i = j;   
        }
        
        return true;
    }
};