class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = 3000, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        for (int &x : fronts) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        for (int &x : backs) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        return res % 3000;
    }
};


class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int> ans;
        
        for (size_t cnt = 0; cnt < fronts.size(); cnt++) {
            unordered_map<int, int> numMap;
            for (size_t index = 0; index < fronts.size(); index++) {
                if (index == cnt) {
                    ++numMap[backs[index]];
                } else {
                    ++numMap[fronts[index]];
                }
            }
            
            /* get the unique number by comparing to the fronts */
            for (size_t i = 0; i < backs.size(); i++) {
                int frontNum, backNum;
                
                if (i == cnt) {
                    frontNum = backs[i];
                    backNum = fronts[i];
                } else {
                    frontNum = fronts[i];
                    backNum = backs[i];
                }
                --numMap[frontNum];
                
                if (numMap.count(backNum) == 0) {
                    ans.push_back(backNum);
                }
            }
        }
        if (ans.size() == 0) {
            return 0;
        }
        return *min_element(ans.begin(), ans.end());
    }
};