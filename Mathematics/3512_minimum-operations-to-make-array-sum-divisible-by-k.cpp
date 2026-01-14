/* Original Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;

        for (const int num : nums) {
            operations += num;
            operations %= k;
        }

        return operations;
    }
};