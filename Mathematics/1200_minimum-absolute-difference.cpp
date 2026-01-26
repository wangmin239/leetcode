/* Original Solution 1 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int minDiff = INT_MAX;
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];

            if (diff > minDiff) {
                continue;
            }

            if (diff < minDiff) {
                ans.clear();
                minDiff = diff;
            }
            ans.push_back({arr[i - 1], arr[i]});
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int best = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; ++i) {
            if (int delta = arr[i + 1] - arr[i]; delta < best) {
                best = delta;
                ans = {{arr[i], arr[i + 1]}};
            }
            else if (delta == best) {
                ans.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};

