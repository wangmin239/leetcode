class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        bool find0 = false, find5 = false;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0' || num[i] == '5') {
                if (find0) {
                    return n - i - 2;
                }
                if (num[i] == '0') {
                    find0 = true;
                } else {
                    find5 = true;
                }
            } else if (num[i] == '2' || num[i] == '7') {
                if (find5) {
                    return n - i - 2;
                }
            }
        }
        if (find0) {
            return n - 1;
        }
        return n;
    }
};

class Solution {
public:
    int minimumOperations(string num) {
        int cnt = 0;
        unordered_map<char, int> mp;
        // 从后向前遍历
        for(int i = num.length() - 1; i >= 0; --i) {
            char ch = num[i];
            // 找到5则判断右边有没有0
            if(ch == '5' && mp.find('0') != mp.end()) return cnt - 1;
            // 找到0判断右边有没有0
            else if(ch == '0' && mp.find('0') != mp.end()) return cnt - 1;
            // 找到2或7判断右边有没有5
            else if((ch == '7' || ch == '2') && mp.find('5') != mp.end()) return cnt - 1;

            // 否则将字母加入哈希表并让计数器加1
            else {
                ++mp[ch];
                ++cnt;
            }
        }
        // 判断无解情况有0为n-1，无0为n
        return mp.find('0') == mp.end()? num.size(): num.size() - 1;
    }
};
