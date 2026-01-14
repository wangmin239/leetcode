class Solution {
public:
    vector<string_view> split(const string_view &str, char trim) {
        int n = str.size();
        vector<string_view> res;
        int pos = 0;
        while (pos < n) {
            while(pos < n && str[pos] == trim) {
                pos++;
            }
            if (pos < n) {
                int curr = pos;
                while(pos < n && str[pos] != trim) {
                    pos++;
                }
                res.emplace_back(str.substr(curr, pos - curr));
            }
        }
        return res;
    }

    string reorderSpaces(string text) {
        int length = text.size();
        vector<string_view> words = split(text, ' ');
        int cntSpace = length;
        int wordCount = 0;
        for (auto &word : words) {
            if (word.size() > 0) {
                cntSpace -= word.size();
                wordCount++;
            }
        }

        string ans;
        if (words.size() == 1) {
            ans.append(words[0]);
            for (int i = 0; i < cntSpace; i++) {
                ans.push_back(' ');
            }
            return ans;
        }
        int perSpace = cntSpace / (wordCount - 1);
        int restSpace = cntSpace % (wordCount - 1);
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == 0) {
                continue;
            }
            if (ans.size() > 0) {
                for (int j = 0; j < perSpace; j++) {
                    ans.push_back(' ');
                }
            }
            ans.append(words[i]);
        }
        for (int i = 0; i < restSpace; i++) {
            ans.push_back(' ');
        }
        return ans;
    }
};




class Solution {
public:
    int parseString(const string& text, vector<string>& words) {
        int bankCnt = 0;
        int len = text.length();
        
        for (int i = 0; i < len; ) {
            while (text[i] == ' ') {
                bankCnt++;
                i++;
            }
            
            string tmpStr;
            while (i < len && isalpha(text[i])) {
                    tmpStr.push_back(text[i++]);
            }
            
            if (tmpStr.empty() == false) {
                words.push_back(tmpStr);
            }
        }
        return bankCnt;
    }
    
    
    string reorderSpaces(string text) {
        vector<string> words;
        int bankCnt = parseString(text, words);
        int wordCnt = words.size();
        int len = text.length();
        string ans(len, ' ');
        
        ans.replace(0, words.front().length(), words.front());
        
        if (wordCnt == 1) {
            return ans;
        }
        
        int wordDistance = bankCnt / (wordCnt - 1);
        int pos = words.front().length() + wordDistance;
        for (int i = 1; i < wordCnt; i++) {
            ans.replace(pos, words[i].length(), words[i]);
            pos += words[i].length() + wordDistance;
        }
        
        return ans;
    }
};