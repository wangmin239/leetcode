class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string str;

        function<void(string &)> dfs = [&](string& str) {
            if (str.size() == n) {
                res.push_back(str);
                return;
            }
            if (str.empty() || str.back() == '1') {
                str.push_back('0');
                dfs(str);
                str.pop_back();
            }
            str.push_back('1');
            dfs(str);
            str.pop_back();
        };
        
        dfs(str);
        return res;
    }
};


class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int t = mask ^ i;
            if (!(t >> 1 & t)) {
                res.push_back(intToBinaryString(i, n));
            }
        }
        return res;
    }

    string intToBinaryString(int num, int n) {
        string binary(n, '0');
        for (int j = 0; j < n; j++) {
            binary[n - 1 - j] = (num & (1 << j)) ? '1' : '0';
        }
        return binary;
    }
};
