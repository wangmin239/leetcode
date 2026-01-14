class Solution {
    int getMinutes(string &t) {
        return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
    }

public:
    int findMinDifference(vector<string> &timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int t0Minutes = getMinutes(timePoints[0]);
        int preMinutes = t0Minutes;
        for (int i = 1; i < timePoints.size(); ++i) {
            int minutes = getMinutes(timePoints[i]);
            ans = min(ans, minutes - preMinutes); // 相邻时间的时间差
            preMinutes = minutes;
        }
        ans = min(ans, t0Minutes + 1440 - preMinutes); // 首尾时间的时间差
        return ans;
    }
};

class Solution {
    int getMinutes(string &t) {
        return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
    }

public:
    int findMinDifference(vector<string> &timePoints) {
        int n = timePoints.size();
        if (n > 1440) {
            return 0;
        }
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int t0Minutes = getMinutes(timePoints[0]);
        int preMinutes = t0Minutes;
        for (int i = 1; i < n; ++i) {
            int minutes = getMinutes(timePoints[i]);
            ans = min(ans, minutes - preMinutes); // 相邻时间的时间差
            preMinutes = minutes;
        }
        ans = min(ans, t0Minutes + 1440 - preMinutes); // 首尾时间的时间差
        return ans;
    }
};


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int size = timePoints.size();
        int minutesArr[size];
        
        for (int i = 0; i < size; i++) {
            minutesArr[i] = convertMinutes(timePoints[i]);
        }
        
        sort(minutesArr, minutesArr + size);
        int minDiff = INT_MAX;
        
        for (int i = 1; i < size; i++) {
            minDiff = min(minDiff, minutesArr[i] - minutesArr[i - 1]);
        }
        
        minDiff = min(minDiff, 24 * 60 + minutesArr[0] - minutesArr[size - 1]);
        
        
        return minDiff;
        
    }
    
    int convertMinutes(const string& str) {
        auto pos = str.find(":");
        int len  = str.length();
        
        int hours = stoi(str.substr(0, pos));
        int minutes = stoi(str.substr(pos + 1));
        
        return 60 * hours + minutes;
    }
};





class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int size = timePoints.size();
        int *minutesArr = new int[size];
        
        for (int i = 0; i < size; i++) {
            minutesArr[i] = convertMinutes(timePoints[i]);
        }
        
        sort(minutesArr, minutesArr + size, less<int>());
        int minDiff = INT_MAX;
        
        for (int i = 1; i < size; i++) {
            minDiff = min(minDiff, minutesArr[i] - minutesArr[i - 1]);
        }
        
        minDiff = min(minDiff, 24 * 60 + minutesArr[0] - minutesArr[size - 1]);
        
        delete [] minutesArr;
        return minDiff;
        
    }
    
    int convertMinutes(const string& str) {
        auto pos = str.find(":");
        int len  = str.length();
        
        int hours = stoi(str.substr(0, pos));
        int minutes = stoi(str.substr(pos + 1));
        
        return 60 * hours + minutes;
    }
};