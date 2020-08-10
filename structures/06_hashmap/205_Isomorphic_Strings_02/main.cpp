class Solution {
private:
    bool _judge(string s, string t){
        if(s == t) return true;
        int size = s.size();
        unordered_map<char, char> map;
        
        for(int i=0;i<size;++i)
        {
            if(map.find(s[i]) == map.end())
            {
                map.insert(make_pair(s[i], t[i]));
            }
            if(map[s[i]] != t[i])
            return false;
        }
        return true;
    }

public:
    bool isIsomorphic(string s, string t) {
        return _judge(s, t) && _judge(t, s);
    }
};