/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        
        if (root == nullptr) {
            return ans;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        while (que.empty() == false) {
            int size = que.size();
            
            while (size-- != 0) {
                auto node = que.front();
                que.pop();
                
                if (node == nullptr) {
                    ans.append("NULL,");
                    continue;
                }
                
                auto [val, left, right] = *node;

                ans.append(to_string(val) + ",");
                que.push(left);
                que.push(right);
                
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        
        if (data.length() == 0) {
            return root;
        }
        
        const char delm = ',';
        string::size_type start = 0;
        auto end = data.find(delm, start);
        
        root = new TreeNode(stoi(data.substr(start, end - start)));
        
        queue<TreeNode*> que;
        que.push(root);
        while (que.empty() == false) {
            int size = que.size();
            while (size-- != 0) {
                auto node = que.front();
                que.pop();
                
                start = end + 1;
                end = data.find(delm, start);
                auto str = data.substr(start, end - start);
                
                if (str != "NULL") {
                    node->left = new TreeNode(stoi(str));
                    que.push(node->left);
                }
                
                start = end + 1;
                end = data.find(delm, start);
                str = data.substr(start, end - start);
                
                if (str != "NULL") {
                    node->right = new TreeNode(stoi(str));
                    que.push(node->right);
                }
               
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;



class Codec {
public:
    string serialize(TreeNode* root) {
        string res;
        vector<int> arr;
        postOrder(root, arr);
        if (arr.size() == 0) {
            return res;
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            res.append(to_string(arr[i]) + ",");
        }
        res.append(to_string(arr.back()));
        return res;
    }

    vector<string> split(const string &str, char dec) {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == dec) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != dec) {
                pos++;
            }
            if (start < str.size()) {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        vector<string> arr = split(data, ',');
        stack<int> st;
        for (auto & str : arr) {
            st.emplace(stoi(str));
        }
        return construct(INT_MIN, INT_MAX, st);
    }

    void postOrder(TreeNode *root,vector<int> & arr) {
        if (root == nullptr) {
            return;
        }
        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.emplace_back(root->val);
    }

    TreeNode * construct(int lower, int upper, stack<int> & st) {
        if (st.size() == 0 || st.top() < lower || st.top() > upper) {
            return nullptr;
        }
        int val = st.top();
        st.pop();
        TreeNode *root = new TreeNode(val);
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root;
    }
};



class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};
