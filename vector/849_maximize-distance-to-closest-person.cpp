class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDistance = 0;
        int len = seats.size();
        int left = 0;
        int right;
        
        /* obtain the index of the first non-empty seat*/
        for (right = 0; right < len; right++) {
            if (seats[right] != 0) {
                maxDistance = right - left;
                left = right;
                break;
            }
        }
        
        /* compare the distance between the adjacent non-empty seats */
        for (; right < len; right++) {
            if (seats[right] != 0) {
                maxDistance = max(maxDistance, (right - left)/2);
                left = right;
            }
        }
        /* check if the last seat is empty */
        if (seats[right - 1] == 0) {
            maxDistance = max(maxDistance, right - left - 1);
        }
        
        return maxDistance;
        
    }
};

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int l = 0;
        while (l < seats.size() && seats[l] == 0) {
            ++l;
        }
        res = max(res, l);
        while (l < seats.size()) {
            int r = l + 1;
            while (r < seats.size() && seats[r] == 0) {
                ++r;
            }
            if (r == seats.size()) {
                res = max(res, r - l - 1);
            } else {
                res = max(res, (r - l) / 2);
            }
            l = r;
        }
        return res;
    }
};
