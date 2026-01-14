class Solution {
public:
	int countBalls(int lowLimit, int highLimit) {
		int ans = 0;
		unordered_map<int, int> cnt;
		int cur = 0, tmp = lowLimit;  // tmp 是当前 lowLimit 的盒子编号
		while (tmp) {
			cur += tmp % 10;
			tmp /= 10;
		}
		ans = max(ans, ++cnt[cur]);
		++cur;
		for (int i = lowLimit + 1; i <= highLimit; ++i, ++cur) {
            // 对于下一个小球，其各位数和是上一个小球各位和 +1
            // 但是当当前小球是 10 的倍数时，就不是简单的 +1
            // 例如：9 -> 10; 99 -> 100
            // 也就是说当小球编号是 10 的倍数时与后缀 0 的个数有关
			for (int tmp = i; tmp % 10 == 0; tmp /= 10) cur -= 9;
			ans = max(ans, ++cnt[cur]);
		}
		return ans;
	}
};


class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int box = 0, x = i;
            while (x) {
                box += x % 10;
                x /= 10;
            }
            count[box]++;
            res = max(res, count[box]);
        }
        return res;
    }
};




class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        const int max = 48;
        unique_ptr<int[]> boxes(new int[max]);
        int* ptr = boxes.get();
        
        /* Intialize the array */
        for (int i = 0; i < max; i++) {
            ptr[i] = 0;
        }
        
        /* calculate the sum of every ball's id */
        for (int ballId = lowLimit; ballId <= highLimit; ballId++) {
            int id = ballId;
            int boxId = 0;
            
            while (id != 0) {
                boxId += id % 10;
                id /= 10;
            }
            
            ++ptr[boxId];
        }
        
        /* query the box which contains the maximum balls */
        return *max_element(ptr, ptr + max);
    }
};


class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        const int max = 48;
        unique_ptr<int[]> boxes(new int[max] {0});
        int* ptr = boxes.get();

        
        /* calculate the sum of every ball's id */
        for (int ballId = lowLimit; ballId <= highLimit; ballId++) {
            int id = ballId;
            int boxId = 0;
            
            while (id != 0) {
                boxId += id % 10;
                id /= 10;
            }
            
            ++ptr[boxId];
        }
        
        /* query the box which contains the maximum balls */
        return *max_element(ptr, ptr + max);
    }
};





class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(48, 0);
        
        for (int ballId = lowLimit; ballId <= highLimit; ballId++) {
            int id = ballId;
            int boxId = 0;
            
            while (id != 0) {
                boxId += id % 10;
                id /= 10;
            }
            
            ++boxes[boxId];
        }
        
        return *max_element(boxes.begin(), boxes.end());
    }
};
