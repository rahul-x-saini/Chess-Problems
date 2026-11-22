class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        
        // Case 0: Already at the target
        if(source == target) return 0;

        // Case 1: target is in the queens range
        if(source[0] == target[0] || source[1] == target[1] || abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;

        // otherwise
        return 2;


    }
};
