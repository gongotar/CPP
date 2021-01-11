class Trie {
    struct pretree_t {
        struct pretree_t *children[26];
        bool end = false;
        pretree_t () {
            for (int i = 0; i<26; i++) {
                children[i] = nullptr;
            }
        }
    } *pretree;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        pretree = new pretree_t ();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct pretree_t *pt = pretree;
        
        uint8_t d;
        
        for (int i=0; i<word.size(); i++) {
            d = word[i] - 'a';
            if (!(pt->children[d])) {
                pt->children[d] = new pretree_t ();
            }
            pt = pt->children[d];
        }
        pt->end = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct pretree_t *pt = pretree;
        uint8_t d;
        
        for (int i=0; i<word.size(); i++) {
            d = word[i] - 'a';
            if (!(pt->children[d])) {
                return false;
            }

            pt = pt->children[d];
        }
        return (pt && pt->end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct pretree_t *pt = pretree;
        uint8_t d;
        
        for (int i=0; i<prefix.size(); i++) {
            d = prefix[i] - 'a';
            if (!(pt->children[d])) {
                return false;
            }
            pt = pt->children[d];
        }
        return true;    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
