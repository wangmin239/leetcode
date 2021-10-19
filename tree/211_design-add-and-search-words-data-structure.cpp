


struct TrieNode{
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode *>(26,nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode * root, const string & word) {
    TrieNode * node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        insert(trie,word);
    }
    
    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string & word,int index,TrieNode * node) {
　　　　if (index == word.size()) {
            return node->isEnd;    
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode * child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    TrieNode * trie;
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        chMap.emplace(word, word.length());
    }
    
    bool search(string word) {
        if (chMap.count(word) > 0) {
            return true;
        }
        int i;
        for (auto& [str, len] : chMap) {
            if (len != word.length()) {
                continue;
            }
            
            i = 0;
            for (char ch : str) {
               if (ch == word[i] || word[i] == '.') {
                   i++;
               } else {
                   break;
               }
            }
            
            if (i == len) {
                return true;
            }
        }
        
        return i == word.length();
    }
private:
    map<string, int> chMap;
   
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 
 class WordDictionary {
public:
    WordDictionary(): next {nullptr}, isEnd(false) {

    }
    
    void addWord(string word) {
        WordDictionary *p = this;
        for (char ch : word) {
            if (p->next[ch - 'a'] == nullptr) {
                p->next[ch - 'a'] = new WordDictionary();
            }
            p = p->next[ch - 'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, this);
    }
    
    bool dfs(string word, int index, WordDictionary* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        
        char ch = word[index];
        
        if (ch >= 'a' && ch <= 'z') {
            WordDictionary* child = node->next[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                WordDictionary* child = node->next[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }


private:
    WordDictionary* next[26];
    bool isEnd;
};
 