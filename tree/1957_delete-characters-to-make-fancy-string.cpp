
/* Original Solution 1 */
class Solution {
public:
    string makeFancyString(string s) {
        string ans(1, s[0]);
        int len = s.length();
        int cnt = 1;
        const int limit = 2;

        for (int i = 1;  i < len; i++) {
            if (ans.back() != s[i]) {
                ans.push_back(s[i]);
                cnt = 1;
            } else if (cnt < limit) {
                ans.push_back(s[i]);
                cnt = 2;
            }
        }
        
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    string makeFancyString(string s) {
        string res;   // 删除后的字符串
        // 遍历 s 模拟删除过程
        for (char ch : s){
            int n = res.size();
            if (n >= 2 && res[n-1] == ch && res[n-2] == ch){
                // 如果 res 最后两个字符与当前字符均相等，则不添加
                continue;
            }
            // 反之则添加
            res.push_back(ch);
        }
        return res;
    }
};

/* Official Solution 2 */
class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt++;
            if (cnt < 3) {
                ans += s[i];
            }
            if (i < s.size() - 1 && s[i] != s[i + 1]) {
                cnt = 0; // 当前字母和下个字母不同，重置计数器
            }
        }
        return ans;
    }
};
