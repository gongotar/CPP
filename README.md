# Sample algorithmic codes in C++

## LRU 

Least recent used cache argorithm:

- `LRUCache(int capacity)` Initialize the LRU cache with positive size capacity.
- `int get(int key)` Return the value of the key if the key exists, otherwise return `-1`.
- `void put(int key, int value)` Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

**Complexity:**
`get` and `put` in `O(1)` time complexity.

## LFU

Least Frequently Used (LFU) cache:

- `LFUCache(int capacity)` Initializes the object with the capacity of the data structure.
- `int get(int key)` Gets the value of the key if the key exists in the cache. Otherwise, returns `-1`.
- `void put(int key, int value)` Sets or inserts the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be evicted.

**Complexity:**
both operations in `O(1)` time complexity.


## BSTIterator

`BSTIterator` class that represents an iterator over the *in-order* traversal of a binary search tree (BST)

- `BSTIterator(TreeNode root)` Initializes an object of the BSTIterator class. The root of the `BST` is given as part of the constructor.
- `boolean hasNext()` Returns `true` if there exists a number in the traversal to the right of the pointer, otherwise returns `false`.
- `int next()` Moves the pointer to the right, then returns the number at the pointer.

**Complexity:** `next()` and `hasNext()` run in average `O(1)` time and use `O(h)` memory, where h is the height of the tree.

## Trie (Prefix Tree)

Implement a trie with `insert`, `search`, and `startsWith` methods.
**Example:**
```cpp
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
```
