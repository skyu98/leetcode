class DisjointSet
{
public:
    DisjointSet(int size)
        :set(vector(size, 0)),
         rank(vector(size, 1))
    {
        for(int i = 0;i< size;++i)
        {
            set[i] = i;
        }
    }
    
    int find(int idx)
    {
        if(set[idx] != idx)
        {
            set[idx] = find(set[idx]);
        }
        return set[idx];
    }

    void Union(int i, int j)
    {
        int x = find(i);
        int y = find(j);

        if(x == y)
            return;

        if(rank[x] == rank[y])
        {
            set[x] = y;
            ++rank[y];
        }
        else if(rank[x] < rank[y])
        {
            set[x] = y;
        }
        else
        {
            set[y] = x;
        } 
    }

    vector<int>& getSet()
    {
        return set;
    }

private:
    vector<int> set;
    vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 在一棵树中，边的数量比节点的数量少1
        int size = edges.size();
        DisjointSet set(size);

        for(const auto & edge : edges)     // 对于每一条边
        {
            int idx_0 = edge[0]-1, idx_1 = edge[1]-1;
            if(set.find(idx_0) != set.find(idx_1))   // 如果该边的两点不是连通的，那么加入这条边没问题
            {
                set.Union(idx_0, idx_1);
            }
            else    // 如果已经连通了，再加入这条边就形成环了
            {
                return edge;
            }
        }
        return {};
    }
};









