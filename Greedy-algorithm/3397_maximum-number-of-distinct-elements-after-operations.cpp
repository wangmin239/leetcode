/* Original Solution 1 */
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int start = nums.front() - k;
        
        for (int i = 0; i < n; i++) {
            if (start - nums[i] > k) {
                continue;
            }
            
            if (nums[i] - start > k) {
                start = nums[i] - k;
            }
            ++cnt;
            ++start;
        }

        
        return cnt;;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int, int>  digitCnt;
        int n = nums.size();

        if (k * 2 + 1 >= n) {
            return n;
        }
        
        for (int i = 0; i < n; i++) {
            ++digitCnt[nums[i]];
        }
        
        int prev = INT_MIN;
        int maxCnt = 0;
        
        for (auto [num, cnt] : digitCnt) {
            int left = num - k;
            int right = num + k;
            
            left = max(left, prev + 1)
            right = min(right, left + cnt - 1);            

            if (prev > right) {
                continue;
            }


            
            maxCnt += right - left + 1;
            prev = right;
        }
        return maxCnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k * 2 + 1 >= n) {
            return n;
        }

        ranges::sort(nums);
        int ans = 0;
        int pre = INT_MIN; // 记录每个人左边的人的位置
        for (int x : nums) {
            x = clamp(pre + 1, x - k, x + k); // min(max(x - k, pre + 1), x + k)
            if (x > pre) {
                ans++;
                pre = x;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for (int num : nums) {
            int curr = min(max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};
