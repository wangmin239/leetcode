class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> datesOfMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefixSum(1, 0);
        for (int date : datesOfMonths) {
            prefixSum.emplace_back(prefixSum.back() + date);
        }

        int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
        int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
        int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
        int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
        return max(0, min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1);
    }

    int calculateDayOfYear(string day, const vector<int> &prefixSum) {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));
        return prefixSum[month - 1] + date;
    }
};       


class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveAliceDays = calculateDay(arriveAlice);
        int leaveAliceDays = calculateDay(leaveAlice);
        int arriveBobDays = calculateDay(arriveBob);
        int leaveBobDays = calculateDay(leaveBob);
        
        int commonStart = max(arriveAliceDays, arriveBobDays);
        int commonEnd = min(leaveAliceDays, leaveBobDays);
        
        if (commonStart > commonEnd) {
            return 0;
        }
        
        return commonEnd - commonStart + 1;
        
    }
    
    int calculateDay(const string& date) {
                          /* Jan, Feb, Mar, Apr, */
        int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int days = stoi(date.substr(3, 2));
        
        for (int i = 0; i < month; i++) {
            days += monthDays[i];
        }
        
        return days;
    }
};