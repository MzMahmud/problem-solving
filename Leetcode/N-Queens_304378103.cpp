#define ABS(x) ((x) < 0 ? -1 * (x) : (x))

class Solution {
    struct Pos {
        int row, col;
        Pos(int i = 0, int j = 0) : row(i), col(j) {}
    };
    
    vector<string> solution;
    vector<vector<string>> allSoliution;
    vector<Pos> allQueenPos;
    int n;
    
    
    
public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        string initRow = "";
        for(int i = 0;i < n;i++)
            initRow += '.';
        for(int i = 0;i < n;i++)
            solution.push_back(initRow);
        
        findAllSolution();        
        
        return allSoliution;
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
            allSoliution.push_back(solution);
            return;
        }

        for (int row = 0; row < n; row++) {
            if(isValid(Pos(row,col))){
                // put the queen
                solution[row][col] = 'Q';
                allQueenPos.push_back(Pos(row, col));

                findAllSolution(col + 1);

                // take the queen back
                solution[row][col] = '.';
                allQueenPos.pop_back();
            }
        }
    }
};
