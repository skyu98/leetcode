class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> map;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end()) return false;
        nums.push_back(val);
        map[val] = nums.size() -1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;
        
        int index = map[val];
        int tail = nums.back();
        nums[index] = tail;
        map[tail] = index;
        nums.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand()%(nums.size());
        return nums[index];
    }
};
