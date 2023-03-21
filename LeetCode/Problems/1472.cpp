// Time Complexity: std::vector
class BrowserHistory {
public:
    vector<string> history;
    int cur;

    BrowserHistory(string homepage) {
        history.emplace_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        if (cur == history.size() - 1) {
            history.emplace_back(url);
            cur++;
        } else {
            history[++cur] = move(url);
            history.resize(cur + 1);
        }
    }
    
    string back(int steps) {
        cur -= min(steps, cur);
        return history[cur];
    }
    
    string forward(int steps) {
        cur += min(steps, (int) history.size() - 1 - cur);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */