class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCnt = 0;
        int oCnt = 0;
        unordered_map<int, char> chBoard;
        
        for (int i = 0; i < 9; i++) {
                int row = i / 3;
                int col = i % 3;
                char ch = board[row][col];
                
                if (ch == 'X') {
                    xCnt++;
                }
                
                if (ch == 'O') {
                    oCnt++;
                }
                
                chBoard[i] = ch;
        }
        
        if (xCnt - oCnt == 1) {
            if (charWin(chBoard, 'O') == 0) {
                return true;
            }
        }
        
        if (xCnt == oCnt) {
            if (charWin(chBoard, 'X') == 0 && charWin(chBoard, 'O') < 2) {
                return true;
            }
        }
        
        return false;
    }
    
    
    int charWin(unordered_map<int, char>& chBoard, char winCh) {
        int winArr[][3] = { 
            {0, 1, 2}, {3, 4, 5}, {6, 7 ,8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };
        int cnt = 0;
        
        for (int row = 0; row < sizeof(winArr) / sizeof(winArr[0]); row++) {
            int continueCh = 0;
            for (int col = 0; col < 3; col++) {
                int index = winArr[row][col];
                if (chBoard[index] != winCh) {
                    break;
                }
                continueCh++;
            }
            
            if (continueCh == 3) {
                cnt++;
            }
        }
        
        return cnt;
            
    }
};




class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (string & row : board) {
            for (char c : row) {
                xCount = (c == 'X') ? (xCount + 1) : xCount;
                oCount = (c == 'O') ? (oCount + 1) : oCount;
            }
        }
        if (oCount != xCount && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'X') && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'O') && oCount != xCount) {
            return false;
        }
        return true;
    }

    bool win(vector<string>& board, char p) {
        for (int i = 0; i < 3; ++i) {
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) {
                return true;
            }
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) {
                return true;
            }
        }
        if (p == board[0][0] && p == board[1][1] && p == board[2][2]) {
            return true;
        }
        if (p == board[0][2] && p == board[1][1] && p == board[2][0]) {
            return true;
        }
        return false;
    }
};
