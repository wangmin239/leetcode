/* Ofiicial Solution 1 */
struct Trie {
    // 当前节点结构的序列化表示
    string serial;
    // 当前节点的子节点
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // 根节点
        Trie* root = new Trie();

        for (const vector<string>& path: paths) {
            Trie* cur = root;
            for (const string& node: path) {
                if (!cur->children.count(node)) {
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }

        // 哈希表记录每一种序列化表示的出现次数
        unordered_map<string, int> freq;
        // 基于深度优先搜索的后序遍历，计算每一个节点结构的序列化表示
        function<void(Trie*)> construct = [&](Trie* node) {
            // 如果是叶节点，那么序列化表示为空字符串，无需进行任何操作
            if (node->children.empty()) {
                return;
            }

            vector<string> v;
            // 如果不是叶节点，需要先计算子节点结构的序列化表示
            for (const auto& [folder, child]: node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }
            // 防止顺序的问题，需要进行排序
            sort(v.begin(), v.end());
            for (string& s: v) {
                node->serial += move(s);
            }
            // 计入哈希表
            ++freq[node->serial];
        };

        construct(root);

        vector<vector<string>> ans;
        // 记录根节点到当前节点的路径
        vector<string> path;

        function<void(Trie*)> operate = [&](Trie* node) {
            // 如果序列化表示在哈希表中出现了超过 1 次，就需要删除
            if (freq[node->serial] > 1) {
                return;
            }
            // 否则将路径加入答案
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (const auto& [folder, child]: node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return ans;
    }
};


/* Official Solution 2 */
#include <ranges>
class Trie {
    struct Node {
        unordered_map<string_view, Node> children;
        size_t hashVal{};
    }root;
    unordered_map<size_t, size_t> hashCnt;

    size_t hash_combine(size_t a, size_t b) const {
        return a ^ (b + 0x9e3779b97f4a7c15 + (a << 12) + (a >> 4));
    }

    void setHash() {
        [&](this auto&& dfs, Node& node) -> size_t {
            size_t hash = 0;
            for (auto& [word, child] : node.children) {
                hash ^= hash_combine(std::hash<string_view>{}(word), dfs(child));
            }
            hashCnt[hash]++;
            return node.hashVal = hash;
        }(root);
    }

    void removeDuplicates() {
        [&](this auto&& dfs, Node& node) -> void {
            erase_if(node.children, [&](auto& pair) {
                auto& [word, child] = pair;
                if (child.hashVal && hashCnt[child.hashVal] > 1) {
                    return true;
                }
                else {
                    dfs(child);
                    return false;
                }
            });
        }(root);
    }
public:
    Trie(const vector<vector<string>>& paths) {
        for (const auto& path : paths) {
            insert(path);
        }
        setHash();
        removeDuplicates();
    }

    void insert(const vector<string>& words) {
        auto node = &root;
        for (auto& word : words) {
            node = &node->children.try_emplace(word, Node()).first->second;
        }
    }

    bool search(const vector<string>& path) const {
        auto node = &root;
        for (auto& word : path) {
            auto it = node->children.find(word);
            if (it == node->children.end()) return false;
            node = &it->second;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie(paths);
        return paths | views::filter([&](auto&& v) { return trie.search(v); })
                     | ranges::to<vector>();
    }
};