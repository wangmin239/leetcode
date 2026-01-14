class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> direc {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direcIndex = 0;
        int x = 0, y = 0;
        for (char instruction : instructions) {
            if (instruction == 'G') {
                x += direc[direcIndex][0];
                y += direc[direcIndex][1];
            } else if (instruction == 'L') {
                direcIndex += 3;
                direcIndex %= 4;
            } else {
                direcIndex++;
                direcIndex %= 4;
            }
        }
        return direcIndex != 0 || (x == 0 && y == 0);
    }
};

class Solution {
public:
    typedef enum {
        North,
        West,
        South,
        East,
    } Direction;
    
    class Position {
    public:
        pair<int, int> point;
        Direction direction;
        Position(pair<int, int> _point, Direction dir) : point(_point), direction(dir) {}
    };
    bool isRobotBounded(string instructions) {
        Position curPos(make_pair(0, 0), North);
        int diff = 0;;

        for (char ch : instructions) {
            if (ch == 'L') {
                ++diff;
                continue;
            }
            
            if (ch == 'R') {
                --diff;
            }
        }
        diff = abs(diff);
        diff %= 4;
        
        if (diff == 1 || diff = 3) {
            return true;
        }
        
        for (char ch : instructions) {
            switch(ch) {
                case 'G':
                    move(curPos);
                    break;
                case 'L':
                    rotateLeft(curPos);
                    left++;
                    break;
                case 'R':
                    rotateRight(curPos);
                    right++;
                    break;
            }
        }

        if (diff == 0) {
            return curPos.point == make_pair(0, 0);
        }
        
        if (diff = 2) {
            curPos.direction == South;
        }
        
        return false; 
    }
    
    void move(Position& pos) {
        switch (pos.direction) {
            case North:
                pos.point.second += 1;
                break;
            case West:
                pos.point.first -= 1;
                break;
            case South:
                pos.point.second -= 1;
                break;
            case East:
                pos.point.first += 1;
                break;
        }
        
    }
    
    void rotateLeft(Position& pos) {
        switch (pos.direction) {
            case North:
                pos.direction = West;
                break;
            case West:
                pos.direction = South;
                break;
            case South:
                pos.direction = East;
                break;
            case East:
                pos.direction = North;
                break;
        }
    }
    void rotateRight(Position& pos) {
        switch (pos.direction) {
            case North:
                pos.direction = East;
                break;
            case West:
                pos.direction = North;
                break;
            case South:
                pos.direction = West;
                break;
            case East:
                pos.direction = South;
                break;
        }
    }    

};