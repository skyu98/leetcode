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

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y)
        : len(len), 
          x(x),
          y(y) 
    {}

    bool operator <(const Edge& rhs)
    {
        return len < rhs.len;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        DisjointSetUnion dsu(size);

        auto dist = [&](int x, int y) -> int
        {
            return abs(points[x][0] - points[y][0]) +
                    abs(points[x][1] - points[y][1]);
        };

        vector<Edge> Edges;
        for(int i = 0;i < size;++i)
        {
            for(int j = i + 1;j < size;++j)
            {
                Edges.emplace_back(dist(i, j), i, j);
            }
        }

        sort(Edges.begin(), Edges.end());

        int minCost =0, count = 0;
        for(auto& [len, i, j] : Edges)
        {
            if(dsu.unionSet(i, j))
            {
                minCost += len;
                ++count;
                if(count == size)
                    break;
            }
        }
        return minCost;
    }
};