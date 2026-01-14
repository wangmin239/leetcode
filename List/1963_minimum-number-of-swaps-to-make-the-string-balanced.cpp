class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, mincnt = 0;
        for (char ch: s) {
            if (ch == '[') {
                cnt += 1;
            }
            else {
                cnt -= 1;
                mincnt = min(mincnt, cnt);
            }
        }
        return (-mincnt + 1) / 2;
    }
};


class Solution {
public:
    int minSwaps(string s) {
        int n = 0;
        stack<char> bracket;
        for(char c : s){
            if(c == '[') bracket.push('[');
            else if(bracket.empty()) ++n;
            else bracket.pop();
        }
        return n / 2 + n % 2;
    }
};