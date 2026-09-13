
/* Official Solution 1 */
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        vector<pair<int, int>> A2, B2;
        
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (A[r][c]) {
                    A2.emplace_back(r, c);
                }
                if (B[r][c]) {
                    B2.emplace_back(r, c);
                }
            }
        }
        
        auto pairHash = [](const pair<int, int>& p) {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        };
        
        unordered_set<pair<int, int>, decltype(pairHash)> Bset(0, pairHash);
        unordered_set<pair<int, int>, decltype(pairHash)> seen(0, pairHash);
        
        for (const auto& p : B2) {
            Bset.insert(p);
        }
        
        int ans = 0;
        
        for (const auto& a : A2) {
            for (const auto& b : B2) {
                auto d = make_pair(b.first - a.first, b.second - a.second);
                if (seen.find(d) == seen.end()) {
                    seen.insert(d);
                    int count = 0;
                    for (const auto& x : A2) {
                        auto p = make_pair(x.first + d.first, x.second + d.second);
                        if (Bset.find(p) != Bset.end()) {
                            ++count;
                        }
                    }
                    ans = max(ans, count);
                }
            }
        }
        
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        vector<vector<int>> count(2 * N + 1, vector<int>(2 * N + 1, 0));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) {
                    for (int i2 = 0; i2 < N; ++i2) {
                        for (int j2 = 0; j2 < N; ++j2) {
                            if (B[i2][j2] == 1) {
                                count[i - i2 + N][j - j2 + N] += 1;
                            }
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for (const auto& row : count) {
            for (int v : row) {
                ans = std::max(ans, v);
            }
        }
        
        return ans;
    }
};
