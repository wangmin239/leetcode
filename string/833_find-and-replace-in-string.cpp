class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), m = indices.size();

        unordered_map<int, vector<int>> ops;
        for (int i = 0; i < m; ++i) {
            ops[indices[i]].push_back(i);
        }

        string ans;
        for (int i = 0; i < n;) {
            bool succeed = false;
            if (ops.count(i)) {
                for (int pt: ops[i]) {
                    if (s.substr(i, sources[pt].size()) == sources[pt]) {
                        succeed = true;
                        ans += targets[pt];
                        i += sources[pt].size();
                        break;
                    }
                }
            }
            if (!succeed) {
                ans += s[i];
                ++i;
            }
        }
        return ans;
    }
};



class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), m = indices.size();

        vector<int> ops(m);
        iota(ops.begin(), ops.end(), 0);
        sort(ops.begin(), ops.end(), [&](int i, int j) { return indices[i] < indices[j]; });

        string ans;
        int pt = 0;
        for (int i = 0; i < n;) {
            while (pt < m && indices[ops[pt]] < i) {
                ++pt;
            }
            bool succeed = false;
            while (pt < m && indices[ops[pt]] == i) {
                if (s.substr(i, sources[ops[pt]].size()) == sources[ops[pt]]) {
                    succeed = true;
                    break;
                }
                ++pt;
            }
            if (succeed) {
                ans += targets[ops[pt]];
                i += sources[ops[pt]].size();
            }
            else {
                ans += s[i];
                ++i;
            }
        }
        return ans;
    }
};



class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        int len = s.length();
        int start;
        int n = sources.size();
        int i;
        
        /* sort the indices by associating with ids */
        vector<int> ids(n, 0);
        iota(ids.begin(), ids.end(), 0);
        auto cmp = [&indices](int lhs, int rhs) {
                        return indices[lhs] < indices[rhs];
                    };
        sort(ids.begin(), ids.end(), cmp);
        
        /* check if the given string is matched */
        for (i = 0, start = 0; i < n ; i++) {
            int id = ids[i];
            if (start < indices[id]) {
                ans.append(s.substr(start, indices[id] - start));
                start = indices[id];
            }
            
            int srcLen = sources[id].length();
            if (sources[id] == s.substr(indices[id], srcLen)) {
                ans.append(targets[id]);
                start = indices[id] + srcLen;
            }
        }
        /* add the remaining characters */
        if (start < len) {
            ans.append(s.substr(start));
        }
        
        return ans;
    }
};

