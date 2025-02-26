/* Original Solution */
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curId = 0;
    }
    
    void visit(string url) {
        history.resize(curId + 1);
        history.push_back(url);
        curId = history.size() - 1;
    }
    
    string back(int steps) {
        if (steps > curId) {
            curId = 0;
        } else {
            curId -= steps;
        }
        
        return history[curId];
    }
    
    string forward(int steps) {
        if (steps + curId >= history.size()) {
            curId = history.size() - 1;
        } else {
            curId += steps;
        }
        
        return history[curId];
    }
    
    vector<string> history;
    int curId;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
 
 
/* Official Solution */ 
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        this->urls.push_back(homepage);
        this->currIndex = 0;
    }
    
    void visit(string url) {
        while (urls.size() > currIndex + 1) {
            urls.pop_back();
        }
        urls.push_back(url);
        this->currIndex++;
    }
    
    string back(int steps) {
        currIndex  = max(currIndex - steps, 0);
        return urls[currIndex];
    }
    
    string forward(int steps) {
        currIndex = min(currIndex + steps, int(urls.size() - 1));
        return urls[currIndex];
    }
private:
    vector<string> urls;
    int currIndex;
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
