class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> uniqueName;
        size_t len = names.size();
        vector<string> ans(len);
        
        for (auto i = 0; i < len; i++) {
            if (uniqueName.count(names[i]) == 0) {
                uniqueName[names[i]] = 0;
                ans[i] = names[i];
                updateOrder(names[i], uniqueName, 0);
                continue;
            }
            
            string rename;
            do {
                int index = ++uniqueName[names[i]];
                rename = move(names[i] + "(" + to_string(index) + ")");
            } while (uniqueName.count(rename) != 0);
            uniqueName[rename] = 0;
            ans[i] = move(rename);
        }
        return ans;
    }


    void updateOrder(const string& name, unordered_map<string, int>& uniqueName, string::size_type pos) {
        auto findPos = name.find("(", pos);
        if (findPos == string::npos) {
            return ;
        }
        
        string prefix(name.substr(0, findPos));
        if (uniqueName.count(prefix) == 0) {
            return ;
        }
  
        pos = name.find(")", ++findPos);
        int index = stoi(name.substr(findPos, pos - findPos));


        if (index == uniqueName[prefix] + 1 && pos == name.length() - 1) {
            ++uniqueName[prefix];
            return ;
        }
        
        return updateOrder(name, uniqueName, pos + 1);
    }
};


class Solution {
public:
    string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
    }

    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> index;
        vector<string> res(names.size());
        for (string::size_type i = 0; i < names.size(); ++i) {
            if (!index.count(names[i])) {
                res[i] = names[i];
                index[names[i]] = 1;
            } else {
                int k = index[names[i]];
                while (index.count(addSuffix(names[i], k))) {
                    k++;
                }
                res[i] = addSuffix(names[i], k);
                index[names[i]] = k + 1;
                index[addSuffix(names[i], k)] = 1;
            }
        }
        return res;
    }
};
