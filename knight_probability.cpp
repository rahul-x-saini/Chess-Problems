class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<double>> curr(n, vector<double>(n, 0.0));
        curr[row][column] = 1.0;

        vector<int> dx = {-2, -2, -1, 1, 2, 2, 1, -1};
        vector<int> dy = {-1, 1, 2, 2, 1, -1, -2, -2};

        for(int step = 0; step < k; step++){
            
            vector<vector<double>> next(n, vector<double>(n, 0.0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(curr[i][j] == 0.0){
                        continue;
                    }
                    for(int d = 0; d < 8; d++){
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if(0 <= ni && ni < n && 0 <= nj && nj < n){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                    }
                }
            }
            curr = move(next);
        }

        double total_probability = 0.0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                total_probability += curr[i][j];
            }
        }

        return total_probability;
    }
};
