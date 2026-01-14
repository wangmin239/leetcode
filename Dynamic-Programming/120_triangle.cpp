/* Original Solution 1 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int layers = triangle.size();
        vector<int> sum(layers, INT_MAX);

        sum[0] = triangle[0][0];

        for (int layer = 1; layer < layers; layer++) {
            size_t num  = triangle[layer - 1].size();
            auto&& curLayer = triangle[layer];
            
            /* Update every element in an array, starting from the last index and moving to the first */
            for (size_t i = num; i > 0; i--) {
                sum[i] = min(sum[i - 1], sum[i]) + curLayer[i];

            }
            /* update the value of the first element */
            sum[0] += curLayer.front();
        }

        return *min_element(sum.begin(), sum.end());
    }
};


/* Original Solution 1 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int layers = triangle.size();
        shared_ptr<int[]> sum(new int[layers] {0});
        
        fill_n(sum.get(), layers, INT_MAX);
        sum[0] = triangle[0][0];

        for (int layer = 1; layer < layers; layer++) {
            size_t num  = triangle[layer - 1].size();
            auto&& curLayer = triangle[layer];
            
            /* Update every element in an array, starting from the last index and moving to the first */
            for (size_t i = num; i > 0; i--) {
                sum[i] = min(sum[i - 1], sum[i]) + curLayer[i];

            }
            /* update the value of the first element */
            sum[0] += curLayer.front();
        }

        return *min_element(sum.get(), sum.get() + layers);
    }
};



/* Official Solution 1 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};

/* Official Solution 3 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int layers = size(triangle);
        shared_ptr<int[]> sum(new int[layers]);
        
        /* initialize the sum array */
        for (int i = 0; i < layers; i++) {
            sum[i] = triangle[layers - 1][i];
        }
        
        for(int layer = layers -2; layer >= 0; layer--) {
            for(int i = 0; i <= layer; j++) {
                sum[i] = min(sum[i], sum[i + 1]) + triangle[layer][i];
            }
        }
        
        return sum[0];
    }
};

/* Official Solution 4 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = size(triangle);
        for(int i = m-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
        return triangle[0][0];
    }
};