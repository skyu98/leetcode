class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size(), size_2 = nums2.size();
        if(nums1 < nums2) return intersection(nums2, nums1);
        unordered_set<int> set;
        unordered_set<int> intersect;

        for(auto num : nums1)
        {
            set.insert(num);
        }
        for(auto num : nums2)
        {
            if(set.count(num) == 1)
            {
                intersect.insert(num);
            }
        }
        vector<int> res (intersect.begin(), intersect.end());
        return res; 
    }
};