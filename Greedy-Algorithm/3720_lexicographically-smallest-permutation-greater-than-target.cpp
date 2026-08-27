/* Official Solution 1 */
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }

        // 从右往左尝试
        for (int i = s.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            cnt[b]++; // 撤销消耗
             // 检查前缀能否完全匹配
            if (*min_element(cnt.begin(), cnt.end()) < 0) {
                continue;
            }
            // 找一个比 b 大的最小可用字符
            for (int j = b + 1; j < 26; j++) {
                if (cnt[j]) {
                    cnt[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getMinString(cnt);
                }
            }
        }

        return "";
    }

    // 获取最小字典序字符串（升序排列）
    string getMinString(const vector<int>& cnt) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }
};



/* Official Solution 2 */
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        string res;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            int targetChar = target[i] - 'a';

            // 情况1：先尝试在当前位置放置与 target[i] 相同的字符
            if (cnt[targetChar] > 0) {
                cnt[targetChar]--;
                // 检查剩余字符能否构成大于 target[i+1:] 的字符串
                if (canFormGreater(cnt, target, i + 1)) {
                    res.push_back(target[i]);
                    continue;
                }
                // 不能构成更大的字符串，回溯
                cnt[targetChar]++;
            }
            
            // 情况2：在当前位置放置一个大于 target[i] 的字符
            for (int j = targetChar + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    res.push_back('a' + j);
                    // 剩余位置按最小字典序填充
                    res += getMinString(cnt);
                    return res;
                }
            }
            
            // 无法找到可行方案, 直接返回
            return "";
        }
        
        return "";
    }
    
private:
    // 检查剩余字符是否能构成大于 suffix 的字符串
    bool canFormGreater(const vector<int>& cnt, const string& target, int start) {
        string maxStr = getMaxString(cnt);
        string suffix = target.substr(start);
        return maxStr > suffix;
    }
    
    // 获取最大字典序字符串（降序排列）
    string getMaxString(const vector<int>& cnt) {
        string res;
        for (int i = 25; i >= 0; i--) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }
    
    // 获取最小字典序字符串（升序排列）
    string getMinString(const vector<int>& cnt) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }
};


/* Original Solution 1, 579/761 testcases passed  */
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int len = s.length();
        const int chNum = 26;
        int chArr[chNum] = {0};
        string ans(len, 'a');
        int index = 0;
        bool isGreat = false;

        for (char ch : s) {
            ++chArr[ch - 'a'];
        }

        for (char ch : target) {
            int id = ch - 'a';
            int i;

            id = isGreat ? 0 : id;
            for (i = id; i < chNum; i++) {
                if (chArr[i] > 0) {
                    --chArr[i];
                    ans[index++] = 'a' + i;
                    break;
                }
            }

            if (i > id) {
                isGreat = true;
            }

            if (i == chNum) {
                return "";
            }
        }

        auto getMinStr = [len](string& str) {
            for (int i = len - 1; i > 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    if (str[j] < str[i]) {
                        swap(str[j], str[i]);
                        return true;
                    }
                }
            }
            return false;
        };

        if (ans == target) {
            if (getMinStr(ans)) {
                return ans;
            }
            return "";
        }

        return ans;
    }
};