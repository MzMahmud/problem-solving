class Solution {
    public void rotate(int[] numbers, int k) {
        int n = numbers.length;
        if (n == 0 || (k = k % n) == 0) {
            return;
        }
        int[] rotatedNumbers = new int[n];
        for (int i = 0; i < n; ++i) {
            int rotatedIndex = (i + k) % n;
            rotatedNumbers[rotatedIndex] = numbers[i];
        }
        for (int i = 0; i < n; ++i) {
            numbers[i] = rotatedNumbers[i];
        }
    }
}
