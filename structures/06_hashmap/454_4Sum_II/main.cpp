class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        for(auto a : A)
        {
            for(auto b : B)
            {
                int sum = a + b;
                ++map[sum];
            }
        }

        int count =0;
        for(auto c : C)
        {
            for(auto d : D)
            {
                int sum = c + d;
                if(map.find(-sum) != map.end()) count += map[-sum];
            }
        }
        return count;
    }
};