class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int xMax = INT_MIN, yMax = INT_MIN;
        for (auto &&tower : towers) {
            int x = tower[0], y = tower[1];
            xMax = max(xMax, x);
            yMax = max(yMax, y);
        }
        int cx = 0, cy = 0;
        int maxQuality = 0;
        for (int x = 0; x <= xMax; x++) {
            for (int y = 0; y <= yMax; y++) {
                vector<int> coordinate = {x, y};
                int quality = 0;
                for (auto &&tower : towers) {
                    int squaredDistance = getSquaredDistance(coordinate, tower);
                    if (squaredDistance <= radius * radius) {
                        double distance = sqrt((double)squaredDistance);
                        quality += floor((double)tower[2] / (1 + distance));
                    }
                }
                if (quality > maxQuality) {
                    cx = x;
                    cy = y;
                    maxQuality = quality;
                }
            }
        }
        return {cx, cy};
    }

    int getSquaredDistance(const vector<int> &coordinate, const vector<int> &tower) {
        return (tower[0] - coordinate[0]) * (tower[0] - coordinate[0]) + (tower[1] - coordinate[1]) * (tower[1] - coordinate[1]);
    }
};




class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int len = towers.size();
        unique_ptr<int[]> quality(new int [len]);
        
        for (int i = 0; i < len; i++) {
            quality.get()[i] = getQuality(towers, i, radius);
        }
        int maxQuality = *max_element(quality.get(), quality.get() + len);
        vector<pair<int, int>> maxArr;
        for (i = 0; i < len; i++) {
            if (maxQuality == quality.get()[i]) {
                maxArr.emplace_back(towers[i][0], towers[i][1]);
            }
        }
        auto comp = [](const auto pi, const auto pj) {
            if (pi.first < pj.first) {
                return true;
            } 
            if (pi.first == pj.first && pi.second < pj.second) {
                return true;
            }
            return false;
        };
        sort(maxArr.begin(), maxArr.end(), comp);
        
        return maxArr.front();
    }
    
    
    int getDistance(vector<vector<int>>& towers, int src, int dst) {
        int dx = towers[src][0] - towers[dst][0];
        int dy = towers[src][1] - towers[dst][1];
        
        return dx * dx + dy * dy;
        
    }
    
    int getQuality(vector<vector<int>>& towers, int src, int radius) {
        int quality = 0;
        for (int i = 0; i < towers.size(); i++) {
            int distance = getDistance(towers, src, i);
            if (distance > radius * radius) {
                continue;
            }
            double len = pow(static_cast<double>(distance), 0.25); 
            quality += towers[i][2] /(1 + static_cast<int>(len));
        }
        return quality;
    }
};