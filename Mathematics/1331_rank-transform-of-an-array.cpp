/* Original Solution 1 */
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> backup(arr);
        unordered_map<int, int> numIds;
        vector<int> rank(n);

        sort(backup.begin(), backup.end());



        for (int i = 0, j = 1; i < n; i++) {
            if (numIds.count(backup[i]) == 0) {
                numIds[backup[i]] = j++;
            }
        }

        for (int i = 0; i < n; i++) {
            rank[i] = numIds[arr[i]];
        }

        return rank;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> ranks;
        vector<int> ans(arr.size());
        for (auto &a : sortedArr) {
            if (!ranks.count(a)) {
                ranks[a] = ranks.size() + 1;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};
