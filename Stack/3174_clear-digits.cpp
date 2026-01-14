class Solution {
public:
    string clearDigits(string s) {
        string res;
        for (char c : s) {
            if (isdigit(c)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};





class Solution {
public:
    string clearDigits(string s) {
        string ans;
        
        for (char ch : s) {
            if (isdigit(ch) == false) {
                ans.push_back(ch);
                continue;
            }
            
            ans.pop_back();
        }
        
        return ans;
    }
};





class Solution {
public:
    string clearDigits(string s) {
        string ans;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                if (ans.empty() == false && isdigit(ans.back()) == false) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};