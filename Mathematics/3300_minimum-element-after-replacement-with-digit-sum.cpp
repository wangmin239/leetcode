/* Original Solution 1 */
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        const int decimal = 10;

        for (int value : nums) {
            int sum = 0;

            while (value) {
                sum += value % decimal;
                value /= decimal;
            }

            ans = min(sum, ans);
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 37;
        for (int num : nums) {
            int dig = 0;
            while(num){
                dig += num % 10;
                num /= 10;
            }
            ans = min(ans, dig);
        }
        return ans;
    }
};
