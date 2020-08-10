class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> res;

        for(int i=0;i<list1.size();++i)
        {
            map.insert(make_pair(list1[i], i));
        }

        int index_sum = list1.size() + list2.size();
        for(int i=0;i<list2.size() && i <= index_sum;++i)
        {
            if(map.find(list2[i]) != map.end())
            {
                if(i + map[list2[i]] < index_sum)
                {
                    index_sum = i + map[list2[i]];
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if(i + map[list2[i]] == index_sum)
                {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};