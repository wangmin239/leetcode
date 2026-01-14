class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans;
        
        for (int val : nums) {
            if (abs(val) < abs(ans)) {
                ans = val;
            } else if (abs(val) == abs(ans)) {
                if (val > ans) {
                    ans = val;
                }
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];   // 已遍历元素中绝对值最小且数值最大的元素
        int dis = abs(nums[0]);   // 已遍历元素的最小绝对值
        for (int num: nums) {
            if (abs(num) < dis) {
                dis = abs(num);
                res = num;
            } else if (abs(num) == dis) {
                res = max(res, num);
            }
        }
        return res;
    }
};

