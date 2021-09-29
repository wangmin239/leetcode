class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (tot % n) {
            return -1;
        }
        int avg = tot / n;
        int ans = 0, sum = 0;
        for (int num: machines) {
            num -= avg;
            sum += num;
            ans = max(ans, max(abs(sum), num));
        }
        return ans;
    }
};




class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int i, size = machines.size(), sum = getSum(machines), average = sum / size;
        if (average * size != sum) {
            return -1;
        }

        int left = machines[0], wantedLeft = average, right, wantedRight = average * (size - 2);
        int minMoves = max(abs(machines[0] - average), abs(machines[size - 1] - average));

        for (i = 1; i < size - 1; ++i) {
            int num = machines[i];
            right = sum - num - left;

            if (num >= average) {
                int moves = num - average;
                if (left > wantedLeft) {
                    moves += (left - wantedLeft);
                }
                if (right > wantedRight) {
                    moves += (right - wantedRight);
                }
                minMoves = max(minMoves, moves);

            }

            left += num;
            wantedLeft += average;
            wantedRight -= average;
        }

        return minMoves;
    }

    int getSum(vector<int>& machines) {
        int sum = 0;

        for (int num : machines) {
            sum += num;
        }

        return sum;
    }
};

作者：wen-rou-yi-dao-123
链接：https://leetcode-cn.com/problems/super-washing-machines/solution/duo-tu-xiang-xi-jie-shi-yi-xia-yi-fu-de-rq3g4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。