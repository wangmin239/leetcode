  
/* Original Solution 1 */
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        const int kinds = 4;
        vector<vector<string>> classKind(kinds);
        const pair<string, int> busyPair[kinds] = {{"electronics", 0},
                    {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
        auto checkValid = [](const string& code) {
            for (char ch : code) {
                if (isalpha(ch) || isdigit(ch) || ch == '_') {
                    continue;
                }
                return false;
            }
            return true;
        };
        
        for (int i = 0; i < n; i++) {
            if (code[i].empty() == true || isActive[i] == false || checkValid(code[i]) == false) {
                continue;
            }
            
            for (int j = 0; j < kinds; j++) {
                if (businessLine[i] == busyPair[j].first) {
                    int id = busyPair[j].second;
                    classKind[id].push_back(code[i]);
                    break;
                }
            }
        }
        
        vector<string> ans;
        for (auto&& busyness : classKind) {
            if (busyness.empty() == true) {
                continue;
            }
            
            sort(busyness.begin(), busyness.end());
            for (auto&& ele : busyness) {
                ans.push_back(ele);
            }
        }
        
        return ans;
    }
};


/* Official Solution 1 */
unordered_map<string, int> BUSINESS_LINE_TO_CATEGORY = {
    {"electronics", 0},
    {"grocery", 1},
    {"pharmacy", 2},
    {"restaurant", 3},
};

class Solution {
    // 检查字符串是否非空，只包含字母、数字和下划线
    bool is_valid(const string& s) {
        for (char c : s) {
            if (c != '_' && !isalnum(c)) {
                return false;
            }
        }
        return !s.empty();
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> groups[4];
        for (int i = 0; i < code.size(); i++) {
            string& s = code[i];
            auto it = BUSINESS_LINE_TO_CATEGORY.find(businessLine[i]);
            if (it != BUSINESS_LINE_TO_CATEGORY.end() && isActive[i] && is_valid(s)) {
                groups[it->second].push_back(s); // 相同类别的优惠码分到同一组
            }
        }

        vector<string> ans;
        for (auto& g : groups) {
            ranges::sort(g); // 每一组内部排序
            ans.insert(ans.end(), g.begin(), g.end());
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    bool check(string code, bool isActive) {
        for (auto it : code) {
            if (it != '_' && !isalnum(it)) {
                return false;
            }
        }
        return isActive;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<string> groups[4];
        vector<string> ans;
        for (int i = 0; i < code.size(); i++) {
            if (code[i].size() && check(code[i], isActive[i])) {
                if (businessLine[i] == "electronics") {
                    groups[0].push_back(code[i]);
                } else if (businessLine[i] == "grocery") {
                    groups[1].push_back(code[i]);
                } else if (businessLine[i] == "pharmacy") {
                    groups[2].push_back(code[i]);
                } else if (businessLine[i] == "restaurant") {
                    groups[3].push_back(code[i]);
                }
            }
        }
        for (auto& group : groups) {
            sort(group.begin(), group.end());
            ans.insert(ans.end(), group.begin(), group.end());
        }
        return ans;
    }
};
