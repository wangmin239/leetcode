class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> st;
        string::size_type begin, end;
        char delim = ',';
        begin = 0;
        end = preorder.find(delim, begin);
        while (end != string::npos) {
            auto str = preorder.substr(begin, end - begin);
            if (str != "#") {
                st.push(str);
            } else {
                if (st.empty() == true) {
                    return false;
                }
                st.pop();
            }
            begin = end + 1;
            end = preorder.find(delim, begin);
        }

        if (preorder.substr(begin, preorder.length() - begin) != "#") {
            return false;
        }
        return st.empty();
    }
};



class Solution {
public:
    int k = 0;
    string s;
    bool isValidSerialization(string preorder) {
        s = preorder;
        s += ",";
        if (!dfs()) return false;
        return k == s.size();
    }

    bool dfs() {
        if (k == s.size()) return false;
        if (s[k] == '#') {
            k+= 2;
            return true;
        }
        while(s[k] != ',') k++;
        k++;
        return dfs() && dfs();
    }
};


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int i = 0;
        int slots = 1;
        while (i < n) {
            if (slots == 0) {
                return false;
            }
            if (preorder[i] == ',') {
                i++;
            } else if (preorder[i] == '#'){
                slots--;
                i++;
            } else {
                // 读一个数字
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                slots++; // slots = slots - 1 + 2
            }
        }
        return slots == 0;
    }
};
