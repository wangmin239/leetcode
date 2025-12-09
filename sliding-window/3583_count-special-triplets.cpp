/* Original Solution 1 */
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> indexes;
        int n = nums.size();
        constexpr int mod = 1e9 + 7;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            indexes[nums[i]].push_back(i);
        }

        for (const auto& [key, vec] : indexes) {
            int doubleKey = 2 * key;

            if (indexes.count(doubleKey) == 0) {
                continue;
            }

            if (key == 0) {
                int len = indexes[key].size();
                while (len > 2) {
                    cnt += 1LL * (len - 1) * (len - 2) / 2 % mod;
                    cnt %= mod;
                    --len;
                }
                continue;
            }

            auto&& doubleVec = indexes[doubleKey];
            int len = vec.size();
            int doubleLen = doubleVec.size();
            int preSum = 0;
            for (int i = 0, j = 0; i < doubleLen && j < len;) {
                if (doubleVec[i] < vec[j]) {
                    ++preSum;
                    i++;
                } else {
                    int suffixSum = doubleLen - i;
                    int midSum = 0;
                    while (j < len && vec[j] < doubleVec[i]) {
                        ++midSum;
                        ++j;
                    }
                    cnt += 1LL * preSum * midSum * suffixSum % mod;
                    cnt %= mod; 
                }
            }
        }

        return cnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        unordered_map<int, int> suf;
        for (int x : nums) {
            suf[x]++;
        }

        long long ans = 0;
        unordered_map<int, int> pre;
        for (int x : nums) { // x = nums[j]
            suf[x]--; // 撤销
            // 现在 pre 中的是 [0,j-1]，suf 中的是 [j+1,n-1]
            ans += 1LL * pre[x * 2] * suf[x * 2];
            pre[x]++;
        }
        return ans % MOD;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        unordered_map<int, int> cnt1;
        unordered_map<int, long long> cnt12;
        long long cnt123 = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                cnt123 += cnt12[x / 2]; // 把 x 当作 nums[k]
            }
            cnt12[x] += cnt1[x * 2]; // 把 x 当作 nums[j]
            cnt1[x]++; // 把 x 当作 nums[i]
        }
        return cnt123 % MOD;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        numCnt.reserve(nums.size() * 2);
        numPartialCnt.reserve(nums.size() * 2);

        for (int v : nums) {
            numCnt[v]++;
        }

        int ans = 0;
        for (int v : nums) {
            int target = v * 2;
            int lCnt = numPartialCnt[target];
            numPartialCnt[v]++;
            int rCnt = numCnt[target] - numPartialCnt[target];
            ans = (ans + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }

        return ans;
    }
};

/* Official Solution 4 */
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> pos;
        pos.reserve(nums.size() * 2);

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        for (int i = 1; i < nums.size() - 1; i++) {
            int target = nums[i] * 2LL;
            if (pos.count(target) == 0) {
                continue;
            }

            const auto& arr = pos[target];
            if (arr.size() <= 1 || arr[0] >= i) {
                continue;
            }

            auto split = upper_bound(arr.begin(), arr.end(), i);
            int l = split - arr.begin();
            int r = arr.size() - l;

            if (nums[i] == 0) {
                l--;
            }
            ans = (ans + l * 1LL * r % MOD) % MOD;
        }

        return ans;
    }
};
