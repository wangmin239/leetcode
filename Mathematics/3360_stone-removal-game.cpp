/* Original Solution 1 */
class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 0;
        int step = 10;
        const int member = 2;

        while (n >= step) {
            n -= step--;
            ++cnt;
        }

        return (cnt % member) == 1;
    }
};

/* Original Solution 1 */
class Solution {
public:
    bool canAliceWin(int n) {
        auto dfs = [](int stones, int removeStones, int removeCnt, auto&& self) -> bool{
            if (stones < removeStones) {
                return (removeCnt & 0x1) == 0x1;
            }

            return self(stones - removeStones, --removeStones, ++removeCnt, self);

        };

        return dfs(n, 10, 1, dfs);
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool canAliceWin(int n) {
        int k = (21 - sqrt(441 - 8 * n)) / 2;
        return k % 2 == 1;
    }
};
