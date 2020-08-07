class MyHashMap {
private:
    int hash_size;
    vector<list<pair<int, int>>> map;

public:
    /** Initialize your data structure here. */
    MyHashMap() : hash_size(769) {
        list<pair<int, int>> tmp;
        for(int i = 0;i< hash_size; ++i)
        {
            map.push_back(tmp);
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash_key = key % hash_size;
        auto position = map[hash_key].begin();
        while(position != map[hash_key].end() && position->first != key)
        {
            ++position;
        }
        if(position == map[hash_key].end())
        {
            map[hash_key].push_front(make_pair(key, value));
        }
        else
        {
            position->second = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash_key = key % hash_size;
        auto position = map[hash_key].begin();
        while(position != map[hash_key].end() && position->first != key)
        {
            ++position;
        }
        if(position == map[hash_key].end())
        {
            return -1;
        }
        else
        {
            return position->second;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash_key = key % hash_size;
        auto position = map[hash_key].begin();
        while(position != map[hash_key].end() && position->first != key)
        {
            ++position;
        }
        if(position != map[hash_key].end() && position->first == key)
        {
            map[hash_key].erase(position);
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