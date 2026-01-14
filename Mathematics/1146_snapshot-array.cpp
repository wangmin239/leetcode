class SnapshotArray {
public:
    SnapshotArray(int length): snap_cnt(0), data(length) {}
    
    void set(int index, int val) {
        data[index].emplace_back(snap_cnt, val);
    }
    
    int snap() {
        return snap_cnt++;
    }
    
    int get(int index, int snap_id) {
        auto x = upper_bound(data[index].begin(), data[index].end(), pair{snap_id + 1, -1});
        return x == data[index].begin() ? 0 : prev(x)->second;
    }

private:
    int snap_cnt;
    vector<vector<pair<int, int>>> data;
};





class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr = new int[length];
        
        for (int i = 0; i < length; i++) {
            arr[i] = 0;
        }
        snapId = 0;
        len = length;
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        snapMap[snapId] = new int[len];
        for (int i = 0; i < len; i++) {
            snapMap[snapId][i] = arr[i];
        }
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        return snapMap[snap_id][index];
    }
    
    int snapId;
    int* arr;
    unordered_map<int, int*> snapMap;
    int len;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */