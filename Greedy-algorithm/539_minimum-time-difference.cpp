

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