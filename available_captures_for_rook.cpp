class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        
        int sr, sc = 0;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    sr = i;
                    sc = j;
                }
            }
        }

        int ans = 0;
        for(vector<int>& d : vector<vector<int>>({{0, -1}, {0, 1}, {-1, 0}, {1,0}})){
            for(int i = sr + d[0], j = sc + d[1]; 0 <= i && i < 8 && 0 <= j && j < 8; i += d[0], j += d[1]){
                if(board[i][j] == 'p') ans++;
                if(board[i][j] != '.') break;
            }
        }

        return ans;
    }
};
