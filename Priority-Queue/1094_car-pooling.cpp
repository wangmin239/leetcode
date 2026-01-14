class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int to_max = 0;
        for (const auto& trip: trips) {
            to_max = max(to_max, trip[2]);
        }

        vector<int> diff(to_max + 1);
        for (const auto& trip: trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int count = 0;
        for (int i = 0; i <= to_max; ++i) {
            count += diff[i];
            if (count > capacity) {
                return false;
            }
        }
        return true;
    }
};




class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto greater = [](auto& lhs, auto& rhs) {
            return lhs.first > rhs.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> pq;
        
        sort(trips.begin(), trips.end(),[](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        }
        );
        
        for (auto& trip : trips) {
            int numPassenger = trip[0];
            int from = trip[1];
            int to = trip[2];
            /* check if the passengers have arrived at current station */
            while (pq.empty() != true) {
                auto cur = pq.top();
                
                if (cur.first > from) {
                    break;
                }
                
                capacity += cur.second;
                pq.pop();
            }
            if (capacity < numPassenger) {
                return false;
            }
            capacity -= numPassenger;
            pq.push({to, numPassenger});
        }
        return true;
    }
};