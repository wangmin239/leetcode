class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto &kd : knowledge) {
            dict[kd[0]] = kd[1];
        }
        bool addKey = false;
        string key, res;
        for (char c : s) {
            if (c == '(') {
                addKey = true;
            } else if (c == ')') {
                if (dict.count(key) > 0) {
                    res += dict[key];
                } else {
                    res.push_back('?');
                }
                addKey = false;
                key.clear();
            } else {
                if (addKey) {
                    key.push_back(c);
                } else {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};




class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int len = s.length();
        string ans, key;
        int left = 0;
        int right = 0;
        unordered_map<string, string> knowMap;
        initKnowledge(knowledge, knowMap);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                right = i;
            }

            if (s[i] == ')') {
                ans.append(s.substr(left, right - left));
                left = right + 1;
                key.clear();
                key(s.substr(left, i - left));
                ans.append(getValue(key, knowMap));
                left = i + 1;
            }               
        }
        
        ans.append(s.substr(left, len - left));
        return ans;
    }
    
    void initKnowledge(vector<vector<string>>& knowledge, unordered_map<string, string>& knowMap) {
       for (auto vec : knowledge) {
            knowMap[vec.front()] = vec.back();
       }
    }
    
    string getValue(const string& key, unordered_map<string, string>& knowMap) {
            if (knowMap.count(key) != 0) {
                return knowMap[key];
            }
            return "?";
    }

        
};