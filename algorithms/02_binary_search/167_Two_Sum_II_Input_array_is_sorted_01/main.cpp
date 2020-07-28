class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.size() < 2) return res;
        
        for(int i=0;i<numbers.size();++i)
        {
            int low = i + 1, high= numbers.size()-1, the_num = target - numbers[i];
            if(low >= numbers.size()) break;
            while(low<=high)
            {
                int mid = low + ((high - low)>>1);
                if(numbers[mid] == the_num)
                {
                    res.push_back(i+1);
                    res.push_back(mid + 1);
                    return res;
                }
                else if(numbers[mid] < the_num)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            
        }
        return res;
    }
};