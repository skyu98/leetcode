class Solution { 
    public:
    void solve(vector<char>& s, int idx, int len){ 
            if(idx ==(len/2)) return;
            char tmp = s[idx];
            s[idx] = s[len- idx -1];
            s[len- idx -1] = tmp;
            solve(s, idx+1, len);
        }
    
    void reverseString(vector<char>& s) { 
            int len = s.size();
            solve(s, 0, len);
        }
};
