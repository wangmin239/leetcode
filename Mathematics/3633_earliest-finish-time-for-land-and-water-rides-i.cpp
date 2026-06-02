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

/* Original Solution 1 */
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minCostTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            int curCostTime = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                if (curCostTime >= waterStartTime[j]) {
                    minCostTime = min(minCostTime, curCostTime + waterDuration[j]);
                } else {
                    minCostTime = min(minCostTime, waterStartTime[j] + waterDuration[j]);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int curCostTime = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < n; j++) {
                if (curCostTime >= landStartTime[j]) {
                    minCostTime = min(minCostTime, curCostTime + landDuration[j]);
                } else {
                    minCostTime = min(minCostTime, landStartTime[j] + landDuration[j]);
                }
            }
        }

        return minCostTime;
    }
};