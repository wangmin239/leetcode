/* Original Solution 1 */
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int sum = 0;
        
        
        for (int left = 0, right = 1; right < n; ++right) {
            int maxTime = neededTime[left];
            int timeSpec = neededTime[left];
            
            /* Preserve the maximum time span of consecutive same-color sequences */
            while (right < n && colors[right] == colors[left]) {
                timeSpec += neededTime[right];
                maxTime = max(maxTime, neededTime[right]);
                ++right;
            }
            left = right;
            sum += timeSpec - maxTime;
        }
        
        return sum;
    }
};






/* Official Solution 2 */
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, len = colors.length();
        int ret = 0;
        while (i < len) {
            char ch = colors[i];
            int maxValue = 0;
            int sum = 0;

            while (i < len && colors[i] == ch) {
                maxValue = max(maxValue, neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            ret += sum - maxValue;
        }
        return ret;
    }
};
