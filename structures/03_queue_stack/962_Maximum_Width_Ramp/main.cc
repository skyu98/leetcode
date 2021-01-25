class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int size = A.size();

        for(int i = 0;i < size;++i)
        {
            if(s.empty() || A[s.top()] > A[i])
                s.push(i);
        }

        int res = 0;
        for(int idx = size - 1;idx >= 0;--idx)
        {
            while(!s.empty() && A[idx] >= A[s.top()])
            {
                int curRes = idx - s.top();
                res = max(res, curRes);
                s.pop();
            }
        }
        
        return res;
    }
};