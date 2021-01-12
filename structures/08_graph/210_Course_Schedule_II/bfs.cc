class Solution {
private:
    vector<int> topSort(vector<int>& inDegree, const vector<vector<int>>& edges, int numOfItem)
    {
        queue<int> q;
        vector<int> res;
        for(int i = 0;i < numOfItem;++i)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int curItem = q.front();
            q.pop();
            res.push_back(curItem);
            for(auto& item: edges[curItem])
            {
                if(--inDegree[item] == 0)
                {
                    q.push(item);
                }
            }
        }
        return res.size() == numOfItem ? res : vector<int>{};
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);

        for(auto& pair : prerequisites)
        {
            edges[pair[1]].emplace_back(pair[0]);  // 有1->0的边
            ++inDegree[pair[0]];    // 相应增加0的入度
        }

        return topSort(inDegree, edges, numCourses);
    }
};