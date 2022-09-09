class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        
        for (string str : logs) {
            if (str == "../") {
                if (steps != 0) {
                    steps--;
                }
                continue;
            }
            
            if (str != "./") {
                steps++;
            }
        }    
        return steps;
            
    }
};


class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto & log : logs) {
            if (log == "./") {
                continue;
            } else if (log == "../") {
                if (depth > 0) {
                    depth--;
                }
            } else {
                depth++;
            }
        }
        return depth;
    }
};




class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        
        for (string str : logs) {
            if (str == "../") {
                if (st.empty() == true) {
                    continue;
                }
                st.pop();
                continue;
            }
            
            if (str != "./") {
                st.push(str);
            }
        }
        
        
        return st.size();
            
    }
};