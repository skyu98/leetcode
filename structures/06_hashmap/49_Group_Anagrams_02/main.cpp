class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i=0;i<strs.size();++i)
        {
            string cur = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(cur);
        }

        vector<vector<string>> res;
        auto it = map.begin();
        while(it != map.end())
        {
            res.push_back(it->second);
            ++it;
        }

        return res;
    }
};