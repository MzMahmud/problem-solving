class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int totalElements = matrix.length * matrix[0].length;
        List<Integer> spiral = new ArrayList<>();
        int directionIndex = 0;
        int[] position = {0, 0}; 
        while(spiral.size() < totalElements) {
            if(isValidPosition(position, matrix)) {
                spiral.add(markVisitedAndGetValue(matrix, position));
            }
            var nextPosition = getPosition(position, DIRECTIONS[directionIndex]);
            if(isValidPosition(nextPosition, matrix)) {
                position = nextPosition;
            } else {
                directionIndex = (directionIndex + 1) % DIRECTIONS.length;
            }
        }
        return spiral;
    }
    
    private static final int[][] DIRECTIONS = {
        { 0, 1},
        { 1, 0},
        { 0,-1},
        {-1, 0}
    };

    private static final int VISITED_MARKER = 101;

    private static int[] getPosition(int[] position, int[] direction) {
        return new int[] {
            position[0] + direction[0],
            position[1] + direction[1],
        };
    }

    private static boolean isValidPosition(int[] position, int[][] matrix) {
        int i = position[0], j = position[1];
        return (0 <= i && i < matrix.length)
               && (0 <= j && j < matrix[0].length)
               && (matrix[i][j] != VISITED_MARKER);
    }

    public static int markVisitedAndGetValue(int[][] matrix, int[] position) {
        int i = position[0], j = position[1];
        int value = matrix[i][j];
        matrix[i][j] = VISITED_MARKER;
        return value;
    }
}
