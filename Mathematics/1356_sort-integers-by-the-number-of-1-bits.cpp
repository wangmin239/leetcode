/* Original Solution 1 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        const int maxBitCnt = 14;
        vector<vector<int>> binGroups(maxBitCnt);

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            int id = popcount(static_cast<unsigned int>(arr[i]));
            binGroups[id].push_back(arr[i]);
        }

        vector<int> ans;
        for (int id = 0; id < maxBitCnt; id++) {
            for (int i = 0; i < binGroups[id].size(); i++) {
                ans.push_back(binGroups[id][i]);
            } 
        }

        return ans;

    }
};


/* Original Solution 2 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> bitPairs(n);

        for (int i = 0; i < n; i++) {
            bitPairs[i] = make_pair(arr[i], popcount(static_cast<unsigned int>(arr[i])));
        }

        sort(bitPairs.begin(), bitPairs.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second < rhs.second;
        });

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = bitPairs[i].first;
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1; i <= 10000; ++i) {
            bit[i] = bit[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};
