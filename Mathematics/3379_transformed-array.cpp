/* Original Solution 1 */
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                continue;
            }
            
            int offset = i;
            if (nums[i] > 0) {
                offset = (offset + nums[i]) % n;
            } else {
                offset = offset + nums[i] % n >= 0 ? offset + nums[i] % n : n + offset + nums[i]% n;
            }
            result[i] = nums[offset];
        }

        return result;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return res;
    }
};
