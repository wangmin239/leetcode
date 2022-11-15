class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.back() > rhs.back();
        };
        int numUnit = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        auto iter = boxTypes.begin();
        
        while (truckSize > 0 && iter != boxTypes.end()) {
            if (truckSize > iter->front()) {
                truckSize -= iter->front();
                numUnit += iter->front() * iter->back();
            } else {
                numUnit += truckSize * iter->back();
                truckSize = 0;
            }
            ++iter;
        }
        return numUnit;
    }
};


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        });
        int res = 0;
        for (auto &boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int numberOfUnitsPerBox = boxType[1];
            if (numberOfBoxes < truckSize) {
                res += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            } else {
                res += truckSize * numberOfUnitsPerBox;
                break;
            }
        }
        return res;
    }
};