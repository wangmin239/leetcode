/* Official Solution 1 */
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> zeroRight;

        /* Count the length of the consecutive zero sequence starting from the right */
        for (int row = 0; row < n; row++) {
            int zeroCnt = 0;
            for (int col = n - 1; col >= 0; col--) {
                if (grid[row][col] != 0) {
                    break;
                }
                ++zeroCnt;
            }
            zeroRight.emplace_back(zeroCnt, row);
        }

        sort(zeroRight.begin(), zeroRight.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first > rhs.first;
        });

        int steps = 0;
        for (int i = 0; i < n; i++) {
            if (zeroRight[i].first < n - 1 - i) {
                return -1;
            }
            /* Find the smallest index where the value is greater than the index itself */
            int id = zeroRight[i].second;
            int minId = i;
            for (int j = i + 1; j < n; j++) {
                if (zeroRight[j].first >= n -1 - i) {
                    if (zeroRight[j].second < id) {
                        id = zeroRight[j].second;
                        minId = j;
                    }
                }
            }
            /* Update the values of elements preceding the minimum index */
            steps += id - i;
            for (int j = minId; j > i; j--) {
                zeroRight[j] = zeroRight[j - 1];
            }
            /* Increment all elements preceding the nearest index by 1 */
            for (int j = i + 1; j < n; j++) {
                if (zeroRight[j].second < id) {
                    ++zeroRight[j].second;
                }
            }
        }

        return steps;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (~k) {
                for (int j = k; j > i; --j) {
                    swap(pos[j], pos[j - 1]);
                }
            } else {
                return -1;
            }
        }
        return ans;
    }
};



/* Official Solution 1 */
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // 预处理每一行的尾零个数
        int n = grid.size();
        vector<int> tail_zeros(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j]) {
                    tail_zeros[i] = n - 1 - j;
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int j = i;
            while (j < n && tail_zeros[j] < n - 1 - i) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            ans += j - i;
            // 从 j 换到 i，原来 [i, j-1] 中的数据全体右移一位
            copy_backward(tail_zeros.begin() + i, tail_zeros.begin() + j, tail_zeros.begin() + j + 1);
        }
        return ans;
    }
};
