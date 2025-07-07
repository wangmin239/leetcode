
/* Original Solution 1 */
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       auto comp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first != rhs.first? lhs.first > rhs.first:
                    lhs.second > rhs.second;
       };
       
       priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

       for (const auto meeting : events) {
        pq.emplace(meeting.front(), meeting.back());
       }
       
       int cnt = 0;
       int prev = 0;
       while (pq.empty() == false) {
           auto pair = pq.top();
           
           pq.pop();
           if (pair.second <= prev) {
               continue;
           }
           
           if (prev < pair.first) {
               prev = pair.first;
               ++cnt;
               continue;
           } 

           pair.first = prev + 1;
           pq.push(pair);

       }
       
       return cnt;
    }
};

/* Official Soluiton 1 */
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int ans = 0;
        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};

