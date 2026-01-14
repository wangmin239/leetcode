class Trie {
public:
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
    
    bool insert(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr || !node->children[index]->isEnd) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto & word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto & word : words) {
            if (trie.search(word)) {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};



class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<string, int> strMap;
        
        for (const auto& word : words) {
            ++strMap[word];
        }
        
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.length() == rhs.length() ? lhs < rhs : lhs.length() > rhs.length();
        };
        
        sort(words.begin(), words.end(), cmp);
        
        string ans;
        
        for (auto word : words) {
            string str;
            int len = 0;
            for (char ch : word) {
                str.push_back(ch);
                if (strMap.count(str) > 0) {
                    ++len;
                }
            }
            
            if (len == str.length()) {
                ans = str;
                break;
            }
        }
        
        return ans;
        
    }
};