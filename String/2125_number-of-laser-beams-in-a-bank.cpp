/* Original Solution 1 */
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rows = bank.size();
        int cols = bank.front().length();
        int sum = 0;
        /* Get the count of non-zero elements in a numeric string. */
        auto getBeams = [cols](const string&& strBeam) {
            int num = 0;

            for (int col = 0; col < cols; col++) {
                num += strBeam[col] - '0';
            }
            return num;
        };

        int curBeams = 0;

        for (int topRow = -1; topRow < rows; ) {
            int bottomRow = topRow;
            int nextBeams = 0;
            /* Search for the first row with at least one non-zero element */
            while (nextBeams == 0 && ++bottomRow < rows) {
                nextBeams = getBeams(bank[bottomRow]);
            }
            /* Update the previous state machine’s status */
            sum += curBeams * nextBeams;
            curBeams = nextBeams;
            topRow = bottomRow;
        }

        return sum;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, pre_cnt = 0;
        for (auto& row : bank) {
            int cnt = ranges::count(row, '1');
            if (cnt > 0) {
                ans += pre_cnt * cnt;
                pre_cnt = cnt;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0, ans = 0;
        for (const string& line: bank) {
            int cnt = count_if(line.begin(), line.end(), [](char ch) {return ch == '1';});
            if (cnt != 0) {
                ans += last * cnt;
                last = cnt;
            }
        }
        return ans;
    }
};
