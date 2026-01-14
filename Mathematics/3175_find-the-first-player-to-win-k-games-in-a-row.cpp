class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int cnt = 0;
        int i = 0, last_i = 0;
        while (i < n) {
            int j = i + 1; 
            while (j < n && skills[j] < skills[i] && cnt < k) {
                j++;
                cnt++;
            }
            if (cnt == k) {
                return i;
            }
            cnt = 1;
            last_i = i;
            i = j;
        }
        return last_i;
    }
};




class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int id = 0;
        int cnt = 0;
        
        /* mark the first player who consecutively win K rounds */
        for (int i = 1; i < n; i++) {
            if (skills[id] > skills[i]) {
                ++cnt;
            } else {
                id = i;
                cnt = 1;
            }
            
            if (cnt == k) {
                break;
            }
        }
        
        return id;
    }
};


