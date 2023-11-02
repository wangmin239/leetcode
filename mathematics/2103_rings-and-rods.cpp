class Solution {
public:
    static constexpr int POLE_NUM = 10;
    static constexpr int COLOR_NUM = 3;
    int getColorId(char color) {
        if (color == 'R') {
            return 0;
        } else if (color == 'G') {
            return 1;
        }
        return 2;
    }
    int countPoints(string rings) {
        vector<vector<int>> state(POLE_NUM, vector<int>(COLOR_NUM, 0));
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i + 1] - '0';
            state[pole_index][getColorId(color)] = 1;
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            bool flag = true;
            for (int j = 0; j < COLOR_NUM; j++) {
                if (state[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    static constexpr int POLE_NUM = 10;
    int countPoints(string rings) {
        vector<int> state(POLE_NUM);
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i + 1] - '0';
            if (color == 'R') {
                state[pole_index] |= 1;
            } else if (color == 'G') {
                state[pole_index] |= 2;
            } else {
                state[pole_index] |= 4;
            }
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            res += state[i] == 7;
        }
        return res;
    }
};




class Solution {
public:
    typedef enum color {
        Red = 0,
        Green = 1,
        Blue = 2,
    } color;

    int countPoints(string rings) {
        int len = rings.length();     
        int ptr[10] = {{0}};
        
        for (int i = 1; i < len; i += 2) {
            int index = rings[i] - '0';
            char ch = rings[i - 1];
            
            switch(ch) {
                case 'R':
                    ptr[index] |= 1 << Red;
                    break;
                case 'G':
                    ptr[index] |= 1 << Green;
                    break;
                default:
                    ptr[index] |= 1 << Blue;
            }   
        }
        
        int cnt = 0;
        const int mask = 0x7;
        for (int val : ptr) {
            if (val == mask) {
                ++cnt;
            }
        }
        return cnt;
    }
};
"B9R9G0R4G6R8R2R9G9"