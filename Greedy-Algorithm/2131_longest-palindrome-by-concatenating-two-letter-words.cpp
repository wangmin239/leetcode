/* Original Solution 1 */
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> strCnt;
        
        for (const string& word : words) {
            ++strCnt[word];
        }
        
        int count = 0;
        int palindCnt = 0;
        
        for (auto& [str, cnt] : strCnt) {
            /* The word is palindrome */
            if (str[0] == str[1]) {
                count += cnt / 2;
                palindCnt += cnt % 2;
            } else {
                /* is there a palindrome word matching the current word */
                string palindStr(2, str[1]);
                palindStr[1] = str[0];
                
                if (strCnt.count(palindStr) && strCnt[palindStr] > 0) {
                    int minCnt = min(cnt, strCnt[palindStr]);
                    count += minCnt;
                    strCnt[palindStr] -= minCnt;
                    cnt -= minCnt;
                }
            }
        }
        
        return 2 * 2 * count + 2 * (palindCnt == 0 ? 0 : 1);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;   // 单词出现次数
        for (const string& word: words) {
            ++freq[word];
        }
        int res = 0;   // 最长回文串长度
        bool mid = false;   // 是否含有中心单词
        for (const auto& [word, cnt]: freq) {
            // 遍历出现的单词，并更新长度
            string rev = string(1, word[1]) + word[0];   // 反转后的单词
            if (word == rev) {
                if (cnt % 2 == 1) {
                    mid = true;
                }
                res += 2 * (cnt / 2 * 2);
            }
            else if (word > rev) {   // 避免重复遍历
                res += 4 * min(freq[word], freq[rev]);
            }
        }
        if (mid) {
            // 含有中心单词，更新长度
            res += 2;
        }
        return res;
    }
};
