

/* Original Solution 1 */
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int len = nums.size();
        int prevId = 0;

        for (int i = 0; i < len; i++) {
            if (nums[i] == key) {
                int j = max(prevId, i - k); 
                while (j < min(len, i + k + 1)) {
                    ans.push_back(j++); 
                }
                prevId = j;
            }
        }
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size();
        // 遍历数对
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && abs(i - j) <= k) {
                    res.push_back(i);
                    break;   // 提前结束以防止重复添加
                }
            }
        }
        return res;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r = 0;   // 未被判断过的最小下标
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = max(r, j - k);
                r = min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};






