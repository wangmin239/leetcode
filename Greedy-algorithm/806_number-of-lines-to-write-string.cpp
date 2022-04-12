class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int rows = 1;
        int cols = 0;
        const int limit = 100;
        
        for (char ch : s) {
            int width = widths[ch - 'a'];
            if (cols == limit || cols + width > limit) {
                rows++;
                cols = 0;
            } 
            cols += width;

        }
        
        return {rows , cols};
    }
};


const int MAX_WIDTH = 100;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int width = 0;
        for (auto & c : s) {
            int need = widths[c - 'a'];
            width += need;
            if (width > MAX_WIDTH) {
                lines++;
                width = need;
            }
        }
        return {lines, width};
    }
};
