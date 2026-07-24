/* Original Solution 1 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> xorSum(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int xorVal = nums[i] ^ nums[j];
                for (int k = j + 1; k < n; k++) {
                    xorSum.insert(xorVal ^ nums[k];
                }
            }
        }

        return xorSum.size();
    }
};


/* Official Solution 1 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 0;
        for (int v : nums) {
            m = max(m, v);
        }
        int u = 1;
        while (u <= m) {
            u <<= 1;
        }
        vector<int> s(u);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s[nums[i] ^ nums[j]] = 1;
            }
        }
        vector<int> t(u);
        for (int x = 0; x < u; x++) {
            if (!s[x]) {
                continue;
            }
            for (int v : nums) {
                t[x ^ v] = 1;
            }
        }
        int ans = 0;
        for (int x = 0; x < u; x++) {
            if (t[x]) {
                ans++;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 0;
        for (int v : nums) {
            m = max(m, v);
        }
        int u = 1;
        while (u <= m) {
            u <<= 1;
        }
        vector<int> one(u), two(u), three(u);
        for (int v : nums) {
            one[v] = 1;
            for (int x = 0; x < u; x++) {
                if (one[x]) {
                    two[x ^ v] = 1;
                }
            }
        }
        for (int v : nums) {
            for (int x = 0; x < u; x++) {
                if (two[x]) {
                    three[x ^ v] = 1;
                }
            }
        }
        int ans = 0;
        for (int x = 0; x < u; x++) {
            if (three[x]) {
                ans++;
            }
        }
        return ans;
    }
};
