/* Original Solution */
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        int len = s.length();

        for (const auto& word : words) {
            int wordLen = word.length();
            
            if (len < wordLen) {
                continue;
            }
            
            bool isPrefix = true;
            for (int i = 0; i < wordLen; i++) {
                if (word[i] != s[i]) {
                    isPrefix = false;
                    break;
                }
            }
            cnt += isPrefix == true ? 1 : 0;
        }

        return cnt;
    }
};


/* Official Solution */
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;   // 符合要求字符串个数
        // 判断 word 是否是 s 的前缀
        auto isPrefix = [&](const string& word) -> bool {
            if (s.size() < word.size()) {
                return false;
            }
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != s[i]) {
                    return false;
                }
            }
            return true;
        };
        
        for (const string& word: words) {
            if (isPrefix(word)) {
                ++res;
            }
        }
        return res;
    }
};
