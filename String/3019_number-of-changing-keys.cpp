class Solution {
public:
    int countKeyChanges(string s) {
        int cnt = 0;
        int diff = static_cast<int>('A' - 'a');
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1] || s[i] == s[i - 1] + diff || s[i] == s[i - 1] - diff) {
                continue;
            }
            ++cnt;
        }
        
        return cnt;
    }
};



class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (tolower(s[i - 1]) != tolower(s[i])) {
                ++ans;
            }
        }
        return ans;
    }
};

