class Solution {
public:
    vector<int> diStringMatch(string s) {
        int len = s.length();
        vector<int> ans(len + 1, 0);
        int decrease = len;
        int increase = 0;
        
        for (int i = 0; i < len; i++) {
            if (s[i] == 'I') {
                ans[i] = increase++;
            } else {
                ans[i] = decrease--;
            }
        }
        ans[len] = decrease;
        return ans;
    }
};



class Solution {
public:
    vector<int> diStringMatch(string s) {
        int len = s.length();
        vector<int> ans(len + 1, 0);
        int decrease = len;
        int increase = 0;
        
        for (int i = 0; i < len; i++) {
            switch(s[i]) {
                case 'I':
                    ans[i] = increase++;
                    break;
                case 'D':
                    ans[i] = decrease--;
                    break;
            }
        }
        ans[len] = decrease;
        return ans;
    }
};