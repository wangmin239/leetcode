/* Original Solution 1 */
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (x1 <= xCenter + radius && x2 >= xCenter - radius && y1 <= yCenter + radius && y2 >= yCenter - radius) {
            return true;
        }

        if (xCenter + radius <= x2 && xCenter - radius >= x1 && (y1 <= yCenter + radius || y2 >= yCenter - radius)) {
            return true;
        }

        if (yCenter + radius <= y2 && yCenter - radius >= y1 && (x1 <= xCenter + radius || x2 >= xCenter - radius)) {
            return true;
        }
        return false;
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dist = 0;
        if (xCenter < x1 || xCenter > x2) {
            dist += min(pow(x1 - xCenter, 2), pow(x2 - xCenter, 2));
        }
        if (yCenter < y1 || yCenter > y2) {
            dist += min(pow(y1 - yCenter, 2), pow(y2 - yCenter, 2));
        }
        return dist <= radius * radius;
    }
};
