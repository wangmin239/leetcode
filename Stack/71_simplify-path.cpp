class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string& name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }
        string ans;
        if (stack.empty()) {
            ans = "/";
        }
        else {
            for (string& name: stack) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};



class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec {"/"};   
        int len = path.length();
        
        
        for (int i = 1; i < len; i++) {
            string dirent;
            while (i < len && path[i] != '/') {
                dirent.push_back(path[i]);
                i++;
            }
            /* continuous slash char */
            if (dirent.empty() == true) {
                continue;
            }
            
            if (dirent == "..") {
                if (vec.size() > 1) {
                    vec.pop_back();
                }
            } else if (dirent != ".") {
                vec.push_back(dirent);
            }
            
        }
        
        string ans("/");
        getDirent(ans, vec);
        return ans;
     
    }
    
    inline void getDirent(string& ans, vector<string>& vec) {
        int size = vec.size() - 1;
        if (size == 0) {
            return ;
        }
        
        for (int i = 1; i < size; i++){
            ans += vec[i] + "/";
        }
        ans.append(vec[size]);
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec {"/"};
        
        int len = path.length();
        
        
        for (int i = 1; i < len; i++) {
            string dirent;
            while (i < len && path[i] != '/') {
                dirent.push_back(path[i]);
                i++;
            }
            if (dirent.empty() == true) {
                continue;
            }
            if (dirent == "..") {
                if (vec.size() > 1) {
                    vec.pop_back();
                }
            } else if (dirent != ".") {
                vec.push_back(dirent);
            }
            
        }
        
        int size = vec.size() - 1;
        if (size == 0) {
            return "/";
        }
        
        string ans("/");
        for (int i = 1; i < size; i++){
            ans += vec[i] + "/";
        }
        ans.append(vec[size]);
        return ans;
    }
};