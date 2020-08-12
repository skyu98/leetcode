class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto num: nums)
        {
            ++m[num];
        }

        vector<vector<int>> buckets(nums.size() + 1);
        auto it = m.begin();
        while(it != m.end())
        {
            int index = it->second;
            buckets[index].push_back(it->first); 
            ++it;
        }

        vector<int> res;
        for(int i=buckets.size()-1;i>=0 && res.size() < k;--i)
        {
            if(buckets[i].empty()) continue;
            for(int j=0;j<buckets[i].size();++j) res.push_back(buckets[i][j]);
        }
        return res;
    }
};