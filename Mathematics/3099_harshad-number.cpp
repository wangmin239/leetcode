class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int data(x);
        const int decimal = 10;
        
        while (data) {
            sum += data % decimal;
            data /= decimal;
        }
        
        return x % sum == 0 ? sum : -1;
    }
};


class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y; y /= 10) {
            s += y % 10;
        }
        return x % s ? -1 : s;
    }
};

