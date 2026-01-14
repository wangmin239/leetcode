/* Official Solution 1 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                ans += k - j;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; i++) {
            int k = i + 2;

            for (int j = i + 1; j < len - 1; j++) {
                while (k < len && nums[k] < nums[i] + nums[j]) {
                    ++k;
                }

                sum += max(k - j - 1, 0);

            }
        }


        return sum;
    }
};


/* Original Solution  1 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        map<int, int> digits;
        vector<int> lenVec;
        int sum = 0;
        int len;

        for (int num : nums) {
            ++digits[num];
        }

        /* equilateral triangle */
        for (const auto& [aLen, cnt] : digits) {
            if (cnt > 2 && aLen != 0) {
                sum += cnt * (cnt - 1) * (cnt - 2) / 6;
            }
            if (aLen != 0) {
                lenVec.push_back(aLen);
            }
        }

        len = lenVec.size();
        /* isosceles triangle */
        for (int ia = 0, ib = 1, cnt = 0; ia < len; ia++) {
            while (ib < len && lenVec[ia] * 2 > lenVec[ib]) {
                cnt += digits[lenVec[ib]];
                ++ib;
            }

            sum += digits[lenVec[ia]] * (digits[lenVec[ia]] - 1) * cnt / 2;
            cnt += digits[lenVec[ia]];

            if (ia + 1 < len) {
                cnt -= digits[lenVec[ia + 1]];
            }
        }

        for (int ia = 0; ia < len - 2; ia++) {
            int ic = ia + 2;
            int cnt = 0;

            for (int ib = ia + 1; ib < len - 1; ib++) {
                while (ic < len && lenVec[ic] < lenVec[ia] + lenVec[ib]) {
                    if (ic > ib) {
                        cnt += digits[lenVec[ic]];
                    }
                    ++ic;
                }

                if (ic > ib + 1) {
                    sum += digits[lenVec[ia]] * digits[lenVec[ib]] * cnt;
                    cnt -= digits[lenVec[ib + 1]];
                }
            }
        }

        return sum;
    }
};