#define ABS(x) ((x) < 0 ? -1 * (x) : (x))

class Solution {
    struct Pos {
        int row, col;
        Pos(int i = 0, int j = 0) : row(i), col(j) {}
    };
    
    vector<Pos> allQueenPos;
    int n;
    int count;
    
    
public:
    int totalNQueens(int _n) {
        n = _n;
        
        count = 0;
        findAllSolution();        
        
        return count;
    }
    

    bool isValid(Pos pos) {
        for (Pos p : allQueenPos) {
            if (pos.row == p.row || pos.col == p.col ||
                ABS(pos.row - p.row) == ABS(pos.col - p.col))
                return false;
        }
        return true;
    }
    
    void findAllSolution(int col = 0) {
        if (col == n) { // found a solution
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if(isValid(Pos(row,col))){
                // put the queen
                allQueenPos.push_back(Pos(row, col));

                findAllSolution(col + 1);

                // take the queen back
                allQueenPos.pop_back();
            }
        }
    }
};
