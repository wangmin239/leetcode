/* Original Solution */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        
        for (int left = 0, right = 0; right < n; right++) {
            if (nums[right] == maxNum) {
                ++cnt;
            }
            
            if (cnt < k) {
                continue;
            }
            /* calculate the range of the first not equal maxNum to  equal maxNum */
            int preLeft = left;
            while (cnt == k) {
                if (nums[left] == maxNum) {
                    --cnt;
                }
                ++left;
            }
            
            ans += 1LL * (left - preLeft) * (n - right);
        }
        
        return ans;
    }
};

/* Official Solution */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> pos{-1};
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                pos.push_back(i);
            }
        }
        int left = 1, right = k;
        long long ans = 0;
        while (right < pos.size()) {
            ans += (pos[left] - pos[left - 1]) * (n - pos[right]);
            left++, right++;
        }
        return ans;
    }
};
