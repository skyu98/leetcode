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
    int regionsBySlashes(vector<string>& grid) {
        int kGrids = grid.size();
        int kAreas = 4 * kGrids *kGrids;

        DisjointSetUnion dsu(kAreas);
        for(int i = 0;i < kGrids;++i)
        {
            string& curRow = grid[i];
            for(int j = 0;j < kGrids;++j)
            {
                int idx_area = 4 * (i * kGrids + j);
                char curGrid = curRow[j];
                switch(curGrid)
                {
                    case '/':
                        dsu.unionSet(idx_area, idx_area + 3);
                        dsu.unionSet(idx_area + 1, idx_area + 2);
                        break;
                    case '\\':
                        dsu.unionSet(idx_area, idx_area + 1);
                        dsu.unionSet(idx_area + 2, idx_area + 3);
                        break;
                    case ' ':
                        dsu.unionSet(idx_area, idx_area + 1);
                        dsu.unionSet(idx_area + 1, idx_area + 2);
                        dsu.unionSet(idx_area + 2, idx_area + 3);
                        break;
                    default:
                        break;
                }
                if(j < kGrids - 1)
                    dsu.unionSet(idx_area + 1, 4 * (i * kGrids + j + 1) + 3);
                if(i < kGrids - 1)
                   a dsu.unionSet(idx_area + 2, 4 * ((i + 1) * kGrids + j));
            }
        }

        return dsu.getCount();
    }
};