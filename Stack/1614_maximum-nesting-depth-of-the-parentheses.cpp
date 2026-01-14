class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, size = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++size;
                ans = max(ans, size);
            } else if (ch == ')') {
                --size;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxDepth(string s) {
        int leftParentheses = 0;
        int maxDep = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                ++leftParentheses;
            }
            
            if (ch == ')') {
                maxDep = max(leftParentheses, maxDep);
                --leftParentheses;
            }
        }
        
        return maxDep;
            
    }
};

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDep = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            }
            
            if (ch == ')') {
                maxDep = max(static_cast<int>(st.size()), maxDep);
                st.pop();
            }
        }
        
        return maxDep;
            
    }
};