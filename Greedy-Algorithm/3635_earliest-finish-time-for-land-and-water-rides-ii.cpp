/* Original Solution 1 */
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minCostTime = INT_MAX;

        vector<int> sortLand(n);
        vector<int> sortWater(m);

        iota(sortLand.begin(), sortLand.end(), 0);
        sort(sortLand.begin(), sortLand.end(), [&](const int i, const int j){
            return landStartTime[i] + landDuration[i] == landStartTime[j] + landDuration[j] ? landStartTime[i] < landStartTime[j] : landStartTime[i] + landDuration[i] < landStartTime[j] + landDuration[j];
        });

        iota(sortWater.begin(), sortWater.end(), 0);
        sort(sortWater.begin(), sortWater.end(), [&](const int i, const int j){
            return waterStartTime[i] + waterDuration[i] == waterStartTime[j] + waterDuration[j] ? waterDuration[i] < waterDuration[j] : waterStartTime[i] + waterDuration[i] < waterStartTime[j] + waterDuration[j];
        });

        int landIndex = sortLand.front();
        int minLandCostTime = landStartTime[landIndex] + landDuration[landIndex];
        for (int i = 0; i < m; i++) {
            int index = sortWater[i];

            if (waterStartTime[index] >= minLandCostTime) {
                minLandCostTime = max(minLandCostTime, waterStartTime[index]);
                minCostTime = min(minCostTime, minLandCostTime + waterDuration[index]);
                break;
            }
            minCostTime = min(minCostTime, minLandCostTime + waterDuration[index]);
        }

        int waterIndex = sortWater.front();
        int minWaterCostTime = waterStartTime[waterIndex] + waterDuration[waterIndex];
        for (int i = 0; i < n; i++) {
            int index = sortLand[i];

            if (landStartTime[index] >= minWaterCostTime) {
                minWaterCostTime = max(minWaterCostTime, landStartTime[index]);
                minCostTime = min(minCostTime, minWaterCostTime + landDuration[index]);
                break;
            }
            minCostTime = min(minCostTime, minWaterCostTime + landDuration[index]);
        }

        return minCostTime;
    }
};

/* Official Solution 1 */
class Solution {
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
