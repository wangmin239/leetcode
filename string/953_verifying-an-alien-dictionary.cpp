class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> chMap;
        int i = 0;
        
        for (char ch : order) {
            chMap[ch] = i++;
        }
        
        auto cmp = [&](const auto& lhs, const auto& rhs) {
            int len = min(lhs.length(), rhs.length());
            bool isLess = false;
            
            for (int i = 0; i < len; i++) {
                if (chMap[lhs[i]] == chMap[rhs[i]]) {
                    continue;
                }
                
                if (chMap[lhs[i]] < chMap[rhs[i]]) {
                    return true;
                } else {
                    return false;
                }
            }
            
            return lhs.length() > rhs.length() ? false : true;
        };
        
        int size = words.size();
        
        for (int i = 1; i < size; i++) {
            if (cmp(words[i - 1], words[i]) == false) {
                return false;
            }   
        }
        
        return true;
    }
};




class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int index[26] = {0};
        for (int i = 0; i < order.size(); i++) {
            index[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            bool valid = false;
            for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++) {
                int prev = index[words[i - 1][j] - 'a'];
                int curr = index[words[i][j] - 'a'];
                if (prev < curr) {
                    valid = true;
                    break;
                } else if (prev > curr) {
                    return false;
                }
            }
            if (!valid) {
                /* 比较两个字符串的长度 */
                if (words[i - 1].size() > words[i].size()) {
                    return false;
                }
            }
        }
        return true;
    }
};
