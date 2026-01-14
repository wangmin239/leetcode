class Solution {
public:
    string removeStars(string s) {
        string res;
        for (char c : s) {
            if (c == '*') {
                res.pop_back();
            } else {
                res += c;
            }
        }
        return res;
    }
};


class Solution {
public:
    string removeStars(string s) {
        string ans;
        
        for (char ch : s) {
            if (ch != '*') {
                ans.push_back(ch);
            } else {
                ans.pop_back();
            }
        }
        
        return ans;
    }
};




class Solution {
public:
    string removeStars(string s) {
        int len = s.length();
        int i = 0;
        for (int j = 0; j < len; j++) {
            if (s[j] != '*') {
                s[i++] = s[j];
            } else {
                --i;
            }
        }
                
        
        return s.substr(0, i);
    }
};