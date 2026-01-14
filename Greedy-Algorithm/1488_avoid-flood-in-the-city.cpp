class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> zeroDays;
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> lakes;

        /* check if flood possibly occurr */
        for (int i = 0; i < n; i++) {
            int lakeId = rains[i];
            if (lakeId == 0) {
                zeroDays.insert(i);
                continue;
            }
            ans[i] = -1;
            if (lakes.count(lakeId)) {              
                auto iter = zeroDays.lower_bound(lakes[lakeId]);
                if (iter == zeroDays.end()) {
                    return {};
                }
                ans[*iter] = lakeId;
                zeroDays.erase(*iter);
            }
            lakes[lakeId] = i;
        }
        return ans;
    }
};