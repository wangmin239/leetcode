class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt = 0, st = 0, ed = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    st = i;
                    ed = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int step = 0;; ++step) {
                int tx = st + step * dx[i];
                int ty = ed + step * dy[i];
                if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') {
                    break;
                }
                if (board[tx][ty] == 'p') {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};



class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board.front().size();
        pair<int, int> rooks;
        
        /* obtain the positions of the rooks */
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'R') {
                    rooks = make_pair(row, col);
                    goto GetRooks;
                }
            }
        }
GetRooks:         
        auto capturePawns = [&](const pair<int, int>& rooks) {
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            int pawns = 0;
            
            for (size_t i = 0; i < sizeof(directions) / sizeof(directions[0]); i++) {
                int x = rooks.first;
                int y = rooks.second;
                
                while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                    if (board[x][y] == 'B') {
                        break;
                    }
                    
                    if (board[x][y] == 'p') {
                        ++pawns;
                        break;
                    }
                    x += directions[i][0];
                    y += directions[i][1];
                }
            }
            return pawns;
        };
       
        return capturePawns(rooks);
    }
};


