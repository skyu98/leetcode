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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size = s.size();
        DisjointSet D_Set(size);

        for(auto pair : pairs)
        {
            D_Set.Union(pair[0], pair[1]);
        }

        // for(auto num : D_Set.getSet())
        // {
        //     cout << num << endl;
        // }

        map<int, vector<char>> rootToChars;
        for(int i = 0;i < size;++i)
        {
            int root = D_Set.find(i);
            rootToChars[root].emplace_back(s[i]); // 下标不存在会创建
        }

        for(auto it = rootToChars.begin();it != rootToChars.end();++it)
        {
            auto& vec = it->second;
            sort(vec.begin(), vec.end(), greater<int>());
        }

        for(int i = 0;i < size;++i)
        {
            int root = D_Set.find(i);
            s[i] = rootToChars[root].back();
            rootToChars[root].pop_back();
        }

        return s;

    }
};










