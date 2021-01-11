class LFUCache {
    struct lfulist {
        struct lfulist *prev;
        struct lfulist *next;
        int16_t val;
        int16_t key;
        int freq;
        
        lfulist () : prev (nullptr), next (nullptr) {}
        lfulist (int16_t key, int16_t val) : key (key), val (val), freq (0), prev (nullptr), next (nullptr) {}

        lfulist (int16_t key, int16_t val, struct lfulist *prev, struct lfulist *next) : key (key), val (val), prev (prev), next (next), freq (0) {}
    };
    
    struct lfulist *head, *tail;
    unordered_map <int16_t, struct lfulist *> lfu;
    
    int16_t capacity;

    
    void remove_head () {
        struct lfulist *prev = head->prev;
        prev->prev->next = head;
        head->prev = prev->prev;
        lfu.erase (prev->key);        
        delete prev;
    }
    
    void move_up (struct lfulist *item) {
        struct lfulist *prev = item->prev;
        
        while (prev!=tail && item->freq >= prev->freq) {      
            prev = prev->prev;
        }
                
        // old place updates
        item->next->prev = item->prev;
        item->prev->next = item->next;
        
        // new place updates
        item->prev = prev;
        item->next = prev->next;
        prev->next->prev = item;
        prev->next = item;
    }
    
    void insert (struct lfulist *item) {
        struct lfulist *prev = head->prev;
        
        while (prev!=tail && item->freq >= prev->freq) {      
            prev = prev->prev;
        }
        
        item->prev = prev;
        item->next = prev->next;
        prev->next->prev = item;
        prev->next = item;
        
        lfu.insert (make_pair (item->key, item));

    }
public:
    LFUCache(int capacity) : capacity (capacity) {
        head = new lfulist ();
        tail = new lfulist ();
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        unordered_map <int16_t, struct lfulist *>::iterator it = lfu.find (key);
        if (it != lfu.end()) {
            it->second->freq ++;
            move_up(it->second);
            return it->second->val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        unordered_map <int16_t, struct lfulist *>::iterator it = lfu.find (key);
        if (it != lfu.end()) {
            it->second->freq ++;
            it->second->val = value;
            move_up(it->second);
        }
        else {
            
            if (capacity == 0) return;
            if (lfu.size() >= capacity) {
                remove_head ();
            }
            struct lfulist *newitem = new lfulist (key, value);
            insert (newitem);
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
