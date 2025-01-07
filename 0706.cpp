//706. Design HashMap
/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.
    void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
    int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

 
*/
class MyHashMap {
    private:
    std::vector<int> keys{};
    std::vector<int> values{};
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto it = std::find(keys.begin(),keys.end(),key);
        if(it == keys.end())
        {
            keys.push_back(key);
            values.push_back(value);
        }
        else
        {
            int i = std::distance(keys.begin(),it);
            values[i] = value;
        }
    }
    
    int get(int key) {
        auto it = std::find(keys.begin(),keys.end(),key);
        if(it == keys.end())
        {
            return -1;
        }
        else
        {
            int i = std::distance(keys.begin(),it);
            return values[i];
        }
    }
    
    void remove(int key) {
        auto it = std::find(keys.begin(),keys.end(),key);
        if(it != keys.end())
        {
           int i = std::distance(keys.begin(),it);
           keys.erase(keys.begin()+i);
           values.erase(values.begin()+i);
        }
        
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
