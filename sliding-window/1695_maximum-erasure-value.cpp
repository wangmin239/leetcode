
/* Original Solution 1 */
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int score = 0;
        int len = nums.size();
        unordered_map<int, int> digits;
        int maxScore = 0;
        
        for (int left = 0, right = 0; right < len; right++) {
            int curVal = nums[right];
            
            score += curVal;
            if (digits.count(curVal) == 0) {
                digits[curVal] = 1;
            } else {
                ++digits[curVal];
            }
            
            while (digits[curVal] > 1) {
                score -= nums[left];
                --digits[nums[left++]];
            }
            
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int ans = 0, psum = 0;
        for(int i = 0, j = 0; i < n; ++i) {
            psum += nums[i];
            while (seen.count(nums[i])) {
                seen.erase(nums[j]);
                psum -= nums[j];
                j++;
            }
            seen.emplace(nums[i]);
            ans = max(ans, psum);
        }
        
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> psum(n + 1);
        unordered_map<int, int> cnt;
        int ans = 0, pre = 0;
        for(int i = 0; i < n; ++i) {
            psum[i + 1] = psum[i] + nums[i];
            pre = max(pre, cnt[nums[i]]);
            ans = max(ans, psum[i + 1] - psum[pre]);
            cnt[nums[i]] = i + 1;
        }
        
        return ans;
    }
};
