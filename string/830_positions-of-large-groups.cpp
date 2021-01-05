class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        /* check the string is empty */
        if (s.empty() == true) {
            return result;
        }

        char preCh = s[0];
        int  count = 1;
        int startId, endId, i;
        /* abstract the continuous character */
        startId = endId = 0;
        for (i = 1; i < s.length(); i++) {
            if (preCh == s[i]) {
                count++;
                continue;
            }
            /* find the continuous character */
            if (count > 2) {
                endId = i - 1;
                result.push_back({startId, endId});
            }
            preCh = s[i];
            count = 1;
            startId = i;
        }
        /*the last character meet the requirements */
        if (count > 2) {
            result.push_back({startId, i - 1});
        }


        return result;
    }
};