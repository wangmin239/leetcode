/* Original Solution 1 */
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        const int num = 26;
        int chArr[num] = {0};
        
        for (char ch : brokenLetters) {
            int id = ch - 'a';
            chArr[id] = 1;
        }
        
        int len = text.length();
        int cnt = 0;
        
        for (int i = 0; i < len; i++) {
            bool hasBrokenCh = false;
            while (i < len && text[i] != ' ') {
                int id = text[i++] - 'a';
                if (chArr[id] == 1) {
                    hasBrokenCh = true;
                }
            }
            
            if (hasBrokenCh == false) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream iss(text);
        string word;
        int ans = 0;
        while (iss >> word) {
            if (ranges::all_of(word, [&](char c){ return brokenLetters.find(c) == string::npos; })) {
                ans++;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;   // 无法输入的字符集合
        for (char ch: brokenLetters){
            broken.insert(ch);
        }
        int res = 0;   // 可以完全输入的单词数目
        bool flag = true;   // 当前字符所在单词是否可被完全输入
        for (char ch: text){
            if (ch == ' '){
                // 当前字符为空格，检查上一个单词状态，更新数目并初始化 flag
                if (flag){
                    ++res;
                }
                flag = true;
            }
            else if (broken.count(ch)){
                // 当前字符不可被输入，所在单词无法被完全输入，更新 flag
                flag = false;
            }
        }
        // 判断最后一个单词状态并更新数目
        if (flag){
            ++res;
        }
        return res;
    }
};
