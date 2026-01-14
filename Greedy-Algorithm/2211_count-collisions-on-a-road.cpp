/* Original Solution 1 */
class Solution {
public:
    int countCollisions(string directions) {
        int len = directions.length();
        int cnt = 0;



        /* Case 1: Calculate the number of occurrences of two cars traveling in opposite directions */
        for (int i = 1; i < len; i++) {
            if (directions[i] == 'L' && directions[i - 1] == 'R') {
                cnt += 2;
                directions[i] = directions[i - 1] = 'S';
            }
        }

        /* Case 2: Calculate the number of collisions between a right-moving car and a stationary car */        
        for (int i = 0, towardRight = 0; i < len; i++) {
            if (directions[i] == 'R') {
                ++towardRight;
            }

            if (directions[i] == 'S') {
                cnt += towardRight;
                towardRight = 0;
            }
        }
        /* Case 3: Calculate the number of collisions between a left-moving car and a stationary car  */
        for (int i = len - 1, towardLeft = 0; i >= 0; i--) {
            if (directions[i] == 'L') {
                ++towardLeft;
            }

            if (directions[i] == 'S') {
                cnt += towardLeft;
                towardLeft = 0;
            }
        }

        return cnt;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int countCollisions(string directions) {
        int len = directions.length();
        int ans = 0;
        int left = 0, right = len - 1;

        while (left < len) {
            if (directions[left] != 'L') {
                break;
            }
            ++left;
        }

        while (right >= 0) {
            if (directions[right] != 'R') {
                break;
            }
            --right;
        }


        while (left < right) {
            if (directions[left++] != 'S') {
                ++ans;
            }
        }

        return ans;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int countCollisions(string s) { 
        int n = s.size();

        // 前缀向左的车不会发生碰撞
        int l = 0;
        while (l < n && s[l] == 'L') {
            l++;
        }

        // 后缀向右的车不会发生碰撞
        int r = n; 
        while (r > l && s[r - 1] == 'R') {
            r--;
        }

        // 剩下非静止的车必然会碰撞
        int cnt = 0; 
        for (int i = l; i < r; i++) {
            cnt += s[i] != 'S';
        }
        return cnt;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        int flag = -1;
        for (auto c : directions) {
            if (c == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
            }
        }
        return res;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }

        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
            }
        }
        return res;
    }
};