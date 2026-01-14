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





class MagicDictionary {
public:
    unordered_set<string> chSet;
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (const auto& word : dictionary) {
            chSet.insert(word);
        }
    }
    
    bool search(string searchWord) {
        if (chSet.count(searchWord) != 0) {
            return false;
        }
        int len = searchWord.length();
        
        auto check = [=](const string& word, const string& searchWord) {
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (word[i] != searchWord[i]) {
                    ++cnt;
                }
            }
            
            return cnt;
        };
        

        for (const auto word : chSet) {
            if (len != word.length()) {
                continue;
            }
            if (check(word, searchWord) == 1) {
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