
/* Original Solution 1 */
class Trie {
public:
    bool isEnd;
    unordered_map<string, Trie*> path;
    Trie() :isEnd(false) {
    
    }
        
};



class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie root;
        
        for (const auto& dir : folder) {
            int len = dir.length();
            Trie* node = &root;
            int start = 1;
            
            /* split the dirent with the character '/' */
            for (int end = start; end < len; end++) {
                if (end == len - 1 || dir[end] == '/') {
                    int dirLen = (end == len - 1) ? end - start + 1 : end - start;                     
                    string subDir(dir.substr(start, dirLen));
                    
                    if (node->path.count(subDir) == 0) {
                        node->path[subDir] = new Trie;
                    }
                    node = node->path[subDir];
                    start = end + 1;
                }
            }
            node->isEnd = true;
        }
        
        vector<string> ans;
        
        auto dfs =[&ans](Trie* node, string&& parent, auto&& innerDfs) ->void {           
            auto dirs = node->path;
            
            for (auto& [subDir, subNode]: dirs) {
                if (subNode->isEnd == true) {
                    ans.push_back(parent + "/" + subDir);
                } else {
                    innerDfs(subNode, parent + "/" + subDir, innerDfs);
                }
 
            }
            return;
        };
        

        dfs(&root,  "", dfs);
        return ans;  
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            if (int pre = ans.end()[-1].size(); !(pre < folder[i].size() && ans.end()[-1] == folder[i].substr(0, pre) && folder[i][pre] == '/')) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            int pre = ans.back().size();
            if (ans.back() == folder[i].substr(0, pre) && folder[i][pre] == '/') {
                continue;
            }
            ans.push_back(folder[i]);
        }
        return ans;
    }
};








/* Original Solution 2 */
/* using smart pointer to automatic destruction */
class Trie {
public:
    bool isEnd;
    unordered_map<string, shared_ptr<Trie>> path;
    Trie() : isEnd(false) {
        
    }

};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        shared_ptr<Trie> root(new Trie);

        for (const auto& dir : folder) {
            int len = dir.length();
            auto node = root;

            for (int start = 1, end = 1; end < len; end++) {
                if (end == len - 1 || dir[end] == '/') {
                    int dirLen = (end == len - 1) ? end - start + 1 : end - start;
                    string subDir(dir.substr(start, dirLen));

                    if (node->path.count(subDir) == 0) {
                            node->path[subDir] = make_shared<Trie>(Trie());
                    }
                    node = node->path[subDir];
                    start = end + 1;
                }
            }
            node->isEnd = true;
        }

        vector<string> ans;

        function<void(shared_ptr<Trie>&, string&&)> dfs =[&](shared_ptr<Trie>& node, string&& parent) {
            auto dirs = node->path;

            for (auto& [subDir, subNode]: dirs) {
                if (subNode->isEnd == true) {
                    ans.push_back(parent + "/" + subDir);
                    continue;
                }
                dfs(subNode, parent + "/" + subDir);
            }

        };


        dfs(root,  "");
        return ans;
    }
};

