class Solution {
public:

    int hash(int x, int y){
        return x * 8 + y;
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        unordered_set<int> queens_positions;

        for(vector<int>& queen : queens){
            queens_positions.insert(hash(queen[0], queen[1]));
        }

        vector<vector<int>> ans;
        vector<vector<int>> directions{{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

        for(vector<int>& d : directions){
            for(int i = king[0] + d[0], j = king[1] + d[1]; 0 <= i && i < 8 && 0 <= j && j < 8; i += d[0], j += d[1]){
                if(queens_positions.contains(hash(i, j))){
                    ans.push_back({i, j});
                    break;
                }
            }
        }

        return ans;

    }
};
