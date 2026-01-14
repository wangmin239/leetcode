class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto is_subseq = [](const string& s, const string& t) -> bool {
            int pt_s = 0, pt_t = 0;
            while (pt_s < s.size() && pt_t < t.size()) {
                if (s[pt_s] == t[pt_t]) {
                    ++pt_s;
                }
                ++pt_t;
            }
            return pt_s == s.size();
        };

        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && is_subseq(strs[i], strs[j])) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = max(ans, static_cast<int>(strs[i].size()));
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_set<string> specialStr;
        size_t maxLen = -1;
        size_t len = strs.size();

        
        sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs) {
            return lhs.length() < rhs.length();
        });
        
        for (size_t i = 0; i < len; i++) {
            if (specialStr.count(strs[i])) {
                continue;
            }
            specialStr.insert(strs[i]);
            bool isSpecial = true;
            for (size_t j = i + 1; j < len; j++) {
                if (isSubStr(strs[i], strs[j]) == true) {
                    isSpecial = false;
                    break;
                }
            }
            
            if (isSpecial == true) {
                maxLen = strs[i].length();
            }
        }


        return static_cast<int>(maxLen);
    }
    
    bool isSubStr(const string& pattern, const string& str) {
        int strLen = str.length();
        int len = pattern.length();
        int j = 0;
        
        for (int i = 0; i < strLen; i++) {
            if (j < len && str[i] == pattern[j]) {
                j++;
            }
        }
        
        return j == len;
    }
};
