/* Original Solution 1 */
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        unordered_map<int, int> numFreq;

        for (const auto& rows : grid) {
            for (int val : rows) {
                ++numFreq[val];
            }
        }

        int operCnt = INT_MAX;

        for (auto iter = numFreq.begin(); iter != numFreq.end(); ++iter) {
            int curCnt = 0;
            bool isValid = true;

            for (auto curIter = numFreq.begin(); curIter != numFreq.end(); ++curIter) {
                if (curIter == iter) {
                    continue;
                }

                int diff = abs(iter->first - curIter->first);
                if (diff % x != 0) {
                    isValid = false;
                    break;
                }

                curCnt += (diff / x) * curIter->second;
            }

            if (isValid == true) {
                operCnt = min(operCnt, curCnt);
            }
        }

        return operCnt ==  INT_MAX ? -1 : operCnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((grid[i][j] - grid[0][0]) % x != 0) {
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int choose = nums[nums.size() / 2];
        int ans = 0;
        for (int num: nums) {
            ans += abs(num - choose) / x;
        }
        return ans;
    }
};
