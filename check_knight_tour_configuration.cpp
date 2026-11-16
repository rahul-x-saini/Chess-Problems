class Solution {
public:
    int Kdir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
  
    pair<int, int> isValidStep(vector<vector<int>>& grid, int i, int j, int step){
        int n = grid.size();

        for(auto& [dx, dy] : Kdir){
            int x = i + dx;
            int y = j + dy;

            if (x < 0 || x >= n || y < 0 || y >= n){
                continue;
            }

            if(grid[x][y] == step){
                return {x, y};
            }
        }
        return {-1, -1};
    }
  
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0){
            return false;
        }

        int n = grid.size();

        int i = 0;
        int j = 0;

        for(int step = 1; step < n * n; step++){
            auto [x, y] = isValidStep(grid, i, j, step);

            if(x == -1 && y == -1){
                return false;
            }

            i = x;
            j = y;
        }
        return true;
    }
};
