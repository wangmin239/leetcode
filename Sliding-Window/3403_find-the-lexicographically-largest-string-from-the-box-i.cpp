/* Origial Solution 1 */
class Solution {
public:
    string answerString(string word, int numFriends) {
        int len = word.length();
        int maxSplit = len - numFriends + 1;
        
        /**/
        if (numFriends == 1) {
            return word;
        }
        /* Initialize the first splited string */
        string ans(word.substr(0, maxSplit));
        
        for (int i = 1; i < len; i++) {
            if (word[i] < ans.front()) {
                continue;
            }
            int curLen = min(maxSplit, len - i);
            string curSplit(word.substr(i, curLen));
            
            ans = max(ans, curSplit);
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
        }
        return res;
    }
};

/* Official Solution 2 */
class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = s.size();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substr(i, n - i);
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        string last = lastSubstring(word);
        int n = word.size(), m = last.size();
        return last.substr(0, min(m, n - numFriends + 1));
    }
};
