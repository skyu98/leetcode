class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto num: nums)
        {
            ++m[num];
        }

        multimap<int, int> map;
        auto it = m.begin();
        while(it != m.end())
        {
            if(map.size() == k)
            {
                if(it->second > (map.begin())->first)
                {
                    map.erase(map.begin());
                    map.insert(make_pair(it->second, it->first));
                }
            }
            else
            {
                map.insert(make_pair(it->second, it->first));
            }
            ++it;
        }

        vector<int> res;
        auto iterator = map.end();
        for(int i=0;i<k;++i)
        {
            --iterator;
            res.push_back(iterator->second);
        }
        return res;
    }
};