/* Original Solution 1 */
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        matrix = move(vector<vector<int>>(rows, vector<int>(cols, 0)));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        
        matrix[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
                
    }
    
    int getValue(string formula) {
        size_t pos = formula.find('+');
        const size_t start = 1;
        int firstVal = getValCell(formula.substr(start, pos - start));
        int secondVal = getValCell(formula.substr(pos + 1));
        
        return firstVal + secondVal;
    }
    
    int getValCell(string&& cell) {
        if (isdigit(cell[0])) {
            return stoi(cell);
        }
        
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        
        return matrix[row][col];
    }
    
    static const int cols = 26;
    vector<vector<int>> matrix;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
 
/* Original Solution 2 */ 
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        ptr = new arrPtr[rows];
        this->rows = rows;
        for (int row = 0; row < rows; row++) {
            ptr[row] = reinterpret_cast<arrPtr>(new int[cols] {0});
        }
    }

    ~Spreadsheet() {
        for (int row = 0; row < rows; row++) {
            delete [] ptr[row];
        }

        delete [] ptr;
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        int *p = reinterpret_cast<int*>(ptr[row]);
        p[col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);

    }

    int getValFromCell(string&& cell) {
        if (isdigit(cell[0])) {
            return stoi(cell);
        }

        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        int *p = reinterpret_cast<int*>(ptr[row]);


        return p[col];
    }

    int getValue(string formula) {
        size_t pos = formula.find('+');
        const size_t start = 1;

        int sum = getValFromCell(formula.substr(start, pos - start));
        sum += getValFromCell(formula.substr(pos + 1));

        return sum;

    }

    static const int cols = 26;
    typedef int (*arrPtr)[cols];
    arrPtr *ptr;
    int rows;
};

/* Original Solution 3 */
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        sPtr = make_shared<int[][cols]>(rows, {0});
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sPtr[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);

    }

    int getValFromCell(string&& cell) {
        if (isdigit(cell[0])) {
            return stoi(cell);
        }

        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        return sPtr[row][col];
    }

    int getValue(string formula) {
        size_t pos = formula.find('+');
        const size_t start = 1;

        int sum = getValFromCell(formula.substr(start, pos - start));
        sum += getValFromCell(formula.substr(pos + 1));

        return sum;

    }

    static const int cols = 26;
    shared_ptr<int[][cols]> sPtr;
};

/* Official Solution 1 */
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        this->grid = vector<vector<int>>(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value) {
        auto [x, y] = getPos(cell);
        grid[x][y] = value;
    }
    
    void resetCell(string cell) {
        auto [x, y] = getPos(cell);
        grid[x][y] = 0;
    }
    
    int getValue(string formula) {
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return getCellVal(cell1) + getCellVal(cell2);
    }

private:
    vector<vector<int>> grid;

    pair<int, int> getPos(const string &cell) {
        int x = stoi(cell.substr(1));
        int y = cell[0] - 'A';
        return {x, y};
    }

    int getCellVal(string &cell) {
        if (isalpha(cell[0])) {
            auto [x, y] = getPos(cell);
            return grid[x][y];
        } else {
            return stoi(cell);
        }
    }
};
