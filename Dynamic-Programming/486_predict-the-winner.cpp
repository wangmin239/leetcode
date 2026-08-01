/* Original Solution 1 */
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        auto dfs = [&](int left, int right, auto& self) {
            if (left > right) {
                return 0;
            }
                
            if (left == right) {
                return nums[left];
            }
            
            int peerFront = self(left + 1, right, self);
            int peerBack = self(left, right - 1, self);
            
            if (peerFront >= peerBack) {
                return nums[right] + min(self(left, right - 2, self), self(left + 1, right - 1, self));
            }
            return nums[left] + min(self(left + 2, right, self), self(left + 1, right - 1, self));
        };
        
        int firstPoints = dfs(0, n - 1, dfs);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        return firstPoints >= sum - firstPoints;
        
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }

    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
        return max(scoreStart * turn, scoreEnd * turn) * turn;
    }
};


/* Official Solution 2 */
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int length = nums.size();
        auto dp = vector<int>(length);
        for (int i = 0; i < length; i++) {
            dp[i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[length - 1] >= 0;
    }
};
