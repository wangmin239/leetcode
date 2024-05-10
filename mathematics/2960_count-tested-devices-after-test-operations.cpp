class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cnt = 0;
        int n = batteryPercentages.size();
        
        for (int i = 0; i < n; i++) {
            if (batteryPercentages[i] < 1) {
                continue;
            }
            ++cnt;
            for (int j = i + 1; j < n; j++) {
                batteryPercentages[j] = max(0, batteryPercentages[j]) - 1;
            }
        }
        
        return cnt;
    }
};




class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cnt = 0;
        
        for (int percent : batteryPercentages) {
            if (percent > cnt) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int need = 0;
        for (int i = 0; i < n; i++) {
            if (batteryPercentages[i] > 0) {
                need++;
                for (int j = i + 1; j < n; j++) {
                    batteryPercentages[j] = max(batteryPercentages[j] - 1, 0);
                }
            }
        }
        return need;
    }
};
