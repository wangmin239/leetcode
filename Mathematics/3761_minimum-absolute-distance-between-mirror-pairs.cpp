/* Original Solution 1 */
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto reverse = [](int value) {
            int num = 0;
            const int decimal = 10;
            while (value) {
                int mod = value % decimal;
                value /= decimal;
                num *= decimal;
                num += mod;
            }
            return num;
        };

        unordered_map<int, int> reverseNumPos;
        int n = nums.size();
        int distance = n;

        for (int i = 0; i < n; i++) {
            int reverseNum = reverse(nums[i]);

            if (reverseNumPos.count(nums[i]) != 0) {
                distance = min(distance, i - reverseNumPos[nums[i]]);
            }

            reverseNumPos[reverseNum] = i;
        }

        return distance == n ? -1 : distance;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto reverseNum = [](int x) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y;
        };

        int n = nums.size();
        unordered_map<int, int> prev;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (prev.count(x)) {
                ans = min(ans, i - prev[x]);
            }
            prev[reverseNum(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> last_index;
        int n = nums.size(), ans = n;

        for (int j = 0; j < n; j++) {
            int x = nums[j];
            auto it = last_index.find(x);
            if (it != last_index.end()) {
                ans = min(ans, j - it->second);
            }

            // 计算 reverse(x)，不用字符串
            int rev = 0;
            for (; x > 0; x /= 10) {
                rev = rev * 10 + x % 10;
            }
            last_index[rev] = j;
        }

        return ans < n ? ans : -1;
    }
};
