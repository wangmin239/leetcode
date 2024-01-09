class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> d(n + 1, INT_MAX);
        unordered_map<string, int> mp;
        for (auto s : dictionary) {
            mp[s]++;
        }
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + 1;
            for (int j = i - 1; j >= 0; j--) {
                if (mp.count(s.substr(j, i - j))) {
                    d[i] = min(d[i], d[j]);
                }
            }
        }
        return d[n];
    }
};

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool track(Trie*& node, char ch) {
        if (node == nullptr || node->children[ch - 'a'] == nullptr) {
            node = nullptr;
            return false;
        }
        node = node->children[ch - 'a'];
        return node->isEnd;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> d(n + 1, INT_MAX);
        Trie trie;
        for (auto s : dictionary) {
            reverse(s.begin(), s.end());
            trie.insert(s);
        }
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + 1;
            Trie* node = &trie;
            for (int j = i - 1; j >= 0; j--) {
                if (trie.track(node, s[j])) {
                    d[i] = min(d[i], d[j]);
                }
            }
        }
        return d[n];
    }
};



