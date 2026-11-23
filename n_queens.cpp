class Solution {
public:
    int isSafe(vector<vector<int>>& mat, int row, int col, int n){
        // check the col on upper side
        int i, j;
        for(i=0; i<row; i++){
            if(mat[i][col]){
                return 0;
            }
        }
        // Check upper diagonal on left side
        for(i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(mat[i][j]){
                return 0;
            }
        }
        // Check upper diagonal on right side
        for(i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(mat[i][j]){
                return 0;
            }
        }
        return 1;
    }


    void placeQueens(int row, vector<vector<int>>& mat, vector<vector<string>>& result, int n){
        
         // base case: If all queens are placed
        if(row == n){
            
            // store current solution
            vector<string> ans;
            for(int i=0; i<n; i++){
                string s = "";
                for(int j=0; j<n; j++){
                    
                    if(mat[i][j]){
                        s.push_back('Q');
                    }
                    else s.push_back('.');
                }
                ans.push_back(s);
            }
            result.push_back(ans);
            return;
        }



        for(int i=0; i<n; i++){

            // Check if the queen can be placed
            if(isSafe(mat, row, i, n)){

                mat[row][i] = 1;
                placeQueens(row + 1, mat, result, n);
                //backtracking
                mat[row][i] = 0;
            }

        }
    }


    vector<vector<string>> nQueens(int n){

        // Initialize the board
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<vector<string>> result;
        
        //Place Queens
        placeQueens(0, mat, result, n);

        return result;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans = nQueens(n);
        return ans;
    }
};
