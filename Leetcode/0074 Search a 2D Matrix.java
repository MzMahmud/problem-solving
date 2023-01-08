class Solution {    
    public boolean searchMatrix(int[][] sortedMatrix, int target) {
        if (sortedMatrix.length == 0) {
            return false;
        }
        int nRows = sortedMatrix.length, nCols = sortedMatrix[0].length;
        int lo = 0, hi = nRows * nCols - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int row = mid / nCols;
            int col = mid - row * nCols;
            if(sortedMatrix[row][col] == target) {
                return true;
            } else if (sortedMatrix[row][col] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
}
