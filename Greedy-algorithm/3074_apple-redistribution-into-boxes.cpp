
/* Original Solution 1 */
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = reduce(apple.begin(), apple.end(), 0);
        int boxCnt = 0;

        sort(capacity.begin(), capacity.end(), greater<int>());

        for (int size : capacity) {
            if (total <= 0) {
                break;
            }
            total -= size;
            ++boxCnt;
        }

        return boxCnt;
    }
};


class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int s = reduce(apple.begin(), apple.end()); // 把所有苹果堆在一起
        ranges::sort(capacity, greater()); // 先装大箱子，再装小箱子
        int i = 0;
        while (s > 0) { // 还有剩余苹果
            s -= capacity[i++]; // 使用一个箱子
        }
        return i;
    }
};
