class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};


class Trie {
public:
    Trie() {
        this->children = vector<Trie*>(10, nullptr);
        this->isEnd = false;
    }
    
    bool insert(const string& str) {
        Trie *node = this;
        
        for (const char& ch : str) {
            int index = ch - '0';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }
    

   vector<Trie*> children;
   bool isEnd;


};

class Solution {
public:
    int findKthNumber(int n, int k) {
        Trie trie;
        
        for (int i = 1; i <= n; i++) {
            trie.insert(to_string(i));
        }
        
        string ans;
        string answer;
        auto dfs = [&](Trie* node, auto&& dfs) {
            if (node->isEnd == true) {
                --k;
            }
            
            if (k == 0) {
                answer = ans;
                return ;
            }
            

            for (int i = 0; i < 10; i++) {
                if (node->children[i] == nullptr) {
                    continue;
                }
                ans.push_back('0' + i);
                dfs(node->children[i], dfs);
                ans.pop_back();
            }
        };
        
        dfs(&trie, dfs);
        
        return stol(answer);
    }
};