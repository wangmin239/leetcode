/* Original Solution 1 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> sameNums;
        int n = nums.size();
        const int leastN = 3;
        int minDiff = INT_MAX;


        for (int i = 0; i < n; i++) {
            sameNums[nums[i]].push_back(i);
        }

        for (const auto& [_, indexs] : sameNums) {
            if (indexs.size() < leastN) {
                continue;
            }
            const int offset = 2;
            int size = indexs.size();

            for (int i = offset; i < size; i++) {
                minDiff = min(minDiff, (indexs[i] - indexs[i - offset]) << 1);
            }
        }

        return minDiff == INT_MAX ? -1 : minDiff;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n, -1);
        std::unordered_map<int, int> occur;
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.count(nums[i])) {
                next[i] = occur[nums[i]];
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = std::min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(n + 1, -n);
        vector<int> last2(n + 1, -n); // i-(-n) >= n，不会把 ans 变小

        int ans = n;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            ans = min(ans, i - last2[x]);
            last2[x] = last[x];
            last[x] = i;
        }

        return ans == n ? -1 : ans * 2;
    }
};
