class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            ans += 50;
            if (additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        return ans + mainTank * 10;
    }
};


class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
       int distance = 0;
       const int limit = 5;
       const int unit = 10;

       
       while ((mainTank < limit) == false) {
           int consume = mainTank / limit;
           
           distance += limit * unit * consume;
           mainTank -= limit * consume;
           
           consume = min(additionalTank, consume);
           mainTank += consume;
           additionalTank -= consume;
       }
       
       distance += unit * mainTank;

       return distance;
    }
};




class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
       int distance = 0;
       const int limit = 5;
       const int unit = 10;
       
       if (mainTank < limit) {
           return unit * mainTank;
       }
       
       int consume = mainTank / limit;
       
       distance = limit * 10 * consume;
       mainTank -= limit * consume;
       
       consume = min(additionalTank, consume);
       
       return distance + distanceTraveled(mainTank + consume, additionalTank - consume);
    }
};