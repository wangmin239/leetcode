/* Official Solution 1 */
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre;
        partial_sum(stones.begin(), stones.end(), back_inserter(pre));
        vector<int> f(n);
        f[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            f[i] = max(f[i + 1], pre[i] - f[i + 1]);
        }
        return f[1];
    }
};

/* Official Solution 2 */
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int sum = reduce(stones.begin(), stones.end());
        int f = sum;
        for (int i = stones.size() - 2; i > 0; i--) {
            sum -= stones[i + 1];
            f = max(f, sum - f);
        }
        return f;
    }
};
