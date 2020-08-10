class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == t) return true;
        int size = s.size();
        unordered_map<char, char> map;
        unordered_set<char> seen;
        
        for(int i=0;i<size;++i)
        {
            if(map.find(s[i]) == map.end())
            {
                if(seen.count(t[i])==0)
                {
                    map.insert(make_pair(s[i], t[i]));
                    seen.insert(t[i]);
                }
                else return false;
            }
            if(map[s[i]] != t[i])
            return false;
        }
        return true;
    }
};
