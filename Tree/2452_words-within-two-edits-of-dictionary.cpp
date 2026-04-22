/* Original Solution 1 */
class Trie {
public:
    shared_ptr<Trie> chArr[26];
    bool isEnd;

    Trie() {
        for (int i = 0; i < 26; i++) {
            chArr[i] = nullptr;
        }

        isEnd = false;
    }
};

class Solution {
public:
    void addStr(const string& word, shared_ptr<Trie> root) {
        for (char ch : word) {
            int index = ch - 'a';
            if (root->chArr[index] == nullptr) {
                shared_ptr<Trie> node(new Trie);
                root->chArr[index] = node;
            }
            root = root->chArr[index];
        }
        root->isEnd = true;
    }

    int getDiffCnt(const string& word, shared_ptr<Trie> root, int index, int cnt) {
        if (cnt > 2 || root->isEnd == true) {
            return cnt;
        }

        int id = word[index] - 'a';
        int minCnt = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (root->chArr[i] != nullptr) {
                if (i != id) {
                    minCnt = min(minCnt, getDiffCnt(word, root->chArr[i], index + 1, cnt + 1));
                } else {
                    minCnt = min(minCnt, getDiffCnt(word, root->chArr[i], index + 1, cnt));
                }
            }
        }

        return minCnt;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        shared_ptr<Trie> root(new Trie);
        vector<string> ans;
        for (const auto& word : dictionary) {
            addStr(word, root);
        }

        for (const auto& word : queries) {
            if (getDiffCnt(word, root, 0, 0) <= 2) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};



/* Official Solution 1 */
struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int i, TrieNode* node, int cnt) {
        if (cnt > 2)
            return false;
        if (!node)
            return false;

        if (i == word.size()) {
            return node->isEnd;
        }

        int idx = word[i] - 'a';

        // 不修改
        if (node->child[idx]) {
            if (dfs(word, i + 1, node->child[idx], cnt))
                return true;
        }

        // 修改
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx)
                    continue;
                if (node->child[c]) {
                    if (dfs(word, i + 1, node->child[c], cnt + 1))
                        return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        for (auto& w : dictionary)
            insert(w);

        vector<string> res;
        for (auto& q : queries) {
            if (dfs(q, 0, root, 0)) {
                res.push_back(q);
            }
        }
        return res;
    }
};



/* Official Solution 2 */
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& q : queries) {
            for (auto& s : dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.size() && cnt <= 2; i++) {
                    if (q[i] != s[i]) {
                        cnt++;
                    }
                }
                if (cnt <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};
