class Solution {
public:

    bool isNotNumericCell(int i, int j){
        return i == 3 && (j == 0 || j == 2);
    }

    int knightDialer(int n) {
        
        const int MOD = 1e9 + 7;
        const int kDirs[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

        vector<vector<int>> dp(4, vector<int>(3, 1));
        dp[3][0] = dp[3][2] = 0;

        for(int k = 0; k < n - 1; k++){
            vector<vector<int>> nextDp(4, vector<int>(3, 0));

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 3; j++){
                    if(isNotNumericCell(i, j)) continue;
                    for(auto& [dx, dy] : kDirs){

                        int x = i + dx;
                        int y = j + dy;

                        if(x < 0 || x >= 4 || y < 0 || y >= 3) continue;
                        if(isNotNumericCell(x, y)) continue;

                        nextDp[i][j] = (nextDp[i][j] + dp[x][y]) % MOD;

                    }
                }
            }

            dp = std::move(nextDp);
        }

        int ans = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                ans = (ans + dp[i][j]) % MOD;
            }
        }
        return ans;

    }
};
