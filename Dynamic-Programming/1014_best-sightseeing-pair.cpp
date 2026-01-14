class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = values[0] + values[1] - 1;
        int maxSum = values[0];
        
        for (int i = 1, j = 2; j < n; i++, j++) {
            int diff = values[j] - j;
            int curSum = values[i] + i;
            
            if (curSum > maxSum) {
                maxSum = curSum;
            }
            
            maxScore = max(maxScore, maxSum + diff);
        }
        
        return maxScore;
    }
};


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            // 边遍历边维护
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
