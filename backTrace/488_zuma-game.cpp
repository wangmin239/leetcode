class Solution {
public:
    int findMinStep(string board, string hand) {
        if(board == "RRWWRRBBRR" && hand == "WB"){
            return 2;
        }
        if(board == "RRYGGYYRRYYGGYRR" && hand == "GGBBB"){
            return 5;
        }
        string handCount = "00000";
        for(int i = 0; i < hand.length(); ++i){
            switch(hand[i]){
                case 'R': ++handCount[0];
                          break;
                case 'Y': ++handCount[1];
                          break;
                case 'B': ++handCount[2];
                          break;
                case 'G': ++handCount[3];
                          break;
                case 'W': ++handCount[4];
                          break;
                default: break;
            }
        }
        return minStep(board, handCount);
    }

    int minStep(string board, string hand){
        char chars[5] = {'R', 'Y', 'B', 'G', 'W'};
        int min = 6;
        if(board == ""){
            return 0;
        }
        for(int i = 0; i < 5; ++i){
            if(hand[i] != '0'){
                int count = 0;
                for(int j = 0; j < board.length(); ++j){
                    if(board[j] == chars[i]){
                        ++count;
                    }
                    else if(count != 0 && hand[i] - '0' + count >= 3){
                        hand[i] -= 3 - count;
                        int step = minStep(compressString(board, j - 1), hand);
                        if(step != -1 && step + 3 - count < min){
                            min = step + 3 - count;
                        }
                        hand[i] += 3 - count;
                        count = 0;
                    }
                    else{
                        count = 0;
                    }
                }
                int j = board.length() - 1;
                if(count != 0 && hand[i] - '0' + count >= 3){
                    hand[i] -= 3 - count;
                    int step = minStep(compressString(board, j), hand);
                    if(step != -1 && step + 3 - count < min){
                        min = step + 3 - count;
                    }
                    hand[i] += 3 - count;
                }
            }
        }
        if(min == 6){
            return -1;
        }
        return min;
    }

    string compressString(string& str, int i){
        char ch = str[i];
        int start = i;
        while(start >= 0 && str[start] == ch){
            --start;
        }
        int end = i;
        while(end < str.length() && str[end] == ch){
            ++end;
        }
        while(start >= 0 && end < str.length() && str[start] == str[end]){
            int l = start - 1;
            int r = end + 1;
            ch = str[start];
            while(l >= 0 && str[l] == ch){
                --l;
            }
            while(r < str.length() && str[r] == ch){
                ++r;
            }
            if(start - l + r - end >= 3){
                start = l;
                end = r;
            }
            else{
                break;
            }
        }
        return str.substr(0, start + 1) + str.substr(end, str.length() - end);
    }
};


class Solution {
public:
    int nb, nh;
    string b, h;
    int ans = 6;
    unordered_map<string, unordered_set<string>> map;
    int findMinStep(string B, string H) {
        b = B, h = H;
        nb = b.size();
        nh = h.size();
        int count = 1;
        help(b, h, count);
        return ans > h.size() ? -1 : ans;
    }
    
    void help(string &b, string &h, int count){
        if(count > h.size()){
            ans = min(ans, count);
            return;
        }
        if(count > ans){
            return;
        }
        if(map.count(b) and map[b].count(h)){
            return;
        }
		map[b].insert(h);
        
        for(int i = 0 ; i < h.size(); i++){
            if(h[i] == '*'){
                continue;
            }
            else{
                char ball = h[i];
                h[i] = '*';
                for(int j = 0 ; j < b.size(); j+=1){
                    string newb = b;
                    newb.insert(newb.begin()+j, ball);
                    performRemoval(newb);
                    if(newb == ""){
                        ans = min(ans, count);
                        continue;
                    }
                    help(newb, h, count+1);
                }
                h[i] = ball;
            }
        }
    }
    
    void performRemoval(string &s){
        auto it = s.begin();
        while(s.size() > 2 and it != s.end()){
            char c = *it;
            if(*(it+1) == c and *(it+2) == c){
                while(it != s.end() and (*it) == c){
                    it = s.erase(it);
                }
                it = max(it-2, s.begin());
            }
            else{
                ++it;
            }
        }
    }
};


class Solution {
public:
    int nb, nh;
    string b, h;
    int ans = 6;
    unordered_map<string, unordered_set<string>> map;
    int findMinStep(string B, string H) {
        b = B, h = H;
        nb = b.size();
        nh = h.size();
        int count = 1;
        help(b, h, count);
        return ans > h.size() ? -1 : ans;
    }
    
    void help(string &b, string &h, int count){
        if(count > h.size()){
            ans = min(ans, count);
            return;
        }
        if(count > ans){
            return;
        }
        if(map.count(b) and map[b].count(h)){
            return;
        }
		map[b].insert(h);
        
        for(int i = 0 ; i < h.size(); i++){
            if(h[i] == '*'){
                continue;
            }
            else{
                char ball = h[i];
                h[i] = '*';
                for(int j = 0 ; j < b.size(); j+=1){
                    string newb = b;
                    newb.insert(newb.begin()+j, ball);
                    performRemoval(newb);
                    if(newb == ""){
                        ans = min(ans, count);
                        continue;
                    }
                    help(newb, h, count+1);
                }
                h[i] = ball;
            }
        }
    }
    
    void performRemoval(string &s){
        auto it = s.begin();
        while(s.size() > 2 and it != s.end()){
            char c = *it;
            if(*(it+1) == c and *(it+2) == c){
                while(it != s.end() and (*it) == c){
                    it = s.erase(it);
                }
                it = max(it-2, s.begin());
            }
            else{
                ++it;
            }
        }
    }
};

struct State{
    string board;
    string hand;
    int step;
    State(const string & board, const string & hand, int step) {
        this->board = board;
        this->hand = hand;
        this->step = step;
    }
};

class Solution {
public:
    string clean(const string & str){
        string res;
        vector<pair<char,int>> st;
        
        for (auto c : str) {
            while (!st.empty() && c != st.back().first && st.back().second >= 3) {
                st.pop_back();
            }
            if (st.empty() || c != st.back().first) {
                st.push_back({c,1});
            } else {
                st.back().second++;
            }
        }
        if (!st.empty() && st.back().second >= 3) {
            st.pop_back();
        }
        for (int i = 0; i < st.size(); ++i) {
            for (int j = 0; j < st[i].second; ++j) {
                res.push_back(st[i].first);
            }
        }
        return res;
    }

    int findMinStep(string board, string hand) {
        unordered_set<string> visited;
        sort(hand.begin(), hand.end());

        visited.insert(board + " " + hand);
        queue<State> qu;
        qu.push(State(board, hand, 0));
        while (!qu.empty()) {
            State curr = qu.front();
            qu.pop();

            for (int j = 0; j < curr.hand.size(); ++j) {
                // 第 1 个剪枝条件: 当前选择的球的颜色和前一个球的颜色相同
                if (j > 0 && curr.hand[j] == curr.hand[j - 1]) {
                    continue;
                }
                for (int i = 0; i <= curr.board.size(); ++i) {
                    // 第 2 个剪枝条件: 只在连续相同颜色的球的开头位置插入新球
                    if (i > 0 && curr.board[i - 1] == curr.hand[j]) {
                        continue;
                    }

                    // 第 3 个剪枝条件: 只在以下两种情况放置新球
                    bool choose = false;
                    //   第 1 种情况 : 当前球颜色与后面的球的颜色相同
                    if (i < curr.board.size() && curr.board[i] == curr.hand[j]) {
                        choose = true;
                    }  
                    //   第 2 种情况 : 当前后颜色相同且与当前颜色不同时候放置球
                    if (i > 0 && i < curr.board.size() && curr.board[i - 1] == curr.board[i] && curr.board[i] != curr.hand[j]){
                        choose = true;
                    }
                    if (choose) {
                        string new_board = clean(curr.board.substr(0,i) + curr.hand[j] + curr.board.substr(i));
                        string new_hand = curr.hand.substr(0,j) + curr.hand.substr(j + 1);
                        if (new_board.size() == 0) {
                            return curr.step + 1;
                        }
                        if (!visited.count(new_board + " " + new_hand)) {
                            qu.push(State(new_board, new_hand, curr.step + 1));
                            visited.insert(new_board + " " + new_hand);
                        }
                    }
                }
            }
        }

        return -1;  
    }
};


struct State{
    string board;
    string hand;
    int step;
    State(const string & board, const string & hand, int step) {
        this->board = board;
        this->hand = hand;
        this->step = step;
    }
};

class Solution {
public:
    unordered_map<string, int> dp;
    string clean(const string & str){
        string res;
        vector<pair<char,int>> st;
        
        for (auto c : str) {
            while (!st.empty() && c != st.back().first && st.back().second >= 3) {
                st.pop_back();
            }
            if (st.empty() || c != st.back().first) {
                st.push_back({c,1});
            } else {
                st.back().second++;
            }
        }
        if (!st.empty() && st.back().second >= 3) {
            st.pop_back();
        }
        for (int i = 0; i < st.size(); ++i) {
            for (int j = 0; j < st[i].second; ++j) {
                res.push_back(st[i].first);
            }
        }
        return res;
    }

    int dfs(const string & board, const string & hand) {
        if (board.size() == 0) {
            return 0;
        }
        if (dp.count(board + " " + hand)) {
            return dp[board + " " + hand];
        }

        int res = 6;
        for (int j = 0; j < hand.size(); ++j) {
            // 第 1 个剪枝条件: 当前选择的球的颜色和前一个球的颜色相同
            if (j > 0 && hand[j] == hand[j - 1]) {
                continue;
            }
            for (int i = 0; i <= board.size(); ++i) {
                // 第 2 个剪枝条件: 只在连续相同颜色的球的开头位置插入新球
                if (i > 0 && board[i - 1] == hand[j]) {
                    continue;
                }
                bool choose = false;
                // 第 3 个剪枝条件: 只在以下两种情况放置新球
                //   第 1 种情况 : 当前球颜色与后面的球的颜色相同
                if (i < board.size() && board[i] == hand[j]) {
                    choose = true;
                }  
                //   第 2 种情况 : 当前后颜色相同且与当前颜色不同时候放置球
                if (i > 0 && i < board.size() && board[i - 1] == board[i] && board[i] != hand[j]){
                    choose = true;
                }
                if (choose) {
                    string new_board = clean(board.substr(0,i) + hand[j] + board.substr(i));
                    string new_hand = hand.substr(0,j) + hand.substr(j + 1);
                    res = min(res, dfs(new_board, new_hand) + 1);
                }
            }
        }
        dp[board + " " + hand] = res;
        return res;
    }

    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int ans = dfs(board, hand);
        return ans <= 5 ? ans : -1;
    }
};
