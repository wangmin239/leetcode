/* Official Solution */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};


/* The Latest Original Solution */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid.front().size();
        
        vector<int> dp(cols, 0);
        
        /* One obstacle locates the start point. */
        if (obstacleGrid[0][0] != 0) {
            return 0;
        }
        
        
        dp[0] = 1;
        for (int row = 0; row < rows; row++) {
            /* Check if the first cell is occupied by one obstacle of every row. */
            if (obstacleGrid[row][0] != 0) {
                dp[0] = 0;
            }

            for (int col = 1; col < cols; col++) {
                if (obstacleGrid[row][col] != 0) {
                    dp[col] = 0;
                } else {
                    dp[col] += dp[col - 1];  
                }
            }
        }
        
        return dp[cols - 1];
    }
};




/* The Previous Original Solution*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int row = obstacleGrid.size();
    	int col = obstacleGrid.front().size();

    	vector<int> dp(col + 1, 1);
    	dp[0] = 0;
    	for (int i = 0; i < col; i++) {
    		if (obstacleGrid[0][i] == 1) {
    			for (int j = i; j < col; j++) {
    				dp[j + 1] = 0;
    			}
    			break;
    		}
    	}


    	for (int i = 1; i < row; i++) {
    		for (int j = 0; j < col; j++) {
    			if (obstacleGrid[i][j] == 0) {
    				dp[j + 1] += dp[j];
    			} else {
    				dp[j + 1] = 0;
    			}
    		}
    	}
    	return dp[col];
    }
};
