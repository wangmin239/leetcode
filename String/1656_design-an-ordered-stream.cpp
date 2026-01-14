class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
        arr = new pii[n];
        size = n + 1;
        
        for (int i = 0; i < n; i++) {
            arr[i] = make_pair(-1, "");
        }
    }
    
    vector<string> insert(int idKey, string value) {
        
        vector<string> ans;
        
        arr[idKey - 1] = make_pair(idKey, value);
        
        if (idKey != ptr) {
            return ans;
        }

        for (int index = ptr; index < size; index++) {
            if (arr[index - 1].first == -1) {
                ptr = index;
                break;
            }
            ans.push_back(arr[index - 1].second);

        }

        return ans;
    }
private:
    int ptr;
    int size;
    using pii = pair<int, string>;
    pii* arr;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
 
 class OrderedStream {
public:
    OrderedStream(int n) {
        stream.resize(n + 1);
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> res;
        while (ptr < stream.size() && !stream[ptr].empty()) {
            res.push_back(stream[ptr]);
            ++ptr;
        }
        return res;
    }

private:
    vector<string> stream;
    int ptr;
};
