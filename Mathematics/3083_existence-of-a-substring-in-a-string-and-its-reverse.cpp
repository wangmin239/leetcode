class Solution {
public:
    bool isSubstringPresent(string s) {
        vector<int> h(26);
        for (int i = 0; i + 1 < s.size(); i++) {
            int x = s[i] - 'a';
            int y = s[i + 1] - 'a';
            h[x] |= 1 << y;
            if (h[y] >> x & 1) {
                return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool isSubstringPresent(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            string substr = s.substr(i, 2);
            reverse(substr.begin(), substr.end());
            if (s.find(substr) != string::npos) {
                return true;
            }
        }
        return false;
    }
};





class Solution {
public:
    bool isSubstringPresent(string s) {
        int len = s.length();
        unordered_set<string> strSet;
        
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                return true;
            }
            string twoCh(s.substr(i, 2));
            
            strSet.insert(twoCh);
            swap(twoCh.front(), twoCh.back());
            if (strSet.count(twoCh)) {
                return true;
            }
        }
        
        return false;
    }
};



class Solution {
public:
    bool isSubstringPresent(string s) {
        int len = s.length();
        
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                return true;
            }
            for (int j = i + 1; j < len - 1; j++) {
                if (s[i] == s[j + 1] && s[i + 1] == s[j]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};