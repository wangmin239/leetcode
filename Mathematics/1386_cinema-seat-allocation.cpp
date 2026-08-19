/* Original Solution 1 */
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int cnt = 0;
        auto lessCmp = [](const auto& lhs, const auto& rhs) {
            return lhs.front() < rhs.front();
        };
        const int family = 3;
        const int seatMaskGroup[family] = { 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5,
                                            1 << 6 | 1 << 7 | 1 << 8 | 1 << 9,
                                            1 << 4 | 1 << 5 | 1 << 6 | 1 << 7
        };

        int len = reservedSeats.size();
        auto getSeatCnt = [&seatMaskGroup](int seatMask) {
            int seat0 = 0, seat1 = 0, seat2 = 0;

            if (seatMask & seatMaskGroup[0]) {
                seat0 = 1;
            }

            if (seatMask & seatMaskGroup[1]) {
                seat1 = 1;
            }

            if (seatMask & seatMaskGroup[2]) {
                seat2 = 1;
            }

            if (seat0 & seat1 & seat2) {
                return 0;
            }

            if (seat0 == 0 && seat1 == 0) {
                return 2;
            }
            return 1;
        };

        sort(reservedSeats.begin(), reservedSeats.end(), lessCmp);

        int startRow = reservedSeats.front().front();

        cnt += (startRow - 1) << 1;
        for (int row = startRow, id = 0; row <= n; row++) {
            if (row < reservedSeats[id].front()) {
                cnt += 2;
                continue;
            }

            int seatMask = 0;
            while (id < len && row == reservedSeats[id].front()) {
                seatMask |= 1 << reservedSeats[id++].back();
            }


            cnt += getSeatCnt(seatMask);

            if (id == len) {
                break;
            }
        }

        int lastRow = reservedSeats.back().front();
        if (lastRow <= n){
            cnt += 2 * (n - lastRow);
        }

        return cnt;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;
        int middle = 0b11000011;
        int right = 0b00001111;

        unordered_map<int, int> occupied;
        for (const vector<int>& seat: reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2));
            }
        }

        int ans = (n - occupied.size()) * 2;
        for (auto& [row, bitmask]: occupied) {
            if (((bitmask | left) == left) || ((bitmask | middle) == middle) || ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};
