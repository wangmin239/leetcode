/* Original Solution 1 */
class Solution {
public:
    int maxDistance(string s, int k) {
        int distance = 0;
        const int size = 4;
        enum Dir {
            SOUTH = 0,
            EAST = 1,
            NORTH = 2,
            WEST = 3,
        };
        
        int directions[size] = {0};
        
        auto getMaxDistance = [size](int dirs[size], int k) {
            pair<int, Dir> counts[size] = {{0, SOUTH}};
            int sum, oppositeSum, revertCnt;
            
            for (int i = 0; i < size; i++) {
                counts[i] = make_pair(dirs[i], static_cast<Dir>(i));
            }
            
            /* Sort the numbers in descending order. */
            sort(counts, counts + size, [](const auto& lhs , const auto& rhs) {return lhs.first > rhs.first;});
            
            if ((counts[0].second ^ counts[1].second) != 2) {
                sum = counts[0].first + counts[1].first;
                oppositeSum = counts[2].first + counts[3].first;
            } else {
                sum = counts[0].first + counts[2].first;
                oppositeSum = counts[1].first + counts[3].first;
            }
            
            revertCnt = min(oppositeSum, k);
            return sum - oppositeSum + (revertCnt << 1);
        };
        /*  put every character into statistic */
        for (char ch : s) {
            switch(ch) {
                case 'S':
                    directions[SOUTH]++;
                    break;
                case 'E':
                    directions[EAST]++;
                    break;
                case 'N':
                    directions[NORTH]++;
                    break;
                default:
                    directions[WEST]++;
            }
            distance = max(distance, getMaxDistance(directions, k));
        }
        
        return distance;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for (char it : s) {
            switch (it) {
            case 'N':
                north++;
                break;
            case 'S':
                south++;
                break;
            case 'E':
                east++;
                break;
            case 'W':
                west++;
                break;
            }
            int times1 = min({north, south, k});        // modification times for N and S
            int times2 = min({east, west, k - times1}); // modification times for E and W
            ans = max(ans,
                      count(north, south, times1) + count(east, west, times2));
        }
        return ans;
    }

    int count(int drt1, int drt2, int times) {
        return abs(drt1 - drt2) + times * 2;
    } // Calculate modified Manhattan distance
};

/* Official Solution 2 */
class Solution {
public:
    int maxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
            case 'N':
                latitude++;
                break;
            case 'S':
                latitude--;
                break;
            case 'E':
                longitude++;
                break;
            case 'W':
                longitude--;
                break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};
