class Solution {
private:
    bool isValid;

    void DfstopSort(int cur, vector<int>& visited, const vector<vector<int>>& edges, vector<int>& res)
    {
        visited[cur] = 1; // 搜索中
        for(auto& item : edges[cur])
        {
            if(visited[item] == 1)
            {
                isValid = false;
                return;
            }
            if(visited[item] == 0)
            {
                DfstopSort(item, visited, edges, res);
                if(!isValid)
                    return;
            }
        }

        visited[cur] = 2;
        res.emplace_back(cur);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
       
        vector<int> visited(numCourses, 0);
        vector<int> res;
        isValid = true;

        for(auto& pair : prerequisites)
        {
            edges[pair[1]].emplace_back(pair[0]);  // 有1->0的边
        }

        for(int i = 0;i < numCourses && isValid;++i)
        {
            if(visited[i] == 0)
                DfstopSort(i, visited, edges, res);
        }

        if(!isValid)
            return {};
        
        reverse(res.begin(), res.end());
        return res;
    }
};