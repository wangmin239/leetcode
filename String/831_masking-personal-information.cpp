class Solution {
public:
    vector<string> country = {"", "+*-", "+**-", "+***-"};

    string maskPII(string s) {
        string res;
        int at = s.find("@");
        if (at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }
};


class Solution {
public:
    string maskPII(string s) {
        auto pos = s.find('@');
        
        if (pos != string::npos) {
            return email(s, pos);
        }
        
        return phoneNum(s);
    }
    
    string phoneNum(const string& s) {
       string digits;
       for (auto ch : s) {
           if (isdigit(ch)) {
               digits.push(ch);
           }
       }
       
       int len = digits.length();
       string num("***-***-" + digits.substr(len - 5));
       string ans;
       switch (len) {
           case 10:
                ans = move(num);
                break;
           case 11:
                ans = move("+*" + num);
                break;
           case 12:
                ans = move("+**" + num);
                break;
           case 13:
                ans = move("+***" + num);
                break;
       }
       return ans;
    }
    
    string email(const string& s, string::size_type pos) {
        string prefix;
        prefix.push_back(tolower(s[0]));
        prefix.append("*****");
        prefix.push_back(tolower(s[pos - 1]));
        
        for (auto index = pos; index < s.length(); index++) {
            char ch = s[index];
            if (isupper(ch)) {
                ch = tolower(ch);
            }
            prefix.push_back(ch);
        }
        return prefix;
    }
    
};