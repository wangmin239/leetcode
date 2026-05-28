/* Original Solution 1 */
auto greaterCmp = [](const auto& lhs, const auto& rhs) {
    return lhs.second == rhs.second ? lhs.first > rhs.first : lhs.second > rhs.second;
};

class Trie {
public:
    shared_ptr<Trie> next[26];
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greaterCmp)> ids {greaterCmp};
};

void build(const int id, const string& str, shared_ptr<Trie> root) {
    int len = str.length();

    for (char ch : str) {
        int index = ch - 'a';

        if (root->next[index] == nullptr) {
            root->next[index] = make_shared<Trie>();
        }
        root->ids.push({id, len});
        root = root->next[index];
    }
    root->ids.push({id, len});

}

int findWord(const string& str, shared_ptr<Trie> root) {
    for (char ch : str) {
        int index = ch - 'a';

        if (root->next[index] == nullptr) {
            break;
        }

        root = root->next[index];
    }

    return root->ids.top().first;
}

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        shared_ptr<Trie> root(new Trie);
        int size = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> ans(n);

        for (int i = 0; i < size; i++) {
            auto& str = wordsContainer[i];
            reverse(str.begin(), str.end());
            build(i, str, root);
        }

        for (int i = 0; i < n; i++) {
            auto& word = wordsQuery[i];

            reverse(word.begin(), word.end());
            ans[i] = findWord(word, root);
        }

        return ans;
    }
};



/* Official Solution 1 */
class Trie {
public:
    Trie(): tot_(0) {
        for (int i = 0; i < N; i++) {
            memset(tr_[i], 0, sizeof(tr_[i]));
            min_len_[i] = INT_MAX;
            idx_[i] = INT_MAX;
        }
    }
    void clear() {
        for (int i = 0; i <= tot_; i++) {
            memset(tr_[i], 0, sizeof(tr_[i]));
            min_len_[i] = INT_MAX;
            idx_[i] = INT_MAX;
        }
        tot_ = 0;
    }
    void insert(const string &s, int idx) {
        int p = 0;
        if (min_len_[p] > s.length()) {
            min_len_[p] = s.length();
            idx_[p] = idx;
        }
        for (auto &ch : s) {
            int c = ch - 'a';
            if (tr_[p][c] == 0) {
                tr_[p][c] = ++tot_;
            }
            p = tr_[p][c];
            if (min_len_[p] > s.length()) {
                min_len_[p] = s.length();
                idx_[p] = idx;
            }
        }
    }
    int query(const string &s) {
        int p = 0;
        for (auto &ch : s) {
            int c = ch - 'a';
            if (tr_[p][c] != 0) {
                p = tr_[p][c];
            } else {
                break;
            }
        }
        return idx_[p];
    }
private:
    static constexpr int N = 500010, M = 26;
    int tot_;
    int tr_[N][M];
    int min_len_[N];
    int idx_[N];
};

Trie tr;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        tr.clear();
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        for (int i = 0; i < n; i++) {
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            tr.insert(s, i);
        }

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            string s = wordsQuery[i];
            reverse(s.begin(), s.end());
            res[i] = tr.query(s);
        }
        return res;
    }
};


/* Official Solution 1 */
class Solution {
    struct Node {
        Node* son[26]{};
        int min_len = INT_MAX; // 子树中的最短字符串的长度
        int best_index; // 子树中的最短字符串的下标
    };

    void clear(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->son[i]) {
                clear(node->son[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Node* root = new Node();
        for (int i = 0; i < wordsContainer.size(); i++) {
            auto& s = wordsContainer[i];
            int len = s.size();
            if (len < root->min_len) {
                root->min_len = len;
                root->best_index = i;
            }

            // 把 reverse(s) 插入字典树
            auto cur = root;
            for (int j = len - 1; j >= 0; j--) {
                int b = s[j] - 'a';
                if (cur->son[b] == nullptr) {
                    cur->son[b] = new Node();
                }
                cur = cur->son[b];
                // 维护 cur 子树中的最短字符串的长度及其下标
                // 由于我们是按照 i 从小到大的顺序遍历，字符串长度相同时不更新 best_index
                if (len < cur->min_len) {
                    cur->min_len = len;
                    cur->best_index = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (auto& s : wordsQuery) {
            auto cur = root;
            for (int j = s.size() - 1; j >= 0 && cur->son[s[j] - 'a']; j--) {
                cur = cur->son[s[j] - 'a'];
            }
            // 退出循环时，cur 即最长公共前缀（的对应节点），cur->best_index 是前缀为 cur 的最短字符串的下标
            ans.push_back(cur->best_index);
        }

        clear(root);
        return ans;
    }
};
