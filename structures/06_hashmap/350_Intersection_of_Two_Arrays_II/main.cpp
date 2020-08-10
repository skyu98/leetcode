class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size(), size_2 = nums2.size();
        if(size_1 > size_2) return intersect(nums2, nums1);
        unordered_map<int, int> map;
        vector<int> intersection;

        for(auto num : nums1)
        {
            ++map[num];
        }
        for(auto num : nums2)
        {
            if(map[num] > 0)
            {
                intersection.push_back(num);
                map[num]--;
            }
        }
        return intersection; 
    }
};