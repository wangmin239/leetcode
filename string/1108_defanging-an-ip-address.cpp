regex r("\\.");
class Solution {
public:
    string defangIPaddr(string address) {
        return regex_replace(address, r, "[.]");
    }
};


class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        
        for (const char ch : address) {
            if (ch != '.') {
                ans.push_back(ch);
            } else {
                ans.append("[.]");
            }
        }
        
        return ans;
    }
};



class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.length();
        string ans(len + 6, '0');
        int i = 0;
        
        for (const char ch : address) {
            if (ch != '.') {
                ans[i++] = ch;
            } else {
                ans[i++] = '[';
                ans[i++] = '.';
                ans[i++] = ']';
            }
        }
        
        return ans;
    }
};