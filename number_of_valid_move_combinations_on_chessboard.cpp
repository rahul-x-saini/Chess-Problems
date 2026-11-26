class Solution {
private:
    int ans = 0;

public:

    bool isValid(vector<vector<int>>& positions, const vector<pair<int,int>>& direction_combination, vector<int>& steps){

        int maxTime = *max_element(steps.begin(), steps.end());

        int n = positions.size();
        for(int t = 0; t <= maxTime; t++){

            for(int i = 0; i < n - 1; i++){

                int r1 = positions[i][0] + direction_combination[i].first * min(t, steps[i]);
                int c1 = positions[i][1] + direction_combination[i].second * min(t, steps[i]);

                for(int j = i + 1; j < n; j++){

                    int r2 = positions[j][0] + direction_combination[j].first * min(t, steps[j]);
                    int c2 = positions[j][1] + direction_combination[j].second * min(t, steps[j]);

                    if(r1 == r2 && c1 == c2){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void generate_combinations_for_directions_combination(vector<vector<int>>& positions, int i, vector<pair<int, int>>& destinationCombination, vector<int>& steps, const vector<pair<int, int>>& dir_comb, set<pair<int, int>>& seen_destination, set<vector<pair<int, int>>>& seen){

        if(i == positions.size()){
            if(isValid(positions, dir_comb, steps)){
                if(seen.insert(destinationCombination).second){
                    ans++;
                }
            }
            return;
        }

        int r = positions[i][0];
        int c = positions[i][1];

        auto [dx, dy] = dir_comb[i];

        for(int s = 0; ; s++){

            int nr = r + dx * s;
            int nc = c + dy * s;

            if(nr < 1 || 8 < nr || nc < 1 || 8 < nc) break;

            if(seen_destination.count({nr, nc})) continue;

            seen_destination.insert({nr, nc});
            steps.push_back(s);
            destinationCombination.push_back({nr, nc});

            generate_combinations_for_directions_combination(positions, i + 1, destinationCombination, steps, dir_comb, seen_destination, seen);

            destinationCombination.pop_back();
            steps.pop_back();
            seen_destination.erase({nr, nc});

        }
    }

    void Generate_Destination_combinations(vector<vector<int>>& positions, set<vector<pair<int, int>>>& seen, vector<vector<pair<int, int>>>& Direction_Combinations){

        vector<int> steps;
        set<pair<int, int>> seen_destination;
        vector<pair<int, int>> destinationCombination;

        for(const vector<pair<int, int>>& dir_comb : Direction_Combinations){

            generate_combinations_for_directions_combination(positions, 0, destinationCombination, steps, dir_comb, seen_destination, seen);
        }
    }

    void Generate_Direction_Combinations(vector<string>& pieces, int i, vector<pair<int, int>>& path, vector<vector<pair<int, int>>>& Direction_Combinations, const unordered_map<string, vector<pair<int, int>>>& Kpiece_To_kDirs){

        if(i == pieces.size()){
            Direction_Combinations.push_back(path);
            return;
        }

        for(const pair<int, int>& move_dir : Kpiece_To_kDirs.at(pieces[i])){

            path.push_back(move_dir);
            Generate_Direction_Combinations(pieces, i + 1, path, Direction_Combinations, Kpiece_To_kDirs);
            path.pop_back();

        }
    }

    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {

        ans = 0;
        
        const unordered_map<string, vector<pair<int, int>>> Kpiece_To_kDirs{
            {"rook", {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}},
            {"bishop", {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
            {"queen", {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}}
        };

        vector<vector<pair<int, int>>> Direction_Combinations;
        vector<pair<int, int>> path;

        Generate_Direction_Combinations(pieces, 0, path, Direction_Combinations, Kpiece_To_kDirs);

        set<vector<pair<int, int>>> seen;
        Generate_Destination_combinations(positions, seen, Direction_Combinations);

        return ans;

    }
};
