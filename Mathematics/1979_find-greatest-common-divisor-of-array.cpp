/* Original Solution 1 */
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        for (int num : nums) {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        return gcd(minNum, maxNum);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return gcd(mx, mn);
    }
};
