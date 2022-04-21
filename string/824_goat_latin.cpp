class Solution {
public:
    string toGoatLatin(string sentence) {
        auto isVowel = [](const string& str) {
            string pattern("aeiouAEIOU");
            
            for (const char& ch : pattern) {
                if (ch == str[0]){
                    return true;
                }
            }
            return false;
        };
        
        string ans;
        int prevPos = 0;
        int index = 1;
        while (prevPos < sentence.length()) {
            int curPos = sentence.find(' ', prevPos);
            if (curPos == string::npos) {
                curPos = sentence.length();
            }
            string subStr(sentence.substr(prevPos, curPos - prevPos));
            
            if (isVowel(subStr) == false) {
                circleReplace(subStr);
            }
            
            subStr.append("ma" + string(index++, 'a'));
            prevPos = curPos + 1;
            if ( prevPos < sentence.length()) {
                subStr.push_back(' ');
            }
            ans += subStr;
        }
        
        return ans;      
    }
    
    void inline circleReplace(string& str) {
        char firstCh = str.front();
        int len = str.length();
        for (int i = 1; i < len; i++) {
            str[i - 1] = str[i];
        }            
        str[len - 1] = firstCh;
        return;
    }
};


class Solution {
public:
    string toGoatLatin(string sentence) {
        auto isVowel = [](const string& str) {
            string pattern("aeiouAEIOU");
            
            for (const char& ch : pattern) {
                if (ch == str[0]){
                    return true;
                }
            }
            return false;
        };
        
        string ans;
        int index = 1;
        char* pch;
        pch = strtok(const_cast<char*>(sentence.c_str()), " ");
        while (pch != nullptr) {

            string subStr(pch);
            
            if (isVowel(subStr) == false) {
                circleReplace(subStr);
            }
            
            subStr.append("ma" + string(index++, 'a') + " ");
            ans += subStr;
            pch = strtok(nullptr, " ");
        }
        ans.pop_back();
        return ans;      
    }
    
    void inline circleReplace(string& str) {
        char firstCh = str.front();
        int len = str.length();
        for (int i = 1; i < len; i++) {
            str[i - 1] = str[i];
        }            
        str[len - 1] = firstCh;
        return;
    }
};


class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = sentence.size();
        int i = 0, cnt = 1;
        string ans;

        while (i < n) {
            int j = i;
            while (j < n && sentence[j] != ' ') {
                ++j;
            }

            ++cnt;
            if (cnt != 2) {
                ans += ' ';
            }
            if (vowels.count(sentence[i])) {
                ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
            }
            else {
                ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(cnt, 'a');
            }

            i = j + 1;
        }

        return ans;
    }
};
