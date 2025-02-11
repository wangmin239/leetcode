

/* Official Solution */
static const int MOUSE_TURN = 0, CAT_TURN = 1;
static const int UNKNOWN = 0, MOUSE_WIN = 1, CAT_WIN = 2;
static const int MAX_MOVES = 1000;

class Solution {
public: 
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols;
    vector<string> grid;
    int catJump, mouseJump;
    int food;
    int degrees[64][64][2];
    int results[64][64][2][2];

    bool canMouseWin(vector<string> grid, int catJump, int mouseJump) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        this->grid = grid;
        this->catJump = catJump;
        this->mouseJump = mouseJump;
        int startMouse = -1, startCat = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char c = grid[i][j];
                if (c == 'M') {
                    startMouse = getPos(i, j);
                } else if (c == 'C') {
                    startCat = getPos(i, j);
                } else if (c == 'F') {
                    food = getPos(i, j);
                }
            }
        }
        int total = rows * cols;
        memset(degrees, 0, sizeof(degrees));
        memset(results, 0, sizeof(results));
        queue<tuple<int, int, int>> qu;
        // 计算每个状态的度
        for (int mouse = 0; mouse < total; mouse++) {
            int mouseRow = mouse / cols, mouseCol = mouse % cols;
            if (grid[mouseRow][mouseCol] == '#') {
                continue;
            }
            for (int cat = 0; cat < total; cat++) {
                int catRow = cat / cols, catCol = cat % cols;
                if (grid[catRow][catCol] == '#') {
                    continue;
                }
                degrees[mouse][cat][MOUSE_TURN]++;
                degrees[mouse][cat][CAT_TURN]++;
                for (auto & dir : dirs) {
                    for (int row = mouseRow + dir[0], col = mouseCol + dir[1], jump = 1; row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != '#' && jump <= mouseJump; row += dir[0], col += dir[1], jump++) {
                        int nextMouse = getPos(row, col), nextCat = getPos(catRow, catCol);
                        degrees[nextMouse][nextCat][MOUSE_TURN]++;
                    }
                    for (int row = catRow + dir[0], col = catCol + dir[1], jump = 1; row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != '#' && jump <= catJump; row += dir[0], col += dir[1], jump++) {
                        int nextMouse = getPos(mouseRow, mouseCol), nextCat = getPos(row, col);
                        degrees[nextMouse][nextCat][CAT_TURN]++;
                    }
                }
            }
        }
        // 猫和老鼠在同一个单元格，猫获胜
        for (int pos = 0; pos < total; pos++) {
            int row = pos / cols, col = pos % cols;
            if (grid[row][col] == '#') {
                continue;
            }
            results[pos][pos][MOUSE_TURN][0] = CAT_WIN;
            results[pos][pos][MOUSE_TURN][1] = 0;
            results[pos][pos][CAT_TURN][0] = CAT_WIN;
            results[pos][pos][CAT_TURN][1] = 0;
            qu.emplace(pos, pos, MOUSE_TURN);
            qu.emplace(pos, pos, CAT_TURN);
        }
        // 猫和食物在同一个单元格，猫获胜
        for (int mouse = 0; mouse < total; mouse++) {
            int mouseRow = mouse / cols, mouseCol = mouse % cols;
            if (grid[mouseRow][mouseCol] == '#' || mouse == food) {
                continue;
            }
            results[mouse][food][MOUSE_TURN][0] = CAT_WIN;
            results[mouse][food][MOUSE_TURN][1] = 0;
            results[mouse][food][CAT_TURN][0] = CAT_WIN;
            results[mouse][food][CAT_TURN][1] = 0;
            qu.emplace(mouse, food, MOUSE_TURN);
            qu.emplace(mouse, food, CAT_TURN);
        }
        // 老鼠和食物在同一个单元格且猫和食物不在同一个单元格，老鼠获胜
        for (int cat = 0; cat < total; cat++) {
            int catRow = cat / cols, catCol = cat % cols;
            if (grid[catRow][catCol] == '#' || cat == food) {
                continue;
            }
            results[food][cat][MOUSE_TURN][0] = MOUSE_WIN;
            results[food][cat][MOUSE_TURN][1] = 0;
            results[food][cat][CAT_TURN][0] = MOUSE_WIN;
            results[food][cat][CAT_TURN][1] = 0;
            qu.emplace(food, cat, MOUSE_TURN);
            qu.emplace(food, cat, CAT_TURN);
        }
        // 拓扑排序
        while (!qu.empty()) {
            auto [mouse, cat, turn] = qu.front();
            qu.pop();
            int result = results[mouse][cat][turn][0];
            int moves = results[mouse][cat][turn][1];
            vector<tuple<int, int, int>> prevStates = getPrevStates(mouse, cat, turn);
            for (auto [prevMouse, prevCat, prevTurn] : prevStates) {
                if (results[prevMouse][prevCat][prevTurn][0] == UNKNOWN) {
                    bool canWin = (result == MOUSE_WIN && prevTurn == MOUSE_TURN) || (result == CAT_WIN && prevTurn == CAT_TURN);
                    if (canWin) {
                        results[prevMouse][prevCat][prevTurn][0] = result;
                        results[prevMouse][prevCat][prevTurn][1] = moves + 1;
                        qu.emplace(prevMouse, prevCat, prevTurn);
                    } else {
                        degrees[prevMouse][prevCat][prevTurn]--;
                        if (degrees[prevMouse][prevCat][prevTurn] == 0) {
                            int loseResult = prevTurn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
                            results[prevMouse][prevCat][prevTurn][0] = loseResult;
                            results[prevMouse][prevCat][prevTurn][1] = moves + 1;
                            qu.emplace(prevMouse, prevCat, prevTurn);
                        }
                    }
                }
            }
        }
        return results[startMouse][startCat][MOUSE_TURN][0] == MOUSE_WIN && results[startMouse][startCat][MOUSE_TURN][1] <= MAX_MOVES;
    }
    
    vector<tuple<int, int, int>> getPrevStates(int mouse, int cat, int turn) {
        vector<tuple<int, int, int>> prevStates;
        int mouseRow = mouse / cols, mouseCol = mouse % cols;
        int catRow = cat / cols, catCol = cat % cols;
        int prevTurn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;
        int maxJump = prevTurn == MOUSE_TURN ? mouseJump : catJump;
        int startRow = prevTurn == MOUSE_TURN ? mouseRow : catRow;
        int startCol = prevTurn == MOUSE_TURN ? mouseCol : catCol;
        prevStates.emplace_back(mouse, cat, prevTurn);
        for (auto & dir : dirs) {
            for (int i = startRow + dir[0], j = startCol + dir[1], jump = 1; i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != '#' && jump <= maxJump; i += dir[0], j += dir[1], jump++) {
                int prevMouseRow = prevTurn == MOUSE_TURN ? i : mouseRow;
                int prevMouseCol = prevTurn == MOUSE_TURN ? j : mouseCol;
                int prevCatRow = prevTurn == MOUSE_TURN ? catRow : i;
                int prevCatCol = prevTurn == MOUSE_TURN ? catCol : j;
                int prevMouse = getPos(prevMouseRow, prevMouseCol);
                int prevCat = getPos(prevCatRow, prevCatCol);
                prevStates.emplace_back(prevMouse, prevCat, prevTurn);
            }
        }
        return prevStates;
    }

    int getPos(int row, int col) {
        return row * cols + col;
    }
};


/* AI Solution */
class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int rows = grid.size();
        int cols = grid[0].size();
        pair<int, int> cat, mouse, food;
        // 找到猫、老鼠和食物的初始位置
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 'C') {
                    cat = {i, j};
                } else if (grid[i][j] == 'M') {
                    mouse = {i, j};
                } else if (grid[i][j] == 'F') {
                    food = {i, j};
                }
            }
        }
        // 四个方向：上、下、左、右
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // 状态队列，存储 (老鼠位置, 猫位置, 步数, 轮到谁行动)
        queue<tuple<pair<int, int>, pair<int, int>, int, bool>> q;
        // 记录已经访问过的状态
        set<tuple<pair<int, int>, pair<int, int>, int, bool>> visited;
        q.push({mouse, cat, 0, true});
        visited.insert({mouse, cat, 0, true});
        while (!q.empty()) {
            auto [mousePos, catPos, steps, isMouseTurn] = q.front();
            q.pop();
            // 检查是否满足游戏结束条件
            if (mousePos == catPos || catPos == food || steps >= 1000) {
                continue;
            }
            if (mousePos == food) {
                return true;
            }
            int currentJump = isMouseTurn ? mouseJump : catJump;
            auto currentPos = isMouseTurn ? mousePos : catPos;
            // 可以选择停留在原地
            auto newState = make_tuple(isMouseTurn ? mousePos : currentPos, isMouseTurn ? catPos : currentPos, steps + 1, !isMouseTurn);
            if (visited.find(newState) == visited.end()) {
                visited.insert(newState);
                q.push(newState);
            }
            // 尝试向四个方向跳跃
            for (const auto& [dx, dy] : directions) {
                for (int jump = 1; jump <= currentJump; ++jump) {
                    int newX = currentPos.first + dx * jump;
                    int newY = currentPos.second + dy * jump;
                    // 检查是否越界或碰到墙
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != '#') {
                        auto newPos = make_pair(newX, newY);
                        auto newMouse = isMouseTurn ? newPos : mousePos;
                        auto newCat = isMouseTurn ? catPos : newPos;
                        auto newState = make_tuple(newMouse, newCat, steps + 1, !isMouseTurn);
                        if (visited.find(newState) == visited.end()) {
                            visited.insert(newState);
                            q.push(newState);
                        }
                    } else {
                        // 如果碰到墙，就不用再继续往这个方向跳了
                        break;
                    }
                }
            }
        }
        return false;
    }
};