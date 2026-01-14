class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
        });
        sort(potions.begin(), potions.end(), [](int a, int b) {
            return a > b;
        });
        for (int i = 0, j = 0; i < spells.size(); ++i) {
            int p = idx[i];
            int v = spells[p];
            while (j < potions.size() && (long long) potions[j] * v >= success) {
                ++j;
            }
            res[p] = j;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto& i : spells) {
            long long t = (success + i - 1) / i - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};



class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans(n, 0);

        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < n; i++) {
            long long mul = (success + spells[i] - 1) / spells[i];
            auto iter = lower_bound(potions.begin(), potions.end(), mul);
            ans[i] = potions.end() - iter;
        }
        return ans;
    }
};