class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i > n - 3) {
                    return -1;
                }
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ans++;
            }
        }

        return ans;
    }
};





class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 1) {
                continue;
            }
            ++cnt;
            nums[i + 1] = static_cast<int>(!nums[i + 1]);
            nums[i + 2] = static_cast<int>(!nums[i + 2]);
        }
        
        if (nums[n - 1] == 0 || nums[n - 2] == 0) {
            return -1;
        }
        
        return cnt;
    }
};