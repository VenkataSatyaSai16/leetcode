class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        vector<vector<bool>> row(9,vector<bool>(10,false)) , col(9,vector<bool>(10,false)) , box(9,vector<bool>(10,false));

        // for(int i = 0 ; i < 9 ; i++){
        //     for(int j = 0 ; j < 9 ; j++){
        //         int rowNum = i/3;
        //         int colNum = j/3;
        //         int boxNum = rowNum*3 + colNum ;
        //         cout<<boxNum<<" ";
        //     }
        //     cout<<"\n";
        // }

        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '0';

                if(row[i][num]||col[j][num]) return false;

                int rowNum = i/3;
                int colNum = j/3;
                int boxNum = rowNum*3 + colNum ;
                if(box[boxNum][num]) return false;
            
                row[i][num] = true;
                col[j][num] = true;
                box[boxNum][num] = true;
            }
        }
        return true;
    }
};