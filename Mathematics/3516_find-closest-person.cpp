/* Original Solution 1 */
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xSteps = abs(z - x);
        int ySteps = abs(z - y);
        
        return xSteps == ySteps ? 0 : xSteps < ySteps ? 1 : 2;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (x == y || x + y == 2 * z) {
            return 0;
        }
        
        if (x < y && x + y < 2 * z) {
            return 2;
        }
        if (x > y && x + y > 2 * z) {
            return 2;
        }
        
        return 1;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dxz = abs(x - z), dyz = abs(y - z);
        if (dxz < dyz) {
            return 1;
        } else if (dxz > dyz) {
            return 2;
        } else {
            return 0;
        }
    }
};
