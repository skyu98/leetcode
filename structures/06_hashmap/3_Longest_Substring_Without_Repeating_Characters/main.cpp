class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size(); 

        unordered_map<char, int> map;
        int len = 0, max_len = 0, i=0, begin = 0;
        while(begin < s.size() && i<s.size())
        {
            char c = s[i];
            if(map.find(c) != map.end() && map[c] >= begin)
            {
                if(max_len < len) max_len = len;
                begin = map[c] + 1;
                len = i - begin + 1;
            }
            else
            {
                ++len;
            } 
            map[c] = i;
            ++i;
        }
        if(max_len < len) max_len = len;
        return max_len;
    }
};