/* Original Solution 1 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int len = nums.size();
        
        for (int left = 0, right = 0; left < len; left++) {
            if (nums[left] != 0) {
                continue;
            }
            int cnt = 1;
            /* Identify the partition that contains consecutive zero values. */
            right = left + 1;
            ans += cnt++;
            while (right < len && nums[right] == 0) {
                right++;
                ans += cnt++;
            }

            left = right;
        }
        
        return ans;
    }
};




/* Original Solution 2 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int len = nums.size();
        
        for (int left = 0, right = 0; left < len; left++) {
            if (nums[left] != 0) {
                continue;
            }
            
            /* Identify the partition that contains consecutive zero values. */
            right = left + 1;
            while (right < len && nums[right] == 0) {
                right++;
            }
            
            int cnt = right - left;
            
            ans += 1LL * (cnt + 1) * cnt / 2;
            left = right;
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                last = i; // 记录上一个非 0 元素的位置
            } else {
                ans += i - last;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt0 = 0;
        for (int x : nums) {
            if (x) {
                cnt0 = 0;
            } else {
                cnt0++; // 右端点为 i 的全 0 子数组比右端点为 i-1 的全 0 子数组多一个
                ans += cnt0;
            }
        }
        return ans;
    }
};
