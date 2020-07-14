class Solution { 
    private:
    unordered_map<int, int> map;
    public:
    int climbStairs(int n) { 
            if(map[n] != 0) return map[n];
            int res;
            if(n<=2) res = n;
            else
            { 
                        res = climbStairs(n-2) + climbStairs(n-1);      
                    }
            map[n] = res;
            return res;
        }
};
