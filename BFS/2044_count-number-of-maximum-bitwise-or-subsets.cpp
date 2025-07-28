/* Official Solution 1 */
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue) {
                cnt++;
            } else if (cur > maxValue) {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }

    void dfs(int pos, int orVal) {
        if (pos == nums.size()) {
            if (orVal > maxOr) {
                maxOr = orVal;
                cnt = 1;
            } else if (orVal == maxOr) {
                cnt++;
            }
            return;
        }
        dfs(pos + 1, orVal| nums[pos]);
        dfs(pos + 1, orVal);
    }

private:
    vector<int> nums;
    int maxOr, cnt;
};
