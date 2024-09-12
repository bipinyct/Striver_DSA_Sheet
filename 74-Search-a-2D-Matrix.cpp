class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row*col-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(matrix[mid/col][mid%col] == target) return true;

            if(matrix[mid/col][mid%col] < target){
                low = mid+1;
            }

            else{
                high = mid -1;
            }
        }

        return false;
        
    }
};

// int row = matrix.size();
        // int col = matrix[0].size();

        // for(int i =0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         if(matrix[i][j] == target)
        //             return true;
        //     }
        // }
        // return false;