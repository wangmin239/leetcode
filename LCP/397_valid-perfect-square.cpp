class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        
        int high = num / 2;
        int low = 0;
        int mid;
        while (low <= high) {
            mid = (high + low) / 2;
            int divides = num / mid;
            if (divides < mid) {
                high = mid - 1;
            } else if (divides > mid) {
                low = mid + 1;
            } else {
                return num % mid == 0;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        double x0 = num;
        while (true) {
            double x1 = (x0 + num / x0) / 2;
            if (x0 - x1 < 1e-6) {
                break;
            }
            x0 = x1;
        }
        int x = (int) x0;
        return x * x == num;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = (int) sqrt(num);
        return x * x == num;
    }
};


class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            long square = (long) mid * mid;
            if (square < num) {
                left = mid + 1;
            } else if (square > num) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

