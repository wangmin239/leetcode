                                                         ^
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        unique_ptr<pair<int, int>[]> valsLabPtr(new pair<int, int> [n]);
        pair<int, int>  valsLab[n] = valsLabPtr.get();
        
        for (int i = 0; i < n; i++) {
            valsLab[i] = make_pair(values[i], labels[i]);
        }
        
        sort(valsLab, valsLab + n, [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;});
        
        int sum = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (numWanted <= 0) {
                break;
            }
            if (cnt[valsLab[i].second] >= useLimit) {
                continue;
            }
            --numWanted;
            sum += valsLab[i].first;
            ++cnt[valsLab[i].second];
        }
        return sum;
    }
};


class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return values[i] > values[j];
        });

        int ans = 0, choose = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n && choose < numWanted; ++i) {
            int label = labels[id[i]];
            if (cnt[label] == useLimit) {
                continue;
            }
            ++choose;
            ans += values[id[i]];
            ++cnt[label];
        }
        return ans;
    }
};


                                                            ^
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> valsLab(n);
        
        for (int i = 0; i < n; i++) {
            valsLab[i] = make_pair(values[i], labels[i]);
        }
        
        sort(valsLab.begin(), valsLab.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;});
        
        int sum = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (numWanted <= 0) {
                break;
            }
            if (cnt[valsLab[i].second] >= useLimit) {
                continue;
            }
            --numWanted;
            sum += valsLab[i].first;
            ++cnt[valsLab[i].second];
        }
        return sum;
    }
};