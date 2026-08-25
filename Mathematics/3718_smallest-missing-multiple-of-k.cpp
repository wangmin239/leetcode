/* Original Solution 1 */
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        const int upLimit = 100;
        vector<int> multiple(upLimit, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] % k == 0) {
                multiple[nums[i] / k - 1] = 1;
            }
        }

        for (int i = 0; i < upLimit; i++) {
            if (multiple[i] == 0) {
                return (i + 1) * k;
            }
        }

        return (upLimit + 1) * k;
    }
};



/* Original Solution 2 */
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int multiple = 1;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] % k == 0) {
                int id = nums[i] / k;

                if (id < multiple) {
                    continue;
                }

                if (id != multiple) {
                    break;
                }
                ++multiple;
            }
        }

        return multiple * k;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int ans = k;
        while (seen.count(ans)) {
            ans += k;
        }
        return ans;
    }
};
