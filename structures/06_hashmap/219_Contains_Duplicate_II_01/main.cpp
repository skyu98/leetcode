class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0) return false;

        unordered_multimap<int, int> map;
        for(int i=0;i<nums.size();i++)
        {
            map.insert(make_pair(nums[i], i));
        }

        for(int i=0;i<nums.size();i++)
        {
            int cur = nums[i];
            auto it = map.find(cur);
            if( it!= map.end())
            {
                int count = map.count(cur);
                while(count > 0)
                {
                    if(abs(it->second - i) <= k && abs(it->second - i) >=1)  return true;
                    ++it;
                    --count;
                }
            }
        }
        return false;
    }       
};