/* Official Solution 1 */
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;   // 分组后的字符串
        int n = s.size();
        int curr = 0;   // 每个分组的起始下标
        // 拆分字符串
        while (curr < n) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        // 尝试填充最后一组
        res.back() += string(k - res.back().length(), fill);
        return res;
    }
};




/* Original Solution 1 */
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int len = s.length();
        int groups = len / k;
        int remain = len % k;
        vector<string> ans(groups + static_cast<int>(remain > 0), string(k, fill));

        for (int group = 0; group < groups; group++) {
            ans[group] = s.substr(group * k, k);
        }

        for (int i = 0; i < remain; i++) {
            ans.back()[i] = s[groups * k + i];
        }
        
        return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int len = s.length();
        int groups = (len + k - 1) / k;
        vector<string> ans(groups, string(k, fill));

        for (int group = 0; group < groups; group++) {
            ans[group] = s.substr(group * k, k);
        }

        if (len % k) {
            ans.back().append(k - len % k, fill);
        }
        
        return ans;
    }
};