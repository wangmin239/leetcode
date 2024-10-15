class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        auto maxHeight = [](int x, int y) -> int {
            for (int i = 1;; ++i) {
                if (i % 2 == 1) {
                    x -= i;
                    if (x < 0) {
                        return i - 1;
                    }
                }
                else {
                    y -= i;
                    if (y < 0) {
                        return i - 1;
                    }
                }
            }
        };
        return max(maxHeight(red, blue), maxHeight(blue, red));
    }
};

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        auto maxHeight = [](int x, int y) -> int {
            int odd = 2 * int(sqrt(x)) - 1;
            int even = 2 * int((-1 + sqrt(1 + 4 * y)) / 2);
            return min(odd, even) + 1;
        };
        return max(maxHeight(red, blue), maxHeight(blue, red));
    }
};





class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
       function<int(int, int, int, bool)> dfs = [&](int height, int red, int blue, bool isRed) {
            if (isRed == true && red >= height) {
                return 1 + dfs(height + 1, red - height, blue, !isRed);
            }
            
            if (isRed == false && blue >= height) {
                return 1 + dfs(height + 1, red, blue - height, !isRed);
            }
            
            return 0;
        };
        
        return max(dfs(1, red, blue, true), dfs(1, red, blue, false));
    }
};


class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
       function<int(int, int, bool)> getHeight = [&](int red, int blue, bool isRed) {
            int height = 0;
            for (int level = 1; red >= level || blue >= level; ++height, level += 1, isRed = !isRed) {
                if (isRed == true) {
                    if (red >= level) {
                        red -= level;
                        continue;
                    }
                    break;
                } else {
                    if (blue >= level) {
                        blue -= level;
                        continue;
                    }
                    break;
                }
            }
            
            return height;
        };
        
        return max(getHeight(red, blue, true), getHeight(red, blue, false));
    }
};