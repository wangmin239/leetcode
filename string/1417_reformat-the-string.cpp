class Solution {
public:
    string reformat(string s) {
        string digitStr;
        string charStr;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                digitStr.push_back(ch);
                continue;
            }      
            charStr.push_back(ch); 
        }
        
        string ans;
        int digitLen = digitStr.length();
        int charLen = charStr.length();

        if (abs(digitLen - charLen) > 1) {
            return ans;
        }
        
        int digitIndex = 0, charIndex = 0;
        int minLen = min(digitLen, charLen);
        if (digitLen > minLen) {
            ans.push_back(digitStr[digitIndex++]);
        } 
        
        if (charLen > minLen) {
            ans.push_back(charStr[charIndex++]);
        }
        
        auto interactiveStr = [&](auto& lhs, auto& rhs, int lhsIndex, int rhsIndex) {

            while (lhsIndex < minLen) {
                ans.push_back(lhs[lhsIndex]);
                ans.push_back(rhs[rhsIndex]);
            }
        };
        
        if (digitLen > minLen) {
            interactiveStr(charStr, digitStr, charIndex, digitIndex);
        } else {
            interactiveStr(digitStr, charStr, digitIndex, charIndex);
        }
        
        return ans;
    }
};





class Solution {
public:
    string reformat(string s) {
        int sum_digit = 0;
        for (auto& c : s) {
            if (isdigit(c)) {
                sum_digit++;
            }
        }
        int sum_alpha = s.size() - sum_digit;
        if (abs(sum_digit - sum_alpha) > 1) {
            return "";
        }
        bool flag = sum_digit > sum_alpha;
        for (int i = 0, j = 1; i < s.size(); i += 2) {
            if (isdigit(s[i]) != flag) {
                while (isdigit(s[j]) != flag) {
                    j += 2;
                }
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
