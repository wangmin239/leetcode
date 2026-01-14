class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        int n = nums.size(), cnt[n * 2];
        fill_n(cnt, 2 * n, 0);
        cnt[n] = 1;
        for (int i = pos - 1, x = n; i >= 0; --i) { // 从 pos-1 开始累加 x
            x += nums[i] < k ? 1 : -1;
            ++cnt[x];
        }

        int ans = cnt[n] + cnt[n - 1];
        for (int i = pos + 1, x = n; i < n; ++i) { // 从 pos+1 开始累加 x
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
};

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        int n = nums.size(), cnt[n * 2];
        fill(cnt, 2 * n, 0);
        cnt[n] = 1;
        for (int i = pos - 1, x = n; i >= 0; --i) { // 从 pos-1 开始累加 x
            x += nums[i] < k ? 1 : -1;
            ++cnt[x];
        }

        int ans = cnt[n] + cnt[n - 1];
        for (int i = pos + 1, x = n; i < n; ++i) { // 从 pos+1 开始累加 x
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
};


class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        int n = nums.size(), cnt[n * 2];
        memset(cnt, 0, sizeof(cnt));
        cnt[n] = 1;
        for (int i = pos - 1, x = n; i >= 0; --i) { // 从 pos-1 开始累加 x
            x += nums[i] < k ? 1 : -1;
            ++cnt[x];
        }

        int ans = cnt[n] + cnt[n - 1];
        for (int i = pos + 1, x = n; i < n; ++i) { // 从 pos+1 开始累加 x
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
};





class Solution {
public:
    inline int sign(int num) {
        if (num == 0) {
            return 0;
        }
        return num > 0 ? 1 : -1;
    }

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int kIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                kIndex = i;
                break;
            }
        }
        int ans = 0;
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sign(nums[i] - k);
            if (i < kIndex) {
                counts[sum]++;
            } else {
                int prev0 = counts[sum];
                int prev1 = counts[sum - 1];
                ans += prev0 + prev1;
            }
        }
        return ans;
    }
};
