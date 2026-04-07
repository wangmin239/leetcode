/* Original Solution 1 */
class Robot {
public:
    typedef enum {
        East = 0,
        North = 1,
        West = 2,
        South = 3,
        Max
    } Dirs;

    Robot(int width, int height) {
        rows = height;
        cols = width;
        x = y = 0;
        degree = 0;
    }

    Dirs rotation(void) {
        degree += rightAngle;
        degree %= circle;
        return static_cast<Dirs>(degree / rightAngle);
    }
    void step(int num) {
        Dirs curDir = static_cast<Dirs>(degree / rightAngle);
        while (num--) {
            if (curDir == East) {
                if (x + 1 < cols) {
                    ++x;
                } else {
                    curDir = rotation();
                    num %= 2 * (rows + cols) - 4;
                }
            }
            if (curDir == North) {
                if (y + 1 < rows) {
                    ++y;
                } else {
                    curDir = rotation();
                    num %= 2 * (rows + cols) - 4;
                }
            }
            if (curDir == West) {
                if (x - 1 < 0) {
                    curDir = rotation();
                    num %= 2 * (rows + cols) - 4;
                } else {
                    --x;
                }
            }
            if (curDir == South) {
                if (y - 1 < 0) {
                    curDir = rotation();
                    ++num;
                } else {
                    --y;
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        int id = degree / rightAngle;
        return directions[id];
    }
    int x, y;
    int rows, cols;
    int degree;
    static const int rightAngle = 90;
    static const int circle = 360;
    static constexpr string directions[] = {"East", "North", "West", "South"};
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
 
 

/* Official Solution 1 */
class Robot {
private:
    bool moved = false;
    int idx = 0;
    vector<pair<int, int>> pos;
    vector<int> dir;
    unordered_map<int, string> to_dir = {
        {0, "East"},
        {1, "North"},
        {2, "West"},
        {3, "South"}
    };
    
public:
    Robot(int width, int height) {
        for (int i = 0; i < width; ++i) {
            pos.emplace_back(i, 0);
            dir.emplace_back(0);
        }
        for (int i = 1; i < height; ++i) {
            pos.emplace_back(width - 1, i);
            dir.emplace_back(1);
        }
        for (int i = width - 2; i >= 0; --i) {
            pos.emplace_back(i, height - 1);
            dir.emplace_back(2);
        }
        for (int i = height - 2; i > 0; --i) {
            pos.emplace_back(0, i);
            dir.emplace_back(3);
        }
        dir[0] = 3;
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx].first, pos[idx].second};
    }
    
    string getDir() {
        if (!moved) {
            return "East";
        }
        return to_dir[dir[idx]];
    }
};


/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
 
 
 /* Official Solution 2 */
 class Robot {
    int w;
    int h;
    int s = 0;

    tuple<int, int, string> getState() {
        if (s < w) {
            return {s, 0, "East"};
        } else if (s < w + h - 1) {
            return {w - 1, s - w + 1, "North"};
        } else if (s < w * 2 + h - 2) {
            return {w * 2 + h - s - 3, h - 1, "West"};
        } else {
            return {0, (w + h) * 2 - s - 4, "South"};
        }
    }

public:
    Robot(int width, int height) : w(width), h(height) {}

    void step(int num) {
        // 由于机器人只能走外圈，那么走 (w+h-2)*2 步后会回到起点
        // 把 s 取模调整到 [1, (w+h-2)*2]，这样不需要特判 s == 0 时的方向
        s = (s + num - 1) % ((w + h - 2) * 2) + 1;
    }

    vector<int> getPos() {
        auto [x, y, _] = getState();
        return {x, y};
    }

    string getDir() {
        return get<2>(getState());
    }
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
 