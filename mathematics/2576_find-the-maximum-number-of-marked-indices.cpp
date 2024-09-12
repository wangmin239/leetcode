class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n / 2;
        auto check = [&](int m) {
            for (int i = 0; i < m; i++) {
                if (nums[i] * 2 > nums[n - m + i]) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            int m = l + r + 1 >> 1;
            if (check(m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l * 2;
    }
};


class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n / 2;
        int res = 0;
        for (int i = 0, j = m; i < m && j < n; i++) {
            while (j < n && 2 * nums[i] > nums[j]) {
                j++;
            }
            if (j < n) {
                res += 2;
                j++;
            }
        }
        return res;
    }
};





class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
     int n = nums.size();
     int ans = 0;

     sort(nums.begin(), nums.end());
     

     int mid = lower_bound(nums.begin(), nums.end(), nums[n - 1] / 2) - nums.begin();
     int half = (n - 1) / 2;
     
     for (int left = mid, right = n -1; left >= 0 && right > half; right--) {
        while (left >= 0 && 2 * nums[left] > nums[right]) {
            --left;
        }
        
        if (left >= 0) {
            ans += 2;
        }
        --left;
         
     }

     return ans;
    }
};