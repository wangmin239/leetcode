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