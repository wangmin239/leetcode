/* Original Solution 1 */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> subMask;
        int len = s.length();
        int num = 0;

        for (int left = 0, right = 0; right < len; right++) {
            num += (s[right] - '0') << (right - left);
            if (right - left + 1 == k) {
                subMask.insert(num);
                num >>= 1;
                ++left; 
            }
        }

        return subMask.size() == (1 << k);

    }
};







/* Original Solution 1 */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> subStr;
        int len = s.length();

        for (int i = 0; i <= len - k; i++) {
            subStr.insert(s.substr(i, k));
        }

        return subStr.size() == (1 << k);

    }
};


/* Official Solution 1 */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) {
            return false;
        }

        int num = stoi(s.substr(0, k), nullptr, 2);
        unordered_set<int> exists = {num};
        
        for (int i = 1; i + k <= s.size(); ++i) {
            num = (num - ((s[i - 1] - '0') << (k - 1))) * 2 + (s[i + k - 1] - '0');
            exists.insert(num);
        }
        return exists.size() == (1 << k);
    }
};
