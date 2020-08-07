class MyHashSet {
private:
    int hash_size;
    vector<list<int>> hash_set;    
public:
    /** Initialize your data structure here. */
    MyHashSet():hash_size(769) {
        list<int> tmp;
        for(int i = 0;i<hash_size;++i)
        {
            hash_set.push_back(tmp);
        }
    }
    
    void add(int key) {
        int hash_key = key % hash_size;
        auto res = find(hash_set[hash_key].begin(), hash_set[hash_key].end(), key);
        if(res == hash_set[hash_key].end())
        {
            hash_set[hash_key].push_front(key);
        }
    }
    
    void remove(int key) {
        int hash_key = key % hash_size;
        auto res = find(hash_set[hash_key].begin(), hash_set[hash_key].end(), key);
        if( res != hash_set[hash_key].end())
        {
            hash_set[hash_key].erase(res);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_key = key % hash_size;
        auto res = find(hash_set[hash_key].begin(), hash_set[hash_key].end(), key);
        return res != hash_set[hash_key].end();
       
    }
};