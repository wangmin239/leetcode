/* Official Solution 1 */
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur;
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            for (int x : cur) {
                next.insert(x | num);
            }
            cur = next;
#ifdef __cpp_lib_containers_ranges
            res.insert_range(cur);
#else
            res.insert(cur.begin(), cur.end());
#endif
        }
        return res.size();
    }
};

