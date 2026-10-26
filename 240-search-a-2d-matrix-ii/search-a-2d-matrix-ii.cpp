class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int row = matrix.size() , col = matrix[0].size();
        //row limit
        // int low = 0 , high = col-1;
        // while(low<=high){
        //     int mid = low + (high-low)/2;
        //     if(matrix[0][mid] == target){
        //         low = mid;
        //         break;
        //     }
        //     if(matrix[0][mid] < target) low = mid+1;
        //     else high = mid-1;
        // }
        // int rowLimit = low;
        //col limit
        // low = 0 , high = row-1;
        // while(low<=high){
        //     int mid = low + (high-low)/2;
        //     if(matrix[0][mid] == target){
        //         low = mid;
        //         break;
        //     }
        //     if(matrix[mid][0] <= target) low = mid+1; 
        //     else high = mid-1;
        // }
        // int colLimit = low;
        //search

        // for(int i = 0 ; i <= rowLimit ; i++){
        //     for(int j = 0 ; j <= colLimit ; j++){
        //         if(matrix[i][j]==target) return true;
        //     }
        // }
        // return false;


        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0 ; i < row ;i++){
            for(int j = 0 ; j < col ; j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;

    }
};