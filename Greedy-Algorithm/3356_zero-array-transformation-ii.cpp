/* Official Solution 1 */
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        if (!check(nums, queries, right)) {
            return -1;
        }
        while (left < right) {
            int k = (left + right) / 2;
            if (check(nums, queries, k)) {
                right = k;
            } else {
                left = k + 1;
            }
        }
        return left;
    }

private:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> deltaArray(nums.size() + 1, 0);
        for (int i = 0; i < k; ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            int value = queries[i][2];
            deltaArray[left] += value;
            deltaArray[right + 1] -= value;
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

/* Official Solution 2 */
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> deltaArray(n + 1, 0);
        int operations = 0;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            operations += deltaArray[i];
            while (k < queries.size() && operations < num) {
                int left = queries[k][0];
                int right = queries[k][1];
                int value = queries[k][2];
                deltaArray[left] += value;
                deltaArray[right + 1] -= value;
                if (left <= i && i <= right) {
                    operations += value;
                }
                k++;
            }
            if (operations < num) {
                return -1;
            }
        }
        return k;
    }
};
