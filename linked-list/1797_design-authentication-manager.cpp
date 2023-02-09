struct Node {   
public:
    int expire;
    string key;
    Node *prev;
    Node *next;

    Node(int expire_) : expire(expire_), prev(nullptr), next(nullptr) {
    }

    Node(int expire_, string key_) : expire(expire_), key(key_), prev(nullptr), next(nullptr) {
    }

    Node(int expire_, string key_, Node *prev_, Node *next_) : expire(expire_), key(key_), prev(prev_), next(next_) {
    }
};

class AuthenticationManager {
private:
    int timeToLive;
    Node *head;
    Node *tail;
    unordered_map<string, Node*> mp;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
        this->head = new Node(-1);
        this->tail = new Node(-1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    
    void generate(string tokenId, int currentTime) {
        Node *node = new Node(currentTime + timeToLive, tokenId);
        mp[tokenId] = node;
        Node *last = tail->prev;
        last->next = node;
        node->prev = last;
        tail->prev = node;
        node->next = tail;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp.count(tokenId) && mp[tokenId]->expire > currentTime) {
            Node *node = mp[tokenId];
            Node *prev = node->prev;
            Node *next = node->next;
            prev->next = next;
            next->prev = prev;
            node->expire = currentTime + timeToLive;
            Node *last = tail->prev;
            last->next = node;
            node->prev = last;
            tail->prev = node;
            node->next = tail;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        while (head->next->expire > 0 && head->next->expire <= currentTime) {
            Node *node = head->next;
            mp.erase(node->key);
            head->next = node->next;
            node->next->prev = head;
            delete node;
        }
        return mp.size();
    }
};

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        this->liveTime = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        this->tokenInfo[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        int start = tokenInfo[tokenId];
        
        if (start + liveTime <= currentTime) {
            return;
        }
        
        tokenInfo[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for (auto& [_, start] :tokenInfo) {
            if (start + liveTime > currentTime) {
                cnt++;
            }
        }
        return cnt;
    }
private:
    int liveTime;
    unordered_map<string, int> tokenInfo;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
 
 class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> mp;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (mp.count(tokenId) && mp[tokenId] > currentTime) {
            mp[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto &[_, time] : mp) {
            if (time > currentTime) {
                res++;
            }
        }
        return res;
    }
};
