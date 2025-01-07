//705. Design HashSet
/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

    void add(key) Inserts the value key into the HashSet.
    bool contains(key) Returns whether the value key exists in the HashSet or not.
    void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

*/

class MyHashSet {
    private:
    std::unordered_set<int> hash{};
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        hash.insert(key);
    }
    
    void remove(int key) {
        hash.erase(key);
    }
    
    bool contains(int key) {
        return hash.count(key) > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
