class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = 30 * hour;
        if (hour == 12) {
            hourAngle = 0;
        }
        hourAngle += (minutes/60.0) * 30;
        double minutesAngle = 6 * minutes;
        double diffBetweenAngles = abs(hourAngle-minutesAngle);
        return min(diffBetweenAngles, 360 - diffBetweenAngles);
    }
};