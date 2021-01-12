class Solution {
private:
    vector<int> topSort(vector<int>& inDegree, const vector<vector<int>>& edges, const vector<int>& items)
    {
        queue<int> q;
        vector<int> res;
        for(auto& i : items)
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
        return res.size() == items.size() ? res : vector<int>{};
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupToItem(n + m, vector<int>());
        
        vector<int> groupInDeg(n + m, 0);
        vector<int> itemInDeg(n, 0);

        // graph
        vector<vector<int>> groupEdges(n + m, vector<int>());
        vector<vector<int>> itemEdges(n, vector<int>());
        
        int moreGroupId = m;
        for(int i = 0;i < n;++i)
        {
            if(group[i] == -1)
            {
                group[i] = moreGroupId++;
            }
            groupToItem[group[i]].emplace_back(i);
        }

        vector<int> id;
        for(int i = 0;i < moreGroupId;++i)
        //for(int i = 0;i < n + m;++i)
        {
            id.emplace_back(i);
        }


        // 建立组间关系和组内关系
        for(int i = 0;i < n;++i)
        {   
            int curGroupId = group[i];   // i：当前物体    curGroupId：当前物体所属组号
            for(auto& item :beforeItems[i])
            {   
                int beforeGroupId = group[item];  // item：前驱物体    curGroupId：前驱物体所属组号
                if(curGroupId != beforeGroupId)
                {
                    groupEdges[beforeGroupId].emplace_back(curGroupId);
                    ++groupInDeg[curGroupId];
                }
                else
                {
                    itemEdges[item].emplace_back(i);
                    ++itemInDeg[i];
                }
            }
        }

        vector<int> sortedGroup = topSort(groupInDeg, groupEdges, id);
        if(sortedGroup.size() == 0)
            return {};

        vector<int> res;
        for(auto& curGroupId : sortedGroup)
        {
            if(groupToItem[curGroupId].empty())
                continue;

            vector<int> sortedItem = topSort(itemInDeg, itemEdges, groupToItem[curGroupId]);
            if (sortedItem.size() == 0)
                return vector<int>{};

            for(auto& item : sortedItem)
            {
                res.emplace_back(item);
            }
        }

        return res;
    }
};