class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, start=0;
        for(i=0;i<nums1.size();i++)
        {
            int low = start, high = nums2.size()-1, mid;
            if(low >= nums2.size()) break;
            while(low<=high)
            {
                mid = low + ((high-low)>>1);
                
                if(nums2[mid] >= nums1[i])
                {
                    if(mid == 0 || nums2[mid-1] < nums1[i])
                    {
                        break;
                    }                    
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            if(nums2[mid] == nums1[i])
            {
                res.push_back(nums1[i]);
                start = mid + 1; 
            }
            else
            {
                start = mid; 
            }
        }
        return res;
    }
};