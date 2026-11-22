class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

        // Case 0: the rook is in the same row as the queen.
        if(a == e){
            // the bishop blocks the rook or not.
            return (c == a && (b < d && d < f || b > d && d > f)) ? 2 : 1;
        }

        // Case 1: the rook is in the same column as the queen.
        if(b == f){
            // the bishop blocks the rook or not.
            return (d == b && (a < c && c < e || a > c && c > e)) ? 2 : 1;
        }

         // Case 2: the bishop is in the same main-diagonal as the queen.
         if(c + d == e + f){
            // the rook blocks the bishop or not.
            return (a + b == c + d && (c < a && a < e || c > a && a > e)) ? 2 : 1;
         }

         // Case 3: the bishop is in the same cross-diagonal as the queen.
         if(c - d == e - f){
            // the rook blocks the bishop or not.
            return (a - b == c - d && (c < a && a < e || c > a && a > e)) ? 2 : 1;
         }

         // Otherwise
         return 2;

    }
};
