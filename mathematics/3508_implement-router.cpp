/* Original Solution 1 */
class Router {
public:
    function<int(tuple<int, int, int>)> hash = [&](const tuple<int, int, int>& packet) {
        return ::hash<unsigned long long >{}(get<2>(packet));
    };
    
    function<bool(tuple<int, int, int>, tuple<int, int, int>)> comp = [&](const auto& lhs, const auto& rhs) {
        return lhs == rhs;
    }; 
    
    queue<tuple<int, int, int>> packetQue;
    unordered_map<int, vector<int>> destPack;
    unordered_set<tuple<int, int, int>, decltype(hash), decltype(comp)> packetSet;
    int packetCnt;
    
    Router(int memoryLimit) {
        packetCnt = memoryLimit;
        unordered_set<tuple<int, int, int>, decltype(hash), decltype(comp)> tmp(packetCnt, hash, comp);
        packetSet = ::move(tmp);
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto newPacket = make_tuple(source, destination, timestamp);
        
        if (packetSet.count(newPacket) > 0) {
            return false;
        }
        
        int curPacketCnt = packetQue.size();
        
        if (packetCnt == curPacketCnt) {
           forwardPacket();
        }
            
        packetQue.emplace(source, destination, timestamp);
        packetSet.insert(::move(newPacket));
        destPack[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetQue.empty() == true) {
            return {};
        }
        
        auto&& popPacket = packetQue.front();
        auto& ids = destPack[get<1>(popPacket)];

        vector<int> packInfo {get<0>(popPacket), get<1>(popPacket), get<2>(popPacket)};
        ids.erase(ids.begin());
        packetSet.erase(popPacket);
        packetQue.pop();
        return packInfo;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (destPack.count(destination) == 0) {
            return 0;
        }
        
        auto&& packets = destPack[destination];
        auto startIter = lower_bound(packets.begin(), packets.end(), startTime);
        auto endIter = upper_bound(packets.begin(), packets.end(), endTime);
        
        return endIter - startIter ;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
 
 
 
 
/* Original Solution 2 */
class Router {
public:
    Router(int memoryLimit) {
        unordered_set<pair<int, int>, decltype(hash), decltype(comp)> tmp(0, hash, comp);
        packetCnt = memoryLimit;
        curTimeStamp = 0;
        packetSet = tmp;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto packetId = make_pair(source, destination);
        
        if (curTimeStamp == timestamp && packetSet.count(packetId) > 0) {
            return false;
        }

        if (curTimeStamp < timestamp) {
            curTimeStamp = timestamp;
            packetSet.clear();
        }

        
        int curPacketCnt = packetQue.size();
        
        if (packetCnt == curPacketCnt) {
            auto&& dropPacket = packetQue.front();
            auto& ids = destPack[dropPacket.second];
            int dropTime = ids.front();
            
            if (dropTime == curTimeStamp) {
                packetSet.erase(dropPacket);
            }
            ids.erase(ids.begin());
            packetQue.pop();
        }
            
        packetQue.emplace(source, destination);
        destPack[destination].push_back(timestamp);
        packetSet.insert(packetId);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetQue.empty() == true) {
            return {};
        }
        
        auto&& popPacket = packetQue.front();
        auto& ids = destPack[popPacket.second];
        int popTime = ids.front();
        
        if (popTime == curTimeStamp) {
            packetSet.erase(popPacket);
        }
        vector<int> packInfo {get<0>(popPacket), get<1>(popPacket), ids.front() };
        ids.erase(ids.begin());
        packetQue.pop();
        return packInfo;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (destPack.count(destination) == 0) {
            return 0;
        }
        
        auto&& packets = destPack[destination];
        auto startIter = lower_bound(packets.begin(), packets.end(), startTime);
        auto endIter = upper_bound(packets.begin(), packets.end(), endTime);
        
        return endIter - startIter ;
    }
    function<int(pair<int, int>)> hash = [&](const pair<int, int>& packet) {
        return ::hash<int>{}(packet.first | (static_cast<unsigned long long>(packet.second) << 18));
    };
    
    function<bool(pair<int, int>, pair<int, int>)> comp = [&](const auto& lhs, const auto& rhs) {
        return lhs == rhs;
    };
    
    queue<pair<int, int>> packetQue;
    unordered_map<int, vector<int>> destPack;
    unordered_set<pair<int, int>, decltype(hash), decltype(comp)> packetSet;
    int packetCnt;
    int curTimeStamp;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
 
 
 
/* Official Solution 1 */
class Router {
public:
    int memLimit = 0;
    int length = 0;
    set<tuple<int, int, int>> isExist;
    unordered_map<int, deque<int>> sameDestQue;
    deque<tuple<int, int, int>> que;

    Router(int memoryLimit) { memLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> packet =
            make_tuple(source, destination, timestamp);
        if (isExist.contains(packet)) {
            return false;
        }
        if (length == memLimit) {
            forwardPacket();
        }
        length++;
        que.push_back(packet);
        sameDestQue[destination].push_back(timestamp);
        isExist.insert(packet);
        return true;
    }

    vector<int> forwardPacket() {
        vector<int> data;
        if (!que.empty()) {
            tuple<int, int, int> packet = que.front();
            que.pop_front();
            data = vector<int>{get<0>(packet), get<1>(packet), get<2>(packet)};
            isExist.erase(packet);
            sameDestQue[data[1]].pop_front();
            length--;    
        }
        return data;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto pos1 = lower_bound(sameDestQue[destination].begin(),
                                sameDestQue[destination].end(), startTime);
        auto pos2 = upper_bound(sameDestQue[destination].begin(),
                                sameDestQue[destination].end(), endTime);
        return pos2 - pos1;
    }
};
