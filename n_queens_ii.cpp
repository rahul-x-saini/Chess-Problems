class Solution {
public:
    int isSafe(vector<vector<int>>& mat, int row, int col, int n) {

        int i, j;

        // Check the col on upper side
        for (i = 0; i < row; i++){
            if (mat[i][col]){
                return 0;
            }
        }

        // Check upper diagonal on left side
        for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if (mat[i][j]){
                return 0;
            }
        }

        // Check upper diagonal on right side
        for (i = row-1, j = col+1; j < n && i >= 0; i--, j++){
            if (mat[i][j]){
                return 0;
            }
        }

        return 1;
    }
    
    void placeQueens(int row, vector<vector<int>>& mat, int& result, int n){

        // base case: If all queens are placed
        if(row == n){
            result++;
            return;
        }

        for(int i=0; i<n; i++){

            // Check if the queen can be placed
            if(isSafe(mat, row, i, n)){
                mat[row][i] = 1;
                placeQueens(row+1, mat, result, n);

                //backtracking
                mat[row][i] = 0;
            }
        }
    }

    int nQueens(int n) {

        // Initialize the board
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int result = 0;

        // Place queens
        placeQueens(0, mat, result, n);

        return result;
    }



    int totalNQueens(int n) {
        int ans = nQueens(n);
        return ans;
    }
};
