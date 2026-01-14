/* Original Solution */
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        
        for (const auto& query : queries) {
            int left = query.front();
            int right = query.back();
            
            preSum[left] -= 1;
            preSum[right + 1] += 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (preSum[i] + nums[i] > 0) {
                return false;
            }
            preSum[i + 1] += preSum[i];
        }
        
        return true;
    }
};

/* Offocial Solution */
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> deltaArray(nums.size() + 1, 0);
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            deltaArray[left] += 1;
            deltaArray[right + 1] -= 1;
        }
        vector<int> operationCounts;
        int currentOperations = 0;
        for (int delta : deltaArray) {
            currentOperations += delta;
            operationCounts.push_back(currentOperations);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (operationCounts[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};


