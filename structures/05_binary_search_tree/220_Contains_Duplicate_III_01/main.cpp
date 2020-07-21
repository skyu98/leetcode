class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i=0;i<nums.size();++i)
        {
            for(int j=1;j<=k && (i+j)<nums.size();++j)
            {
                if(abs(long(nums[i]) - long(nums[i+j]))<=t)
                {
                    return true;
                }    
            }
        }
        return false;
    }
};