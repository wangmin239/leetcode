class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size = pushed.size();
        stack<int> st;
        int pushIndex = 0;
        int popIndex = 0;
        
        while (pushIndex < size) {
           st.push(pushed[pushIndex]);
           
           while (st.empty() == false && st.top() == popped[popIndex]) {
               st.pop();
               popIndex++;
           }
           pushIndex++; 
        }
        
        return st.empty() == true;
    }
};