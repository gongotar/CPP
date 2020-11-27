class LRUCache {
private:
    unordered_map<int, int> cache;
    unordered_set<int> in_queue;
    unordered_map<int,int> deferred;
    queue<int> used_queue;
    int limit;

    void use(int key) {
        unordered_set<int>::iterator f = in_queue.find(key);
        if (f != in_queue.end()) {     // key is in queue
            unordered_map<int,int>::iterator ff = deferred.find(key);
            if (ff != deferred.end()) {
                ff->second ++;
            }
            else {
                deferred.insert(make_pair(key, 1));
            }
        }
        else {
            in_queue.insert(key);
        }
        used_queue.push(key);
    }

    int last_used() {

        int key = used_queue.front();

        unordered_map<int,int>::iterator f = deferred.find(key);
        while (f != deferred.end()) { // key is used before, ignore and get next key
            if (f->second > 1) {
                f->second --;
            }
            else if (f->second == 1){
                deferred.erase(f);
            }
            used_queue.pop();

            key = used_queue.front();
            f = deferred.find(key);
        }
        unordered_set<int>::iterator ff = in_queue.find(key);
        in_queue.erase(ff);
        used_queue.pop();
        return key;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
    }

    int get(int key) {
        unordered_map<int,int>::iterator f = cache.find(key);
        if (f == cache.end()) {
            return -1;
        }
        use(key);
        return f->second;

    }

    void put(int key, int value) {
        unordered_map<int, int>::iterator f = cache.find(key);
        use(key);

        if (f != cache.end()) {  // if found, update
            f->second = value;
        }
        else if (cache.size() < limit) {    // if not exceeding limit, insert
            cache.insert(make_pair(key, value));

        }
        else {  // if limit exceeded, remove last used, insert
            int lkey = last_used();
            f = cache.find(lkey);
            cache.erase(f);

            cache.insert(make_pair(key, value));

        }

    }
};
