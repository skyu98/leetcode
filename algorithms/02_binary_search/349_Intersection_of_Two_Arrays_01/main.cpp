class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, start=0;
        for(i=0;i<nums1.size();i++)
        {
            if(i>0 && nums1[i]==nums1[i-1]) continue;
            int low = start, high = nums2.size()-1;
            while(low<=high)
            {
                int mid = low +((high-low)>>1);
                if(nums2[mid] == nums1[i])
                {
                    res.push_back(nums1[i]);
                    break;
                }
                else if(nums2[mid] < nums1[i])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if(low >= nums2.size()) break;
            start = low; 
        }
        return res;
    }
};