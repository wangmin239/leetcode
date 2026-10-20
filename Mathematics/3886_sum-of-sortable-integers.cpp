/* Official Solution 1 */

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        auto getElement = [](int value) {
            vector<int> elements;

            for (int i = 1; i * i <= value; i++) {
                if (value % i == 0) {
                    int divisor = value / i;
                    elements.push_back(i);
                    if (divisor != i) {
                        elements.push_back(divisor);
                    }
                }
            }

            return elements;
        };

        vector<int> copyNums(nums);
        auto isEqual = [](vector<int>& fullNums, vector<int>& partNums, int offset, int len) {
            for (int i = 0; i < len; i++) {
                if (fullNums[offset + i] != partNums[i]) {
                    return false;
                }
            }
            return true;
        };

        auto isNonDec = [](vector<int>& partNums, int len) {
            int minId = min_element(partNums.begin(), partNums.end()) - partNums.begin();
            int i = minId + 1;

            /* non decresing order*/
            while (i < len) {
                if (partNums[i - 1] > partNums[i]) {
                    break;
                }
                i++;
            }


            if (i == len) {
                while (i <  len + minId) {
                    if (partNums[(i - 1) % len ] > partNums[i % len]) {
                        return false;
                    }
                    i++;
                }
                return true;
            }

            while (i < len + minId) {
                if (partNums[i % len] != partNums[minId]) {
                    return false;
                }
                i++;
            }

            return true;

        };

        sort(copyNums.begin(), copyNums.end());

        auto check = [&](int k) {
            
            
            for (int i = 0; i < n; i += k) {

                vector<int> partCopy(k);
                for (int j = 0; j < k; j++) {
                    partCopy[j] = nums[i + j];
                }

                if (isNonDec(partCopy, k) == false) {
                    return false;
                }

                sort(partCopy.begin(), partCopy.end());

                if (isEqual(copyNums, partCopy, i, k) != true) {
                    return false;
                }

            }

            return true;
        };

        int sum = 0;
        auto elements = getElement(n);
        for (int k : elements) {
            if (check(k) == true) {
                sum += k;
            }
        }

        return sum;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);
                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        ranges::sort(target);

        auto kmp = [](const vector<int>& nums1, const vector<int>& nums2) {
            int n = nums1.size(), m = nums2.size();
            vector<int> pi(m, 0);
            int j = 0;

            for (int i = 1; i < m; ++i) {
                while (j > 0 && nums2[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums2[i] == nums2[j]) {
                    ++j;
                }
                pi[i] = j;
            }

            j = 0;
            for (int i = 0; i < n; ++i) {
                while (j > 0 && nums1[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums1[i] == nums2[j]) {
                    ++j;
                }
                if (j == m) {
                    return true;
                }
            }
            return false;
        };

        auto check = [&](const vector<int>& nums1, const vector<int>& nums2) {
            // 检查能否通过对 nums1 进行若干次循环移动操作得到 nums2
            vector<int> doubled = nums1;
            doubled.insert(doubled.end(), nums1.begin(), nums1.end());
            return kmp(doubled, nums2);
        };

        int ans = 0;

        for (int d : fac) {
            bool allGood = true;
            for (int left = 0; left < n; left += d) {
                int right = left + d - 1;
                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left, target.begin() + right + 1);

                if (!check(sub1, sub2)) {
                    allGood = false;
                    break;
                }
            }
            if (allGood) {
                ans += d;
            }
        }

        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);
                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        ranges::sort(target);

        // 检查能否通过对 nums1 进行若干次循环移动操作得到 nums2
        auto check = [](const vector<int>& nums1, const vector<int>& nums2) {
            int L = nums1.size();

            for (int i = 0; i < L - 1; ++i) {
                if (nums1[i] > nums1[i + 1]) {
                    vector<int> rotated;
                    rotated.insert(rotated.end(), nums1.begin() + i + 1, nums1.end());
                    rotated.insert(rotated.end(), nums1.begin(), nums1.begin() + i + 1);
                    return rotated == nums2;
                }
            }

            return nums1 == nums2;
        };

        int ans = 0;

        for (int d : fac) {
            bool allGood = true;
            for (int left = 0; left < n; left += d) {
                int right = left + d - 1;

                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left, target.begin() + right + 1);

                if (!check(sub1, sub2)) {
                    allGood = false;
                    break;
                }
            }
            if (allGood) {
                ans += d;
            }
        }

        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> ks, v = nums;
        sort(v.begin(), v.end());
        for(int i = 1; i <= n; ++i) if(!(n % i)) ks.push_back(i);
        for(auto k : ks){
            bool b = 1;
            short cnt = 0;
            for(int i = 0; b && (i * k != n) && cnt < 2; ++i){
                cnt = 0;
                for(int j = 0; b && (j != k) && cnt < 2; ++j){
                    if(nums[i * k + j] > v[i * k + k - 1] || nums[i * k + j] < v[i * k]) b = 0;
                    if(i * k + j != 0 && nums[i * k + j] < nums[i * k + j - 1]) ++cnt;
                    if(cnt == 1 && nums[i * k + j] > nums[i * k]) b = 0;
                }
            }
            if(b && cnt < 2) ans += k;
        }
        return ans;
    }
};


/* Official Solution 4 */
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_dec(n); // nums[next_dec[i]] > nums[next_dec[i] + 1]
        next_dec[n - 1] = n;
        int p = n;
        // 对于每个 i，记录下一个递减的位置
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                p = i;
            }
            next_dec[i] = p;
        }

        int ans = 0;

        auto solve = [&](int k) -> void {
            int last_max = 0; // 上一段的最大值
            for (int r = k - 1; r < n; r += k) {
                int l = r - k + 1;
                int m = next_dec[l];
                if (m >= r) {
                    // [l, r] 是递增的，最小值为 nums[l]，最大值为 nums[r]
                    // 最小值必须 >= 上一段的最大值
                    if (nums[l] < last_max) {
                        return;
                    }
                    last_max = nums[r];
                } else {
                    // [l, m] 是第一段，[m+1, r] 是第二段
                    // 第二段必须是递增的，且第二段的最小值必须 >= 上一段的最大值，且第二段的最大值必须 <= 第一段的最小值
                    if (next_dec[m + 1] < r || nums[m + 1] < last_max || nums[r] > nums[l]) {
                        return;
                    }
                    last_max = nums[m];
                }
            }
            ans += k; // 满足要求
        };

        // 枚举 n 的因子 k
        for (int k = 1; k * k <= n; k++) {
            if (n % k == 0) {
                solve(k);
                if (k * k < n) {
                    solve(n / k);
                }
            }
        }

        return ans;
    }
};
