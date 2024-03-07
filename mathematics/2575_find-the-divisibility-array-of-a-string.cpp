class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long long cur = 0;
        for (char& c : word) {
            cur = (cur * 10 + (c - '0')) % m;
            res.push_back(cur == 0 ? 1 : 0);
        }
        return res;
    }
};




class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int len = word.length();
        
        auto toDigit = [](const char& ch) {
            return static_cast<int>(ch - '0');
        };
        
        vector<int> div(len, 0);
        long mod = 0;
        for (int i = 0; i < len; i++) {
            mod = mod * 10 + toDigit(word[i]);
            mod = mod % m;
            if (mod == 0) {
                div[i] = 1;
            }
        }
        
        return div;
    }
};