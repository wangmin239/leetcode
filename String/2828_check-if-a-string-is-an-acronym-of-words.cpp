class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        
        if (s.length() != words.size()) {
            return false;
        }
        int i = 0;
        for (auto& word : words) {
            if (word[0] != s[i++]) {
                return false;
            }
        }
        
        return true;
    }
};


class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int len = s.length();
        int size = words.size();
        
        if (len != size) {
            return false;
        }
        
        for (int i = 0; i < len; i++) {
            if (s[i] != words[i].front()) {
                return false;
            }
        }
        
        return true;
    }
};