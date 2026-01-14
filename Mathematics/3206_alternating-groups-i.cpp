class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if ((colors[i] ^ colors[(i + 1) % n] == 1) &&  (colors[(i + 1) % n] ^ colors[(i + 2) % n] == 1)) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[(i - 1 + n) % n] && colors[i] != colors[(i + 1) % n]) {
                res += 1;
            }
        }
        return res;
    }
};
