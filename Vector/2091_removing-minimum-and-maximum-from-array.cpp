/* Original Solution 1 */
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxPos = max_element(nums.begin(), nums.end()) - nums.begin();
        int minPos = min_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int miniOps = n;

        miniOps = min(miniOps, max(maxPos, minPos) + 1);
        miniOps = min(miniOps, n - min(maxPos, minPos));

        if (maxPos < minPos) {
            miniOps = min(miniOps, maxPos + 1 + n - minPos);
        } else {
            miniOps = min(miniOps, minPos + 1 + n - maxPos);
        }

        return miniOps;

    }
};


/* Official Solution 1 */
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(minidx, maxidx);   // 最值下标中的较小值
        int r = max(minidx, maxidx);   // 最值下标中的较大值
        return min({r + 1, n - l, l + 1 + n - r});   // 计算三种情况下删除次数的最小值
    }
};
