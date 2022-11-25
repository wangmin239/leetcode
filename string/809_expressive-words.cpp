class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (const string& word: words) {
            if (expand(s, word)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    bool expand(const string& s, const string& t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                return false;
            }
            char ch = s[i];
            int cnti = 0;
            while (i < s.size() && s[i] == ch) {
                ++cnti;
                ++i;
            }
            int cntj = 0;
            while (j < t.size() && t[j] == ch) {
                ++cntj;
                ++j;
            }
            if (cnti < cntj) {
                return false;
            }
            if (cnti != cntj && cnti < 3) {
                return false;
            }
        }
        return i == s.size() && j == t.size();
    }
};



class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto comp = [](const string& pattern, const string& str) {
            int lenPattern = pattern.length();
            int lenStr = str.length();
            
            if (lenStr > lenPattern) {
                return false;
            }
            
            int i = 0; 
            int j = 0;
            
            while (i < lenPattern) { 
                if (str[j] != pattern[i]) {
                    return false;
                }
                
                int strChCnt = 1;
                int patterChCnt = 1;
                char ch = str[j];
                while(j < lenStr) {
                    if (ch == str[++j]) {
                        strChCnt++;
                    } else {
                        break;
                    }
                }
                
                while(i < lenPattern) {
                    if (ch == pattern[++i]) {
                        patterChCnt++;
                    } else {
                        break;
                    }
                }
                if (patterChCnt == strChCnt) {
                    continue;
                }                
                if (patterChCnt < strChCnt) {
                    return false;
                }
                    
                if (patterChCnt < 3) {
                    return false;
                }
            }
      
            return (i == lenPattern) && (j == lenStr);
        };

        int ans = 0;
        for (const auto& word : words) {
            if (comp(s, word) == true) {
                ans++;
            }
        }
        return ans;
    }
};