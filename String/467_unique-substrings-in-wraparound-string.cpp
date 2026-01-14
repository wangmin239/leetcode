class Solution {
public:
    int findSubstringInWraproundString(string p) {
        string str("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        int len = p.length();
        unordered_map<string, int> strMap;
        
        for (int i = 0; i < len; i++) {
            string tmp;
            string::size_type pos = 0;
            for (int j = i; j < len; j++) {
                tmp.push_back(p[j]);
                auto size = tmp.size();
                auto start = (size - 1)/26 * 26;
                
                if (size % 26 == 1) {
                    if (tmp[0] != tmp[start]) {
                        break;
                    }
                }
                pos = str.find(tmp.substr(start), pos);
                if (pos == string::npos) {
                    break;
                }
                
                if (strMap.count(tmp) > 0) {
                    continue;
                }
                ++strMap[tmp];
                
                if (tmp.length() <= 26) {
                    pos = 0;
                }
            }
        }
        return strMap.size();
    }
};


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < p.length(); ++i) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1) { // 字符之差为 1 或 -25
                ++k;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
