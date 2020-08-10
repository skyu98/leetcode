class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == t) return true;
        int size = s.size();
    
        for(int i=0;i<size;++i)
        {
            if(s.find(s[i]) != t.find(t[i]))
            {
                return false;
            }
        }
        return true;
    }
};