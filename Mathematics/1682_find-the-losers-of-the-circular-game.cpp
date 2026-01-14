class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unique_ptr<int[]> ptr (new int[n]);
        auto data = ptr.get();
        /* initialize the array */
        for (int i = 0; i < n; i++) {
            data[i] = 0;
        }
        
        int steps = 0;
        for (int i = 0; ;) {
            ++data[i];
            if (data[i] == 2) {
                break;
            }
            ++steps;
            i += k * steps;
            i %= n;
        }
        /* find the index whose value is zero */
        vector<int> ans;
        for (int j = 0; j < n; j++) {
            if (data[j] == 0) {
                ans.push_back(j + 1);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visit(n, false);
        for (int i = k, j = 0; !visit[j]; i += k) {
            visit[j] = true;
            j = (j + i) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};

