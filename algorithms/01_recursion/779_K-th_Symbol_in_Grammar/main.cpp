class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1) return 0;
        double mid = pow(2.0, N-2);
        if(K <= mid) return kthGrammar(N-1, K);
        return 1-kthGrammar(N-1, K-mid);
    }
};