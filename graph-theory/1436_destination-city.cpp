class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_set<string> citiesA;
        for (auto &path : paths) {
            citiesA.insert(path[0]);
        }
        for (auto &path : paths) {
            if (!citiesA.count(path[1])) {
                return path[1];
            }
        }
        return "";
    }
};



class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> outDegree;
        
        for (const auto& path : paths) {
            outDegree.insert(path.front());
        }
        
        for (const auto& path : paths) {
            if (outDegree.count(path.back()) == 0) {
                return path.back();
            }
        }
        
        return "";
    }
};





class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outDegree;
        
        for (const auto& path : paths) {
            ++outDegree[path.front()];
            if (outDegree.count(path.back()) == 0) {
                outDegree[path.back()] = 0;
            }
        }
        
        string ans;
        for (auto& [place, cnt] : outDegree) {
            if (cnt == 0) {
                ans = move(place);
                break;
            }
        }
        
        return ans;
    }
};