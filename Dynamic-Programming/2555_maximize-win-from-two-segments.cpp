class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k) - prizePositions.begin();
            ans = max(ans, i - x + 1 + dp[x]);
            dp[i + 1] = max(dp[i], i - x + 1);
        }
        return ans;
    }
};



class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1);
        int ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            ans = max(ans, right - left + 1 + dp[left]);
            dp[right + 1] = max(dp[right], right - left + 1);
        }
        return ans;
    }
};





class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int limit = *max_element(prizePositions.begin(), prizePositions.end());
        map<int, int> nums;

        for (int pos : prizePositions) {
            ++nums[pos];
        }

        auto getMaxPrize = [&](int k, int& outPos) {
            int maxSum = 0;
            int curSum = 0;
            auto left = nums.begin();
            for (auto  right = left; right != nums.end(); ++right) {
                if (right->first - left->first <= k) {
                    curSum += right->second;
                    continue;
                }
                if (curSum > maxSum) {
                    maxSum = curSum;
                    outPos = left->first;
                }
                curSum += right->second;
                while (right->first - left->first > k) {
                    curSum -= left->second;
                    ++left;
                }
            }
            
            if (curSum > maxSum) {
                maxSum = curSum;
                outPos = left->first;
            }
            
            return maxSum;
        };
        
        int outPos;
        int maxSum = getMaxPrize(k, outPos);

        /* remove the first range */
        for (int i = outPos; i <= outPos + k; i++) {
            if (nums.count(i)) {
                nums[i] = 0;
            }
        }
        
        maxSum += getMaxPrize(k, outPos);
        return maxSum;
    }
    

};