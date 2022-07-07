struct Trie {
    unordered_map<char, Trie *> children;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for (auto &word : dictionary) {
            Trie *cur = trie;
            for (char &c: word) {
                if (!cur->children.count(c)) {
                    cur->children[c] = new Trie();
                }
                cur = cur->children[c];
            }
            cur->children['#'] = new Trie();
        }
        vector<string> words = split(sentence, ' ');
        for (auto &word : words) {
            word = findRoot(word, trie);
        }
        string ans;
        for (int i = 0; i < words.size() - 1; i++) {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }

    vector<string> split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        vector<string> ret;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != ch) {
                pos++;
            }
            if (start < str.size()) {
                ret.emplace_back(str.substr(start, pos - start));
            }
        }
        return ret;
    }

    string findRoot(string &word, Trie *trie) {
        string root;
        Trie *cur = trie;
        for (char &c : word) {
            if (cur->children.count('#')) {
                return root;
            }
            if (!cur->children.count(c)) {
                return word;
            }
            root.push_back(c);
            cur = cur->children[c];
        }
        return root;
    }
};

class Solution {
public:
    vector<string_view> split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        string_view s(str);
        vector<string_view> ret;
        while (pos < s.size()) {
            while (pos < s.size() && s[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < s.size() && s[pos] != ch) {
                pos++;
            }
            if (start < s.size()) {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string_view> dictionarySet;
        for (auto &root : dictionary) {
            dictionarySet.emplace(root);
        }
        vector<string_view> words = split(sentence, ' ');
        for (auto &word : words) {
            for (int j = 0; j < word.size(); j++) {
                if (dictionarySet.count(word.substr(0, 1 + j))) {
                    word = word.substr(0, 1 + j);
                    break;
                }
            }
        }
        string ans;
        for (int i = 0; i < words.size() - 1; i++) {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }
};



class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.length() < rhs.length();
        };
          
        sort(dictionary.begin(), dictionary.end(), cmp);
        
        string ans;
        int len = sentence.length();
        int start = 0;
        
        for (int i = start; i < len; i++) {
            if (sentence[i] == ' ' || i == len - 1) {
                int length = (i == len - 1 ? len - start : i - start);
                string word(sentence.substr(start, length));

                
                start = i + 1;
                successorReplace(word, dictionary);
                ans.append(word);
                
                if (i < len - 1) {
                    ans.append(" ");
                }
            }
        }
        
        
        
        return ans;
    }
    
    void successorReplace(string& pattern, vector<string>& dictionary) {

        for (const auto& word : dictionary) {
            bool isSuccessor = true;
            
            for (int i = 0; i < word.length(); i++) {
                if (word[i] != pattern[i]) {
                    isSuccessor = false;
                    break;
                }
            }

            if (isSuccessor == true) {
                pattern = word;
                return ;
            }  
        }
        return ;
    }
};

