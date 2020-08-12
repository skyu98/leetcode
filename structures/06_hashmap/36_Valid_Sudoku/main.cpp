class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = 9;

        vector<unordered_map<int, int>> row;
        vector<unordered_map<int, int>> col;
        vector<unordered_map<int, int>> box;

        for(int j=0;j<size;++j)
        {
            unordered_map<int, int> tmp;
            row.push_back(tmp);
            col.push_back(tmp);
            box.push_back(tmp);
        }

        for(int i=0;i<size;++i)
        {
            for(int j=0;j<size;++j)
            {
                if(board[i][j] == '.') continue;
                char num_c = board[i][j];
                int num = num_c;

                if(row[i].find(num) != row[i].end()) return false;
                ++row[i][num];

                if(col[j].find(num) != col[j].end()) return false;
                ++col[j][num];

                int box_index = (i/3) * 3 + j/3;
                if(box[box_index].find(num) != box[box_index].end()) return false;
                ++box[box_index][num];
            }
        }
        return true;
    }
};