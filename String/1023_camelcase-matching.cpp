class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n, true);
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (auto c : queries[i]) {
                if (p < pattern.size() && pattern[p] == c) {
                    p++;
                } else if (isupper(c)) {
                    res[i] = false;
                    break;
                }
            }
            if (p < pattern.size()) {
                res[i] = false;
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int size = queries.size();
        vector<bool> ans(size, false);
        int index = 0;
        for (auto&& query : queries) {
            ans[index] = isMatch(query, pattern);
            ++index;
        }
        return ans;
    }
    
    bool isMatch(string& query, string& pattern) {
        int patternLen = pattern.length();
        int i = 0;
        
        for (char ch : query) {
            if (i < patternLen && ch == pattern[i]) {
                ++i;
                continue;
            } 
            if(isupper(ch)) {
                return false;
            }
        }

        return i == patternLen;
    }
    
};