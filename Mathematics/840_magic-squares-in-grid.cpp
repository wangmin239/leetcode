/* Original Solution 1 */
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int fixLen = 3;
        const int digitsCnt = 9;
        auto getMagicNum = [&](int x, int y) {
            int digits[digitsCnt] = {0};
            int sum = reduce(grid[x].begin() + y, grid[x].begin() + y + fixLen, 0);

            for (int row = 1; row < fixLen; row++) {
                int total = reduce(grid[x + row].begin() + y, grid[x + row].begin() + y + fixLen, 0);

                if (total != sum) {
                    return 0;
                }
            }

            for (int col = 0; col < fixLen; col++) {
                int total = 0;
                for (int row = 0; row < fixLen; row++) {
                    int num = grid[x + row][y + col];

                    if (num > digitsCnt || num <= 0) {
                        return 0;
                    }
                    ++digits[num - 1];
                    total += num;
                }

                if (total != sum) {
                    return 0;
                }
            }

            if (sum != grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2]) {
                return 0;
            }

            if (sum != grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y]) {
                return 0;
            }

            for (int i = 0; i < digitsCnt; i++) {
                if (digits[i] != 1) {
                    return 0;
                }
            }

            return 1;
        };


        int rows = grid.size();
        int cols = grid.front().size();
        int cnt = 0;

        for (int row = 0; row <= rows - fixLen; row++) {
            for (int col = 0; col <= cols - fixLen; col++) {
                cnt += getMagicNum(row, col);
            }
        }

        return cnt;
    }
};



/* Official Solution 1 */
class Solution {
public:
    vector<int> m={8,1,6,7,2,9,4,3,8,1,6,7,2,9,4,3};
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int di[8]={-1,-1,-1,0,1,1,1,0};
        int dj[8]={-1,0,1,1,1,0,-1,-1};
        int count=0;
        for(int i=1;i<grid.size()-1;i++)
            for(int j=1;j<grid[0].size()-1;j++)
                if(grid[i][j]==5){
                    vector<int> around;
                    for(int k=0;k<8;k++)
                        around.push_back(grid[i+di[k]][j+dj[k]]);
                    count+=IsMagic(around);
                }
        return count;
    }
    bool IsMagic(vector<int>& v){
        for(int i=0;i<8;i+=2)
            if(m[i]==v[0])
            return v==vector<int>(m.begin()+i,m.begin()+i+8)
            ||v==vector<int>(m.rbegin()+7-i,m.rbegin()+15-i);
        return false;//奇数元素
    }
};
