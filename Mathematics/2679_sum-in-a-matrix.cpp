class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0;
        int m = nums.size();
        int n = nums[0].size();
        vector<priority_queue<int>> pq(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq[i].emplace(nums[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, pq[i].top());
                pq[i].pop();
            }
            res += maxVal;
        }
        return res;
    }
};




class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int rows = nums.size();
        
        for (int row = 0; row < rows; row++) {
            sort(nums[row].begin(), nums[row].end());
        }
        
        auto getColMaxVal = [&nums, &rows](int col) {
            int maxVal = nums[0][col];
            
            for (int row = 1; row < rows; row++) {
                maxVal = max(maxVal, nums[row][col]);
            }
            return maxVal;
        };
        
        int cols = nums.front().size();
        int sum = 0;
        for (int col = 0; col < cols; col++) {
            sum += getColMaxVal(col);
        }
        return sum;
    }
};