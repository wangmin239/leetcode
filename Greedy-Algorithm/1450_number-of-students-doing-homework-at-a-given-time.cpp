class Solution {
public: 
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int lessStart = upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
        int lessEnd = lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();
        return lessStart - lessEnd;
    }
};


class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int maxEndTime = *max_element(endTime.begin(), endTime.end());
        if (queryTime > maxEndTime) {
            return 0;
        }
        vector<int> cnt(maxEndTime + 2);
        for (int i = 0; i < n; i++) {
            cnt[startTime[i]]++;
            cnt[endTime[i] + 1]--;
        }
        int ans = 0;
        for (int i = 0; i <= queryTime; i++) {
            ans += cnt[i];
        }
        return ans;
    }
};




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