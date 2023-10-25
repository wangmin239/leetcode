class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int mul = i * i;
            if (check(to_string(mul), i, 0) == true) {
                sum += mul;
            }
        }
        return sum;
    }
    

    bool check(const string& str, int target, int offset) {
        int size = str.length();
        int remain = size - offset;
        /* meeting the requirements */
        if (offset == size) {
            return target == 0;
        }
        int val = 0;
        for (int len = 1; len <= remain; len++) {
        /* using stoi(s.substr(offset, len)) to convert integer takes 236 ms,
         * while the below codeline just takes 24 ms. */
            val = val * 10 + str[offset + len - 1] - '0';
            if (val > target) {
                break;
            }
            if (check(str, target - val, offset + len) == true) {
                return true;
            }
        }
        return false;
    }

};



class Solution {
public:
    bool dfs(string &s, int pos, int tot, int target) {
        if (pos == s.size()) {
            return tot == target;
        } 
        int sum = 0;
        for (int i = pos; i < s.size(); i++) {
            sum = sum * 10 + s[i] - '0';
            if (sum + tot > target) {
                break;
            }
            if (dfs(s, i + 1, sum + tot, target)) {
                return true;
            }
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (dfs(s, 0, 0, i)) {
                res += i * i;
            }
        }
        return res;
    }
};
