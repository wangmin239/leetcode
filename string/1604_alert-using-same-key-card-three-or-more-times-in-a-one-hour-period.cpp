class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> timeMap;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            string name = keyName[i];
            string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        vector<string> res;
        for (auto &[name, list] : timeMap) {
            sort(list.begin(), list.end());
            int size = list.size();
            for (int i = 2; i < size; i++) {
                int time1 = list[i - 2], time2 = list[i];
                int difference = time2 - time1;
                if (difference <= 60) {
                    res.emplace_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};



class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> persons;
        vector<string> ans;
        for (int i = 0; i < keyName.size(); i++) {
            int minutes = convertTime(keyTime[i]);
            persons[keyName[i]].push_back(minutes);
        }

        for (auto& [name, minuVec] : persons) {
            if (isWarning(name, minuVec) == true) {
                ans.push_back(name);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    int convertTime(const string& time) {
        int hour = stoi(time.substr(0, 2));
        int minus = stoi(time.substr(3));
        
        return hour * 60 + minus;
    }
    
    bool isWarning(const string& name, vector<int>& minuVec) {
        const int oneHour = 60;

        sort(minuVec.begin(), minuVec.end());
        for (int turn = 0; turn < minuVec.size() - 2; turn++) {
            int cnt = 0;
            int start = minuVec[turn];
            for (int i = turn + 1; i < minuVec.size(); i++) {              
                if (minuVec[i] - start > oneHour) {
                    break;
                }
                cnt++;
                /* over three times to trigger one warning */
                if (cnt == 2) {
                    return true;
                }
            }
        }
        return false;
        
    }
};