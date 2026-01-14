class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int pos = 0;
        int space = 0;
        for (int arrive : buses) {
            space = capacity;
            while (space > 0 && pos < passengers.size() && passengers[pos] <= arrive) {
                space--;
                pos++;
            }
        }
        
        pos--;
        int lastCatchTime = space > 0 ? buses.back() : passengers[pos];
        while (pos >= 0 && passengers[pos] == lastCatchTime) {
            pos--;
            lastCatchTime--;
        }

        return lastCatchTime;
    }
};



class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {     
        int n = buses.size();
        int m = passengers.size();

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int i, j;
        int numInTurns;
        for (i = 0, j = 0; i < n; i++) {
            numInTurns = 0;
            while (j < m && passengers[j] <= buses[i] && numInTurns < capacity) {
                numInTurns++;
                j++;
            }
            
        }
        --j;
        int lastTime =  numInTurns < capacity ? buses.back() : passengers[j];
        
        while (j >= 0 && lastTime == passengers[j]) {
            j--;
            lastTime--;
        }
        
        return lastTime;
    }
};