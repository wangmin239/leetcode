class Solution {
public:
    int countValidWords(string sentence) {
        int wordCnt = 0;
        int len = sentence.length();
        
        for (int i = 0; i < len; i++) {
            int start = i;
            while (i < len && sentence[i] != ' ') {
                i++;
            }
            if (i == start) {
                continue;
            }
            
            if (check(sentence.substr(start, i - start)) == true) {
                wordCnt++;
            }
        }
        
        return wordCnt;
    }
    
    bool check(const string& str) {
        int len = str.length();
        int cnt = 0;

        if (isalpha(str[0]) == false && len > 1) {
            return false;
        }

        
        for (int i = 0; i < len; i++) {
           if (isdigit(str[i]) == true) {
                return false;
           }

           if (str[i] == '-') {
               cnt++;
               if (i + 1 < len && isalpha(str[i + 1]) == false) {
                   return false;
               }
               continue;
           }
           
           if (i != len - 1 && isalpha(str[i]) == false) {
               return false;
           }
        }
        
        if (cnt > 1 || str[len - 1] == '-') {
            return false;
        }
        
        return true;
    }
};


class Solution {
public:
    int countValidWords(string sentence) {
        int n = sentence.length();
        int l = 0, r = 0;
        int ret = 0;
        string_view slice(sentence);
        while (true) {
            while (l < n && sentence[l] == ' ') {
                l++;
            }
            if (l >= n) {
                break;
            }
            r = l + 1;
            while (r < n && sentence[r] != ' ') {
                r++;
            }
            if (isValid(slice.substr(l, r - l))) { // 判断根据空格分解出来的 token 是否有效
                ret++;
            }
            l = r + 1;
        }
        return ret;
    }

    bool isValid(const string_view &word) {
        int n = word.length();
        bool has_hyphens = false;
        for (int i = 0; i < n; i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                return false;
            } else if (word[i] == '-') {
                if (has_hyphens == true || i == 0 || i == n - 1 || !islower(word[i - 1]) || !islower(word[i + 1])) {
                    return false;
                }
                has_hyphens = true;
            } else if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                if (i != n - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

