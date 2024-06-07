class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size(), t = 0;
        for (int i = 1; i < n; i += 2) {
            if (nums[i] + nums[i - 1] != nums[1] + nums[0]) {
                break;
            }
            t++;
        }
        return t;
    }
};



class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int len = nums.size();
        int sum = nums[0] + nums[1];
        int cnt = 1;

        for (int i = 2; i < len - 1; i += 2) {
            if (sum == nums[i] + nums[i + 1]) {
                break;
            }
            ++cnt;
        }

        return cnt;
    }
};