/* The first method. */
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


/* The second method. */

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

/* The third method. */
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

/* The forth method. */

class Solution {
public:
	int d_col[4] = { 0,1,0,-1 };
	int d_row[4] = { -1,0,1,0 };
public:
	vector<string> findWords (vector<vector<char>>& board, vector<string>& words) {
		map<char, vector<int>> charMap;
		for(int i = 0; i < board.size (); i++) {
			for(int j = 0; j < board[0].size (); j++) {
				charMap[board[i][j]].push_back (i * board[0].size () + j);
			}
		}

		vector<string> ans;
		for(int i = 0; i < words.size (); i++) {
			int var1 = canMatch (words[i], charMap);
			if(var1 == -1)continue;
			for(int number : charMap[words[i][var1]]) {
				set<char> isMatched;
				isMatched.insert (number);
				int matchWay = var1 == 0 ? 1 : -1;
				if(dfs (words[i], var1, isMatched, board, number, matchWay)) {
					ans.push_back (words[i]);
					break;
				}
			}
		}

		return ans;
	}

	//-1代表不行，0代表建议从头匹配，返回 字符串长度减一 代表建议从尾匹配
	int canMatch (string& s, map<char, vector<int>>& charMap) {
		map<char, int> mapCnt;
		int size = s.size ();
		for(int i = 0; i < size; i++) {
			mapCnt[s[i]]++;
		}
		for(map<char, int>::iterator iter = mapCnt.begin (); iter != mapCnt.end (); iter++) {
			if(charMap.find (iter->first) == charMap.end ())return -1;
			if(iter->second > charMap[iter->first].size ())return -1;
		}
		return charMap[s[0]].size() < charMap[s[size - 1]].size() ? 0 : size - 1;
	}

	bool dfs (string& word, int index, set<char>& isMatched, vector<vector<char>>& board, int number, int matchWay) {
		if(index == (matchWay == 1 ? word.length () - 1 : 0))return true;

		int row = number / board[0].size ();
		int col = number - row * board[0].size ();
		for(int i = 0; i < 4; i++) {
			int row1 = row + d_row[i], col1 = col + d_col[i];
			int number1 = row1 * board[0].size () + col1;
			if(isMatched.find (number1) != isMatched.end ())continue;
			if(row1 < 0 || row1 >= board.size () || col1 < 0 || col1 >= board[0].size () || word[index + matchWay] != board[row1][col1])continue;

			isMatched.insert (number1);
			if(dfs (word, index + matchWay, isMatched, board, number1, matchWay))return true;
			isMatched.erase (number1);
		}

		return false;
	}
};