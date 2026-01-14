/* Original Solution 1 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        int left = 0, right = 1;

        sort(nums.begin(), nums.end());
        for (int len = nums.size(); right < len; right++) {
            while (nums[right] - nums[left] > 1 && left < right) {
                ++left;
            }
            if (nums[right] - nums[left] == 1) {
                ans = max(ans, right - left + 1);
            }
        }
        
        return ans;
    }
};




/* Original Solution 2 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> digits;
        
        for (int num : nums) {
            ++digits[num];
        }
        
        for (auto [num, cnt] : digits) {
            if (digits.count(num + 1) > 0) {
                ans = max(cnt + digits[num + 1], ans);
            }
        }
        
        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int begin = 0;
        int res = 0;
        for (int end = 0; end < nums.size(); end++) {
            while (nums[end] - nums[begin] > 1) {
                begin++;
            }
            if (nums[end] - nums[begin] == 1) {
                res = max(res, end - begin + 1);
            }
        }
        return res;
    }
};

/* Official Solution 2 */
class Solution {
    public int findLHS(int[] nums) {
        HashMap <Integer, Integer> cnt = new HashMap <>();
        int res = 0;
        for (int num : nums) {
            cnt.put(num, cnt.getOrDefault(num, 0) + 1);
        }
        for (int key : cnt.keySet()) {
            if (cnt.containsKey(key + 1)) {
                res = Math.max(res, cnt.get(key) + cnt.get(key + 1));
            }
        }
        return res;
    }
}
