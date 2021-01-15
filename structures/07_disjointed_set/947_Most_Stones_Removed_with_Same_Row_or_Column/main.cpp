class DisjointSet
{
public:
    DisjointSet()
        :set(map<int, int>()),
         rank(map<int, int>()),
         count(0){}
    
    int find(int idx)
    {
        if(set.find(idx) == set.end())
        {
            ++count;
            set[idx] = idx;
            rank[idx] = 1;
            return set[idx];
        }

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

        --count;
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

    const int& getCount() const
    {
        return count;
    }

private:
    map<int, int> set;
    map<int, int> rank;
    int count;
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet set;

        for(const auto& cordinate : stones)
        {
            set.Union(cordinate[0] + 10000, cordinate[1]);
        }

        int res = stones.size() - set.getCount();

        return res;
    }
};