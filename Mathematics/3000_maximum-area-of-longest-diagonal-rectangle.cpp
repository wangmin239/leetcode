/* Original Solution 1 */
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diagonalLen = 0;
        int area = 0;
        
        for (auto& dim : dimensions) {
            int length = dim.front();
            int width = dim.back();
            int curDiagonalLen = length * length + width * width;
            
            /* Update the maximum diagonal length */
            if (curDiagonalLen > diagonalLen) {
                area = length * width;
                diagonalLen = curDiagonalLen;
            } else if (curDiagonalLen == diagonalLen) {
                area = max(area, length * width);
            }
        }
        
        return area;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiaSq = 0, maxArea = 0;
        for (const auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diaSq = l * l + w * w, area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
