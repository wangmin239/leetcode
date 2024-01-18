class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL); // 豆子总数
        long long res = total; // 最少需要移除的豆子数
        for (int i = 0; i < n; i++) {
            res = min(res, total - (long long)beans[i] * (n - i));
        }
        return res;
    }
};
。