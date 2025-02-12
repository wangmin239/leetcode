class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = (left + right) / 2;
            int ops = 0;
            
            for (int num : nums) {
                ops += (num - 1) / mid;
            }
            
            if (ops <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};


/* AI Solution */
class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        // 二分查找的左右边界
        int left = 1;
        int right = *std::max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            int operations = 0;
            // 计算当前中间值下所需的操作次数
            for (int num : nums) {
                operations += (num - 1) / mid;
            }
            if (operations <= maxOperations) {
                // 如果操作次数不超过最大操作次数，缩小右边界
                right = mid;
            } else {
                // 否则，增大左边界
                left = mid + 1;
            }
        }
        return left;
    }
};

/* Official Solution */
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            long long ops = 0;
            for (int x: nums) {
                ops += (x - 1) / y;
            }
            if (ops <= maxOperations) {
                ans = y;
                right = y - 1;
            }
            else {
                left = y + 1;
            }
        }
        return ans;
    }
};

