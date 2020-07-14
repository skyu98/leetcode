class Solution {
public:
    vector<int> getRow(int rowIndex) {
        queue<vector<int>> q;
        vector<int> first;
        first.push_back(1);
        q.push(first);

        for(int i = 0;i<=rowIndex;i++)
        {
            vector<int> tmp;
            vector<int> last = q.front();
            q.pop();
            
            for(int j=0; j<=i;j++)
            {
                if(j==0 || j==i) tmp.push_back(1);
                else
                {
                    tmp.push_back(last[j-1] + last[j]);
                }
            }
            q.push(tmp);
        }
        return q.front();
    }
};
