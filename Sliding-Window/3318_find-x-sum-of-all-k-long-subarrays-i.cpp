/* Original Solution 1 */

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        const int maxVal = 50;
        int index = 0;
        vector<int> numFreq(maxVal + 1);
        vector<int> ids(maxVal + 1);
        auto comp = [&numFreq](int lhs, int rhs) {
            if (numFreq[lhs] > numFreq[rhs]) {
                return true;
            }

            if (numFreq[lhs] == numFreq[rhs]) {
                return lhs > rhs;
            }
            return false;
        };

        iota(ids.begin(), ids.end(), 0);

        for (int left = 0, right = 0; right < n; right++) {
            ++numFreq[nums[right]];
            if (right - left == k - 1) {
               sort(ids.begin(), ids.end(), comp);
               for (int i = 0; i < x; i++) {
                   ans[index] += numFreq[ids[i]] * ids[i];
               }
               index++;
                --numFreq[nums[left++]];
            }
        }

        return ans;
    }
};



