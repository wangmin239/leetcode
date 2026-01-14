/* Original Solution 2 */
#define decimal 10

class Trie {
public:
    shared_ptr<Trie> next[decimal];
    
    Trie() {
        for (int i = 0; i < decimal; i++) {
            next[i] = nullptr;
        }
    }
};
    
void insert(shared_ptr<Trie> node, int value) {
    stack<int> st;
    
    while (value) {
        st.push(value % decimal);
        value /= decimal;
    }
    
    while (st.empty() == false) {
        int digit = st.top();
        
        st.pop();
        if (node->next[digit] == nullptr) {
            node->next[digit] = make_shared<Trie>(); 
        }
        node = node->next[digit];   
    }
}
    


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        shared_ptr<Trie> root(new Trie);
 
        for (int i = 1; i <= n; i++) {
            insert(root, i);
        }
        
        vector<int> ans;
        auto dfs = [&ans](shared_ptr<Trie> node, auto&& innerDfs, int value) {
            if (node == nullptr) {
                return;
            }
            
            for (int i = 0; i < decimal; i++) {
                if (node->next[i] != nullptr) {
                    ans.push_back(value + i);
                    innerDfs(node->next[i], innerDfs, decimal * (value + i ));
                }
            }
        };
        
        dfs(root, dfs, 0);
        return ans;
    }
};







/* Original Solution 1 */
#define decimal 10

class Trie {
public:
    Trie* next[decimal];
    
    Trie() {
        for (int i = 0; i < decimal; i++) {
            next[i] = nullptr;
        }
    }
};
    
void insert(Trie *node, int value) {
    stack<int> st;
    
    while (value) {
        st.push(value % decimal);
        value /= decimal;
    }
    
    while (st.empty() == false) {
        int digit = st.top();
        
        st.pop();
        if (node->next[digit] == nullptr) {
            node->next[digit] = new Trie; 
        }
        node = node->next[digit];   
    }
}
    


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie dummy;
        
        auto root = &dummy;
        for (int i = 1; i <= n; i++) {
            insert(root, i);
        }
        
        vector<int> ans;
        auto dfs = [&ans](Trie *node, auto&& innerDfs, int value) {
            if (node == nullptr) {
                return;
            }
            
            for (int i = 0; i < decimal; i++) {
                if (node->next[i] != nullptr) {
                    ans.push_back(value + i);
                    innerDfs(node->next[i], innerDfs, decimal * (value + i ));
                }
            }
        };
        
        dfs(root, dfs, 0);
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};
