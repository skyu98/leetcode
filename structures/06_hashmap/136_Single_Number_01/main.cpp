class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for(auto num :nums)
        {
            if(set.find(num) == set.end())
            {  
                set.insert(num);
            }
            else
            {
                set.erase(num);
            }
        }
        return *set.begin();
    }
};