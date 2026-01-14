struct Node
{
    int weight;
    bool isWord;
    // unordered_map<char, Node*> children;
    Node* children[27];

    Node()
    {
        memset(children, 0, sizeof(children));
        weight = -1;
        isWord = false;
    }
};

class WordFilter {
private:
    Node* root = new Node();

public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        //这里weight就等于下标，越大表示权重越大
        for (int weight = 0; weight < n; ++weight)
        {
            // 构建一个特殊前后相同字符串，后续查找使用
            string fullWord = words[weight] + "#" + words[weight];
            int nWord = words[weight].size();

            for (int i = 0; i < nWord + 1; ++i)
            {
                Node* curr = root;
                for (int j = i; j < fullWord.size(); ++j)
                {
                    // if (curr->children.find(fullWord[j]-'a') == curr->children.end())
                    int index = fullWord[j] == '#' ? 26 : fullWord[j]-'a';
                    if (curr->children[index] == nullptr)
                    {
                        curr->children[index] = new Node();
                    }
                    curr = curr->children[index];
                    curr->isWord = true;
                    curr->weight = weight;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string fullWord = suffix + "#" + prefix;
        Node* curr = root;
        for (char c : fullWord)
        {
            int index = c == '#' ? 26 : c-'a';
            // if (curr->children.find(c-'a') == curr->children.end())
            if (curr->children[index] == nullptr)
            {
                return -1;
            }
            curr = curr->children[index];
        }
        return curr->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */



struct Trie {
    unordered_map<string, Trie *> children;
    int weight;
};

class WordFilter {
private:
    Trie *trie;

public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            Trie *cur = trie;
            int m = word.size();
            for (int j = 0; j < m; j++) {
                Trie *tmp = cur;
                for (int k = j; k < m; k++) {
                    string key({word[k], '#'});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                tmp = cur;
                for (int k = j; k < m; k++) {
                    string key({'#', word[m - k - 1]});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                string key({word[j], word[m - j - 1]});
                if (!cur->children.count(key)) {
                    cur->children[key] = new Trie();
                }
                cur = cur->children[key];
                cur->weight = i;
            }
        }
    }
    
    int f(string pref, string suff) {
        Trie *cur = trie;
        int m = max(pref.size(), suff.size());
        for (int i = 0; i < m; i++) {
            char c1 = i < pref.size() ? pref[i] : '#';
            char c2 = i < suff.size() ? suff[suff.size() - 1 - i] : '#';
            string key({c1, c2});
            if (!cur->children.count(key)) {
                return -1;
            }
            cur = cur->children[key];
        }
        return cur->weight;
    }
};





class WordFilter {
private:
    unordered_map<string, int> dict;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            int m = words[i].size();
            string word = words[i];
            for (int prefixLength = 1; prefixLength <= m; prefixLength++) {
                for (int suffixLength = 1; suffixLength <= m; suffixLength++) {
                    string key = word.substr(0, prefixLength) + '#' + word.substr(m - suffixLength);
                    dict[key] = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string target = pref + '#' + suff;
        return dict.count(target) ? dict[target] : -1;
    }
};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */