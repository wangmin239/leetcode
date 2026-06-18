/* Original Solution 1 */
class Solution {
public:
    double angleClock(int hour, int minutes) {
        float minuteAngle;
        float hourAngle;

        minuteAngle =  minutes * 6;
        hourAngle = static_cast<float>(minutes) / 2 + 30 * hour;

        float angleDiff = max(hourAngle, minuteAngle) - min(hourAngle, minuteAngle);

        return min(angleDiff, 360.0 - angleDiff);
    }
};

/* Official Solution 1 */
class Solution {
  public:
  double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

    double diff = abs(hourAngle - minutesAngle);
    return min(diff, 360 - diff);
  }
};

/* Official Solution 2 */
class Solution {
public:
    double angleClock(int hour, int minutes) {
        int d = abs(hour * 60 - minutes * 11);
        return min(d, 720 - d) / 2.0;
    }
};
