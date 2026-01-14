/* Original Solution 1 */
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n);
        unordered_map<int, int> lakes;
        
        for (int i = 0; i < n; i++) {
            int lakeId = rains[i];
            
            if (lakeId != 0) {
                ans[i] = -1;
                if (lakes.count(lakeId) != 0) {
                    int prev = lakes[lakeId];
                    bool isValid = false;
                    
                    for (int j = prev + 1; j < i; j++) {
                        if (ans[j] == -2) {
                            ans[j] = lakeId;
                            isValid = true;
                            break;
                        }
                    }
                    
                    if (isValid == false) {
                        return {};
                    }
                }
                lakes[lakeId] = i;
            } else {
                ans[i] = -2;
            }
        }
        
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (rains[i] != 0) {
                id = rains[i];
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (ans[i] == -2) {
                ans[i] = id;
            }
        }
        return ans;
    }
};


/* Official Solution 1*/
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