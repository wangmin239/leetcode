/* Original Solution 1 */
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        unsigned long long sum = mass;
        for (int aster : asteroids) {
            if (sum < aster) {
                return false;
            }
            sum += aster;
        }

        return true;
    }
};

/* Official Solution 1 */
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());   // 按照质量升序排序
        long long mass1 = mass;
        for (const int asteroid: asteroids) {
            // 按顺序遍历小行星，尝试摧毁并更新质量或者返回结果
            if (mass1 < asteroid){
                return false;
            }
            mass1 += asteroid;
        }
        return true;   // 成功摧毁所有小行星
    }
};
