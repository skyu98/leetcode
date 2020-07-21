class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty()) return;
        int right = s.size()-1, left = 0;
        while(left<right)
        {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
        return;
    }
};