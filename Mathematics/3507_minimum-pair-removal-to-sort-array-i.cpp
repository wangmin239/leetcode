/* Original Solution 1 */
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        auto checkAscendOrder = [&](int size) {
            for (int i = 1; i < size; i++) {
                if (nums[i] < nums[i - 1]) {
                    return false;
                }
            }
            return true;
        };

        auto getPos = [&]() {
          int sum = INT_MAX;
          int pos = 0;

          for (int i = 1; i < n - cnt; i++) {
              int adjSum = nums[i - 1] + nums[i];
              if (adjSum < sum) {
                  sum = adjSum;
                  pos = i - 1;
              }
          }

          if (sum == INT_MAX) {
              return pos;
          }

          /* replenish the remain elements */
          nums[pos] = sum;
          ++cnt;
          for (int i = pos + 1; i < n - cnt; i++) {
              nums[i] = nums[i + 1];
          }
          return pos;
        };

        while (checkAscendOrder(n - cnt) != true) {
            getPos();
        }

        return cnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n);
        std::iota(next.begin(), next.end(), 1);
        next[n - 1] = -1;
        int count = 0;

        while (n - count > 1) {
            int curr = 0;
            int target = 0;
            int targetAdjSum = nums[target] + nums[next[target]];
            bool isAscending = true;

            while (curr != -1 && next[curr] != -1) {
                if (nums[curr] > nums[next[curr]]) {
                    isAscending = false;
                }

                int currAdjSum = nums[curr] + nums[next[curr]];
                if (currAdjSum < targetAdjSum) {
                    target = curr;
                    targetAdjSum = currAdjSum;
                }
                curr = next[curr];
            }

            if (isAscending) {
                break;
            }

            count++;
            next[target] = next[next[target]];
            nums[target] = targetAdjSum;
        }

        return count;
    }
};
