class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (true) {
            sort(arr.begin(), arr.end(), [](const pair<int, char> & p1, const pair<int, char> & p2) {
                return p1.first > p2.first;
            });
            bool hasNext = false;
            for (auto & [freq, ch] : arr) {
                int m = res.size();
                if (freq <= 0) {
                    break;
                }
                if (m >= 2 && res[m - 2] == ch && res[m - 1] == ch) {
                    continue;
                }
                hasNext = true;
                res.push_back(ch);
                freq--;
                break;
            }
            if (!hasNext) {
                break;
            }
        }
      
        return res;
    }
};





class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> chVec {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        auto cmp = [] (const auto& lhs, const auto& rhs) {
            return lhs.first > rhs.first;
        };
        
        sort(chVec.begin(), chVec.end(), cmp);
        string ans;
        buildStr(chVec[0], chVec[1], ans);
        
        string str;
        if (chVec[1].first == 0) {
            sort(chVec.begin(), chVec.end(), cmp);
            buildStr(chVec[0], chVec[1], ans);
        } else {
            sort(chVec.begin(), chVec.end(), cmp);
            buildStr(chVec[0], chVec[1], str);
        }
            
        ans = str + ans;
        sort(chVec.begin(), chVec.end(), cmp);
        
        if (chVec.front().first > 0) {
            if (ans.back() == chVec.front().second) {
                ans.push_back(chVec.front().second);
                chVec.front().first -= 1;
            } else {
                ans.append(min(2, chVec.front().first), chVec.front().second);
                chVec.front().first -= min(2, chVec.front().first);
            }
        }
        
        if (chVec.front().first > 0) {
            if (ans.front() != chVec.front().second) {
                ans.insert(0, min(2, chVec.front().first), chVec.front().second);
            }
        }
        
        return ans;
    }
    
    void buildStr(pair<int, char>& great, pair<int, char>& less, string& ans) {
        
        while (great.first > 0 && less.first > 0) {
            bool flag = false;
            
            if (great.first >= less.first * 2) {
                flag = true;
            }
            
            if (great.first > 1) {
                great.first -= 2;
                ans.append(2, great.second);
            } else {
                great.first -= 1;
                ans.push_back(great.second);
            }
            
            if (flag == true) {
                less.first -= 1;
                ans.push_back(less.second);
                continue;
            }
            
            if (less.first > 1) {
                less.first -= 2;
                ans.append(2, less.second);
            } else {
                less.first -= 1;
                ans.push_back(less.second);
            }
        }
    }
};