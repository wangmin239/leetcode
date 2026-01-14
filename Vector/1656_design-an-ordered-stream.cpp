
class OrderedStream {
public:
    OrderedStream(int n) {
        uniq = make_unique<string[]>(n);
        head = ptr = uniq.get();
        fill_n(ptr, n, "");
        num = n;
    }
    
    vector<string> insert(int idKey, string value) {
        if (ptr - head != idKey - 1) {
            head[idKey - 1] = value;
            return {};
        }
        
        string *first = ptr;
        
        *ptr = value;
        while (ptr < head + num && *ptr != "") {
            ++ptr;
        }

        return vector<string>(first, ptr);
    }
    unique_ptr<string[]> uniq;
    string *ptr, *head;
    int num;
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
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */