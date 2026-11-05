/* Original Solution 1 */
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;

        sort(arr2.begin(), arr2.end());

        for (int val : arr1) {
            auto iter = lower_bound(arr2.begin(), arr2.end(), val);
            /* All elements in the ascending sequence are less than the given value. */
            if (iter == arr2.end()) {
                if (arr2.back() < val - d) {
                    ++cnt;
                }
                continue;
            }
            /* At least one element is equal to the given value. */
            if (*iter == val) {
                continue;
            }

            if (*iter > val + d) {
                if (iter == arr2.begin() || iter != arr2.begin() && *(iter - 1) < val - d) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};



/* Original Solution 1 */
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        int n = arr2.size();
        int i;

        for (int val : arr1) {
            for (i = 0; i < n; i++) {
                if (arr2[i] >= val - d && arr2[i] <= val + d) {
                    break;
                }
            }
            cnt += static_cast<int>(i == n);
        }

        return cnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (auto &x: arr1) {
            bool ok = true;
            for (auto &y: arr2) {
                ok &= (abs(x - y) > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto &x: arr1) {
            unsigned p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size()) {
                ok &= (arr2[p] - x > d);
            }
            if (p - 1 >= 0 && p - 1 <= arr2.size()) {
                ok &= (x - arr2[p - 1] > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
