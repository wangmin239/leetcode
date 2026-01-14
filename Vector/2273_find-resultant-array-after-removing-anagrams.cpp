/* Original Solution 1 */
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_set<string>  uniqStr;
        vector<string> ans;
        int n = words.size();
        
        for (int i = 0; i < n; ) {
            string tmp(words[i]);
            
            ans.push_back(words[i]);
            sort(tmp.begin(), tmp.end());
            
            while (++i < n) {
                string nextStr(words[i]);
                sort(nextStr.begin(), nextStr.end());
                if (tmp != nextStr) {
                    break;
                }
            }

        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res = {words[0]};   // 结果数组
        int n = words.size();
        // 判断两个单词是否为字母异位词
        auto compare = [](const string& word1, const string& word2) -> bool {
            vector<int> freq(26);
            for (char ch: word1) {
                ++freq[ch-'a'];
            }
            for (char ch: word2) {
                --freq[ch-'a'];
            }
            return all_of(freq.begin(), freq.end(), [](int x) { return x == 0; });
        };

        for (int i = 1; i < n; ++i) {
            if (compare(words[i], words[i-1])) {
                continue;
            }
            res.push_back(words[i]);
        }
        return res;
    }
};
