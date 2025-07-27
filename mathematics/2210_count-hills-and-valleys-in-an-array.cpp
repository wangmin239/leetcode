/* Original Solution 1 */
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int len = nums.size() - 1;
        int cnt = 0;
        int peek = nums.front();
        
        for (int i = 1; i < len; i++) {
            /* In the case that calculating the number of the hills */
            if (nums[i] > nums[i - 1])  {
                int j = i;
                while (j < len && nums[j + 1] >= nums[j]) {
                    j++;
                }
                
                if (j != len) {
                    ++cnt;
                }
                i = j;
                continue;
            }
            /* In the case that calculating the number of the valley */            
            if (nums[i] < nums[i - 1]) {
                int j = i;
                while (j < len && nums[j + 1] <= nums[j]) {
                    j++;
                }
                if (j != len) {
                    ++cnt;
                }
                i = j;
            }
        }
        return cnt;
        
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;   // 峰与谷的数量
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i-1]) {
                // 去重
                continue;
            }
            int left = 0;   // 左边可能的不相等邻居对应状态
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] > nums[i]) {
                    left = 1;
                    break;
                } else if (nums[j] < nums[i]) {
                    left = -1;
                    break;
                }
            }
            int right = 0;   // 右边可能的不相等邻居对应状态
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    right = 1;
                    break;
                } else if (nums[j] < nums[i]) {
                    right = -1;
                    break;
                }
            }
            if (left == right && left != 0) {
                // 此时下标 i 为峰或谷的一部分
                ++res;
            }
        }
        return res;   
    }
};
