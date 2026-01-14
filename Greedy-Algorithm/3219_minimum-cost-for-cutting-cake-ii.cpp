class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long cost = 0;

        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        
        vector<int>::iterator it[2] = {horizontalCut.begin(), verticalCut.begin()};
        vector<int>::iterator end[2] = {horizontalCut.end(),  verticalCut.end()};
        int cnt[2] = {1, 1};
        
        for (size_t i = 0; i < static_cast<size_t>(m + n - 2); i++) {
            int pos = ranges::max(0, 1, {}, [&](int j) { return it[j] != end[j] ? *it[j] : 0;});
            cost += *it[pos]++  * cnt[!pos];
            ++cnt[pos];
        }
        
        return cost;
    }
};



class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        long long h = 1, v = 1;
        long long res = 0;
        while (!horizontalCut.empty() || !verticalCut.empty()) {
            if (verticalCut.empty() || !horizontalCut.empty() && horizontalCut.back() > verticalCut.back()) {
                res += horizontalCut.back() * h;
                horizontalCut.pop_back();
                v++;
            } else {
                res += verticalCut.back() * v;
                verticalCut.pop_back();
                h++;
            }
        }
        return res;
    }
};
