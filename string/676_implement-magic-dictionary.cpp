class MagicDictionary {
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string searchWord) {
        for (auto&& word: words) {
            if (word.size() != searchWord.size()) {
                continue;
            }

            int diff = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != searchWord[i]) {
                    ++diff;
                    if (diff > 1) {
                        break;
                    }
                }
            }
            if (diff == 1) {
                return true;
            }
        }
        return false;
    }

private:
    vector<string> words;
};



struct Trie {
    bool is_finished;
    Trie* child[26];

    Trie() {
        is_finished = false;
        fill(begin(child), end(child), nullptr);
    }
};

class MagicDictionary {
public:
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto&& word: dictionary) {
            Trie* cur = root;
            for (char ch: word) {
                int idx = ch - 'a';
                if (!cur->child[idx]) {
                    cur->child[idx] = new Trie();
                }
                cur = cur->child[idx];
            }
            cur->is_finished = true;
        }
    }
    
    bool search(string searchWord) {
        function<bool(Trie*, int, bool)> dfs = [&](Trie* node, int pos, bool modified) {
            if (pos == searchWord.size()) {
                return modified && node->is_finished;
            }
            int idx = searchWord[pos] - 'a';
            if (node->child[idx]) {
                if (dfs(node->child[idx], pos + 1, modified)) {
                    return true;
                }
            }
            if (!modified) {
                for (int i = 0; i < 26; ++i) {
                    if (i != idx && node->child[i]) {
                        if (dfs(node->child[i], pos + 1, true)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };

        return dfs(root, 0, false);
    }

private:
    Trie* root;
};




class MagicDictionary {
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (const auto& str : dictionary) {
            int len = str.length();
            dict[len].push_back(str);
        }
    }
    
    bool search(string searchWord) {
        int len = searchWord.length();
        
        if (dict.count(len) == 0) {
            return false;
        }
        
        return comp(searchWord, dict[len]);
    }
    
private:
    unordered_map<int, vector<string>> dict;
    inline comp(const string& pattern, vector<string>& dictionary) {
        auto cmpStr = [](const auto& pattern, const auto& str) {
            int len = pattern.length();
            int diffCnt = 0;
            
            for (int i = 0; i < len; i++) {
                if (pattern[i] != str[i]) {
                    ++diffCnt;
                }
            }
            
            return diffCnt == 1;
        };
        
        for (const auto& str : dictionary) {
            if (cmpStr(pattern, str) == true) {
                return true;
            }
            
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */