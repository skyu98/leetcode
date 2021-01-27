class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;
    int count;

public:
    DisjointSetUnion(int _n)
        : n(_n),
          count(_n)
    {
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        --count;
        return true;
    }

    const int& getCount() const
    {
        return count;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSetUnion Alice(n), Bob(n);

        // 节点编号改为从 0 开始
        for (auto& edge: edges) {
            --edge[1];
            --edge[2];
        }

        int kEdges = edges.size();
        int count = 0;

       
        for(const auto& edge :edges)
        {
            if(edge[0] == 3)
            {
                if(Alice.unionSet(edge[1], edge[2])
                    && Bob.unionSet(edge[1], edge[2]))
                    ++count;
            }
        }
        // cout << "public over" << endl;

        for(const auto& edge :edges)
        {
            if(edge[0] == 1)
            {
                if(Alice.unionSet(edge[1], edge[2]))
                    ++count;
            }
            if(edge[0] == 2)
            {
                if(Bob.unionSet(edge[1], edge[2]))
                    ++count;
            }  
        }
        // cout << "Alice over" << endl;

    if(Alice.getCount() > 1 || Bob.getCount() > 1)
        return -1;

    return kEdges - count;
    }
};