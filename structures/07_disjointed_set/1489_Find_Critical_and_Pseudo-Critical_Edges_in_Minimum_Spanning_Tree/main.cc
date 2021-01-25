class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;

public:
    DisjointSetUnion(int _n) {
        n = _n;
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
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0;i < edges.size();++i)
        {
            edges[i].emplace_back(i);
        }

        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) { return a[2] < b[2];});

        int minCost = findMinCost(n, edges, -1);
        // cout << minCost << endl;

        vector<vector<int>> res(2);
        for(int i = 0;i < edges.size();++i)
        {
            int curCost = findMinCost(n, edges, i);
            // cout << curCost << endl;
            if(curCost == -1 || curCost > minCost)
            {
                res[0].emplace_back(edges[i][3]);
                continue;
            }

            // 说明不是关键边，那就先把它加入图，cost还是最小，说明是伪关键边
            curCost = findMinCost(n, edges, i, false);
            if(curCost == minCost)
            {
                res[1].emplace_back(edges[i][3]);
            }
        }
        return res;
    }

    int findMinCost(int n, vector<vector<int>>& edges, int idx, bool deleted = true)
    {
        DisjointSetUnion dsu(n);
        int cost = 0, count = 0;

        if(!deleted)
        {
            dsu.unionSet(edges[idx][0], edges[idx][1]);
            cost = edges[idx][2], count = 1;
        }

        for(int i = 0;i < edges.size();++i)
        {
            if(i != idx && dsu.unionSet(edges[i][0], edges[i][1]))
            {
                cost += edges[i][2];
                ++count;
                if(count == n - 1)
                {
                    break;
                }
            }
        }
        return count == n - 1 ? cost : -1;
    }
};