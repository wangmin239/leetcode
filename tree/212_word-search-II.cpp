constexpr int dir[4][2] = {1,0, 0,1, -1,0, 0,-1};

class dt{
public:
    dt* next[26];
    string str;
    int cnt;
    dt():next{nullptr}, str(""), cnt(0){}

    void add(const string& s){
        dt* p = this;
        for(char c: s) p = p->next[c-'a'] = (p->next[c-'a'] ? p->next[c-'a'] : (p->cnt++, new dt));
        p->str = move(s);
    }

    void del(char c){
        //delete next[c-'a'];
        next[c-'a'] = nullptr;
        --cnt;
    }
};

class Solution {
public:
    dt tree;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto&& s: words) tree.add(s);
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        function<void(int, int, dt*)> dfs = [&](int x, int y, dt* root){
            dt* nextTree = root->next[board[x][y]-'a'];
            if(nextTree == nullptr) return;
            if(nextTree->str.size()) ans.emplace_back(move(nextTree->str));
            char save = 0;
            swap(save, board[x][y]);
            for(int i = 0; i < 4; ++i){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny]) dfs(nx, ny, nextTree);
            }
            swap(save, board[x][y]);
            if(nextTree->cnt == 0) root->del(board[x][y]);
        };

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                dfs(i, j, &tree);
        return ans; 
    }
};




struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode() {
        this->word = "";
    }   
};

void insertTrie(TrieNode * root, const string & word) {
    TrieNode * node = root;
    for (auto c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
        char ch = board[x][y];        
        if (!root->children.count(ch)) {
            return false;
        }
        root = root->children[ch];
        if (root->word.size() > 0 ) {
            res.insert(root->word);
            root->word = "";
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#'){
                    dfs(board, nx, ny, root,res);
                }
            }
        }
        board[x][y] = ch;
        return true;      
    }

    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        TrieNode * root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto & word: words) {
            insertTrie(root,word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }        
        for (auto & word: res) {
            ans.emplace_back(word);
        }
        return ans;        
    }
};


struct TrieNode {
    string word;
    unordered_map<char,TrieNode *> children;
    TrieNode() {
        this->word = "";
    }   
};

void insertTrie(TrieNode * root,const string & word) {
    TrieNode * node = root;
    for (auto c : word){
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
        char ch = board[x][y];        
        if (!root->children.count(ch)) {
            return false;
        }
        root = root->children[ch];
        if (root->word.size() > 0) {
            res.insert(root->word);
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root,res);
                }
            }
        }
        board[x][y] = ch;

        return true;      
    }

    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        TrieNode * root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto & word: words){
            insertTrie(root,word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }        
        for (auto & word: res) {
            ans.emplace_back(word);
        }
        return ans;        
    }
};