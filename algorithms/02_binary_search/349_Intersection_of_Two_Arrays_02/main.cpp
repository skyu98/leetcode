class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        
        unordered_set<int> set;
        unordered_set<int> nums(nums1.begin(), nums1.end());

        for(auto num : nums2)
        {
            if(nums.count(num) == 1)
            {
                set.insert(num);
            }
        }
        
        for(auto num : set)
        {
            res.push_back(num);
        }
        
        return res;
    }
};