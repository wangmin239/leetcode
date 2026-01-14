class Solution {
public:
    char kthCharacter(int k) {
        const int mod = 26;
        string str("a");
        int len = str.length();
        
        while (len < 2 * k) {
            string tmp(str);
            for (size_t i = 0; i < str.length(); i++) {
                tmp[i] = 'a' + (str[i] - 'a' + 1) % mod;
            }
            str.append(tmp);
            len = str.length();
        }
        
        return str[k];
    }
};