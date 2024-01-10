
class Solution {
public:
    int minLength(string s) {
        vector<int> st;
        for (char c : s) {
            st.push_back(c);
            int m = st.size();
            if (m >= 2 &&
                (st[m - 2] == 'A' && st[m - 1] == 'B' ||
                st[m - 2] == 'C' && st[m - 1] == 'D')) {
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};





class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for (char ch : s) {
           if (st.empty() == false) {
               char preCh = st.top();
               if ((ch == 'B' && preCh == 'A') || (ch == 'D' && preCh == 'C') {
                   st.pop();
               } else {
                   st.push(ch);
               }
           } else {
               st.push(ch);
           }
        }
        return st.size();
    }
};