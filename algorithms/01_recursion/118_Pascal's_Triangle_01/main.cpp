class Solution { 
public:
int solve(int i, int j){ 
        if(j==0 || j==i) return 1;
        return solve(i-1, j-1)+solve(i-1,j);
    }

vector<vector<int>> generate(int numRows) { 
        vector<vector<int>> res;
        if(numRows == 0) return res;
        for(int i = 0;i<numRows;i++)
        { 
            vector<int> tmp;
            for(int j=0; j<=i;j++)
            { 
                tmp.push_back(solve(i, j));
            }
            res.push_back(tmp);
        }
        return res;
    }
};
