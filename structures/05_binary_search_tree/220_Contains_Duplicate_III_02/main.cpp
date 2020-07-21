class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for(int i=0;i<nums.size();++i)
        {
            auto lower = s.lower_bound(nums[i]);
            if(lower != s.end() && *lower <= long(nums[i]) + long(t)) return true;
            auto upper = s.upper_bound(nums[i]);
            // upper 为 s.begin()时说明查找结果为空
            if(upper != s.begin() && (long(nums[i]) - long(t)) <= *--upper ) return true; 
            s.insert(long(nums[i]));
            if(s.size()>k) s.erase(long(nums[i-k]));
        }
        return false;
    }
};