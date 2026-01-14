class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                sum++;
            } else {
                ans += sum;
            }
        }
        return ans;
    }
};



class Solution {
public:
    long long minimumSteps(string s) {
        int len = s.length();
        int whiteBall = 0;
        int blackBall = len - 1;
        long long steps = 0;
        
        while (whiteBall < blackBall) {
            while (whiteBall < len && s[whiteBall] == '0') {
                ++whiteBall;
            }
            
            while (blackBall >= 0 && s[blackBall] == '1') {
                --blackBall;
            }
            
            if (blackBall > whiteBall) {
                steps += blackBall - whiteBall;
            }
            ++whiteBall;
            --blackBall;
        }
        
        return steps;
    }
};