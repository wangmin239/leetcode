class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int sum = 0;
        int  len = startTime.size();
        
        for (int i = 0; i < len; i++) {
            if (startTime[i] > queryTime){
                sum++;
                continue;
            }
            
            if (endTime[i] < queryTime) {
                sum++;
            }
        }
        
        return len - sum;
    }
};


class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int sum = 0;;
        
        for (auto time : endTime) {
            if (time >= queryTime) {
                ++sum;
            }
        }
        
        for (auto time : startTime) {
            if (time > queryTime) {
                --sum;
            }
        }
        return sum;
    }
};