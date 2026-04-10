/* Original Solution 1 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> numIds;
        int len = nums.size();
        int ans = INT_MAX;
        const int minEleCnt = 3;
        auto getMinDiff = [](const vector<int>& ids) {
             int diff = INT_MAX;
             int size = ids.size();

             for (int left = 0, right = 2; right < size; left++, right++) {
                 diff = min(diff, (ids[right] - ids[left]) << 1);
             }
             return diff;
        };

        for (int i = 0; i < len; i++) {
            numIds[nums[i]].push_back(i);
        }

        for (const auto& [_, ids] : numIds) {
            if (ids.size() < minEleCnt) {
                continue;
            }
            ans = min(ans, getMinDiff(ids));
        }

        return ans == INT_MAX ? -1: ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] != nums[j]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] == nums[k]) {
                        ans = std::min(ans, k - i);
                        break;
                    }
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};
