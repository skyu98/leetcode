class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_multimap<string, string> map;
        for(int i=0;i<strs.size();++i)
        {
            string cur = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map.insert(make_pair(strs[i], cur));
        }

        vector<vector<string>> res;
        auto it = map.begin();
        while(it != map.end())
        {
            string cur_key = it->first;
            vector<string> tmp;
            while(it != map.end() && it->first == cur_key)
            {
                tmp.push_back(it->second);
                ++it;
            }
            res.push_back(tmp);
        }

        return res;
    }
};