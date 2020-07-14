class Solution {
private:
    unordered_map<int, int> map;
public:
    int fib(int N) {
        if(map[N] != 0) return map[N];
        int res;
        if(N<2)  res = N;
        else{
            res = fib(N-1) + fib(N-2); 
        }
        map[N] = res;
        return res;
    }
};
