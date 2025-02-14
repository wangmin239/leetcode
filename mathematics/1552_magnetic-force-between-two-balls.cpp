/* Official Solution */
class Solution {
public:
    bool check(int x, vector<int>& position, int m) {
        int pre = position[0], cnt = 1;
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - pre >= x) {
                pre = position[i];
                cnt += 1;
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = position.back() - position[0], ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid, position, m)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};


/* Original Solution */
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        
        sort(position.begin(), position.end());

        int left = 1;
        int right = position.back() - position.front();
        int pre = position.front();
        int cnt = 1;
 
        while (left < right) {
            int mid = (left + right) / 2;
            
            cnt = 1;
            pre = position[0];

            for (int i = 1; i < n; i++) {
                if (position[i] >= pre + mid) {
                    ++cnt;
                    pre = position[i];
                }
            }
            
            if (cnt < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        pre = position[0];
        cnt = 1;

        for (int i = 1; i < n; i++) {
            if (position[i] >= pre + left) {
                ++cnt;
                pre = position[i];
            }
        }
        
        return cnt >= m ? left : left - 1;
    }
};