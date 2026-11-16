class Solution {
public:

    double calculate_prob(int n, int k, int row, int col, int (&dx)[8], int (&dy)[8], vector<vector<vector<double>>>& dp){

        if(row < 0 || row >= n || col < 0 || col >= n){
            return 0.0;
        }

        if(k == 0) return 1.0;

        if(dp[row][col][k] != -1) return dp[row][col][k];

        double ans = 0.0;
        for(int i = 0; i < 8; i++){
            ans += calculate_prob(n, k-1, row + dx[i], col + dy[i], dx, dy, dp) / 8.0;
        }

        return dp[row][col][k] = ans;

    }

    double knightProbability(int n, int k, int row, int col) {

        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));

        return calculate_prob(n, k, row, col, dx, dy, dp);
    }
};
