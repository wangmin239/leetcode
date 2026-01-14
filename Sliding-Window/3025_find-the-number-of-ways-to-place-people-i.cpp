/* Original Solution 1 */
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        auto lessPoint = [](const auto& lhs, const auto& rhs) {
            return lhs.front() == rhs.front() ? lhs.back() > rhs.back() : lhs.front() < rhs.front();
        };
        int cnt = 0;
        
        sort(points.begin(), points.end(), lessPoint);
        
        for (int left = 0; left < n - 1; left++) {
            int leftY = points[left].back();
            
            for (int right = left + 1; right < n; right++) {
                int rightY = points[right].back();
                
                if (leftY < rightY) {
                    continue;
                }
                /* check if there is one point located in the rectangle */
                bool haveInnerPoint = false;
                for (int id = left + 1; id < right; id++) {
                    int innerY = points[id].back();
                    if (innerY <= leftY && innerY >= rightY) {
                        haveInnerPoint = true;
                        break;
                    }
                }
                
                if (haveInnerPoint == false) {
                    ++cnt;
                }
            }
        }
        
        return cnt;        
    }
};


/* Official Solution 1 */
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            auto &pointA = points[i];
            for (int j = 0; j < n; j++) {
                vector<int> pointB = points[j];
                if (i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }
                if (n == 2) {
                    ans++;
                    continue;
                }

                bool illegal = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }

                    auto & pointTmp = points[k];
                    bool isXContained = pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    bool isYContained = pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }
                if (!illegal) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
