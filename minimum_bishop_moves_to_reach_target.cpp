class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        
        // Check if they lie on the same main diagonal
        if((source[0] + source[1]) == (target[0] + target[1])) return 1;

        // Check if they lie on the same anti-diagonal
        if((source[0] - source[1]) == (target[0] - target[1])) return 1;

        // check squares color
        if((source[0] + source[1]) % 2 != (target[0] + target[1]) % 2) return -1;
        
        // Otherwise, reachable in 2 moves
        return 2;
    }
};
