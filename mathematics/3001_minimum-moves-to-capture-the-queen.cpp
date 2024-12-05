class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // 车与皇后处在同一行，且中间没有象
        if (a == e && (c != a || d <= min(b, f) || d >= max(b, f))) {
            return 1;
        }
        // 车与皇后处在同一列，且中间没有象
        if (b == f && (d != b || c <= min(a, e) || c >= max(a, e))) {
            return 1;
        }
        // 象、皇后处在同一条对角线，且中间没有车
        if (abs(c - e) == abs(d - f) && ((c - e) * (b - f) != (a - e) * (d - f) 
            || a < min(c, e) || a > max(c, e))) {
            return 1;
        }
        return 2;
    }
};


class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        const int diagonals[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        bool captureQueen = false;
        auto bishopsCapture = [=](const int  diagonals[2]) {
            const int limit = 9;
            int x = c;
            int y = d;

            while (x > 0 && x < 9 && y > 0 && y < 9) {
                if (x == a && y == b) {
                    return false;
                }
                
                if (x == e && y == f) {
                    return true;
                }
                
                x +=  diagonals[0];
                y +=  diagonals[1];
            }
            return false;
        };
        
        for (size_t i = 0; i < sizeof(diagonals) / sizeof(diagonals[0]); i++) {
            captureQueen |= bishopsCapture(diagonals[i]);
        }
        /* rooks captures queen */
        const int horOrVert[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        auto rooksCapture = [=] (const int moves[2]) {
            int x = a;
            int y = b;
            const int limit = 9;
            
            while (x > 0 && x < 9 && y > 0 && y < 9) {
                if (x == e &&  y == f) {
                    return true;
                }
                
                if (x == c && y == d) {
                    return false;
                }
                x += moves[0];
                y += moves[1];
            }
            return false;
        };
        
        for (size_t i = 0; i < sizeof(horOrVert) / sizeof(horOrVert[0]); i++) {
            captureQueen |= rooksCapture(horOrVert[i]);
        }
        return captureQueen == true ? 1 : 2;
    }
};





