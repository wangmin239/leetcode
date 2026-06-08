/* Original Solution 1 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> sortArr(n, pivot);

        for (int i = 0, left = 0, right = n - 1; i < n; i++) {
            if (nums[i] < pivot) {
                sortArr[left++] = nums[i];
            }

            if (nums[n - 1 - i] > pivot) {
                sortArr[right--] = nums[n - 1 - i];
            }
        }

        return sortArr;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                ans[left] = nums[i];
                ++left;
            }
            else if (nums[i] > pivot) {
                ans[right] = nums[i];
                --right;
            }
        }
        reverse(ans.begin() + right + 1, ans.end());
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a, b, c;
        for (int x : nums) {
            if (x < pivot) {
                a.push_back(x);
            } else if (x == pivot) {
                b.push_back(x);
            } else {
                c.push_back(x);
            }
        }

        a.insert(a.end(), b.begin(), b.end());
        a.insert(a.end(), c.begin(), c.end());
        return a;
    }
};
