/* Original Solution 1 */
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), greater<int>());

        for (int i = 0; i < k; i++) {
            sum += max(happiness[i] - i, 0);
        }

        return sum;
    }
};