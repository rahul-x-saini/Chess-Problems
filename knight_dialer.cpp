class Solution {
public:
    int knightDialer(int n) {
        
        const int MOD = 1e9 + 7;

        vector<long long> dp(10, 1);
        while(--n){

            vector<long long> nextDp(10, 0);

             // Knight can reach 0 from digits 4 and 6
            nextDp[0] = (dp[4] + dp[6]) % MOD;

            // Knight can reach 1 from digits 6 and 8
            nextDp[1] = (dp[6] + dp[8]) % MOD;

            // Knight can reach 2 from digits 7 and 9
            nextDp[2] = (dp[7] + dp[9]) % MOD;

            // Knight can reach 3 from digits 4 and 8
            nextDp[3] = (dp[4] + dp[8]) % MOD;

            // Knight can reach 4 from digits 0, 3, and 9
            nextDp[4] = (dp[0] + dp[3] + dp[9]) % MOD;

            // Digit 5 has no valid knight moves

            // Knight can reach 6 from digits 0, 1, and 7
            nextDp[6] = (dp[0] + dp[1] + dp[7]) % MOD;

            // Knight can reach 7 from digits 2 and 6
            nextDp[7] = (dp[2] + dp[6]) % MOD;

            // Knight can reach 8 from digits 1 and 3
            nextDp[8] = (dp[1] + dp[3]) % MOD;

            // Knight can reach 9 from digits 2 and 4
            nextDp[9] = (dp[2] + dp[4]) % MOD;

            dp = nextDp;

        }
        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;

    }
};
