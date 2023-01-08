class Solution {
    private void reverse(int[] numbers, int start, int end) {
        for (; start <= end; ++start, --end) {
            int temp = numbers[start];
            numbers[start] = numbers[end];
            numbers[end] = temp;
        }
    }

    public void rotate(int[] numbers, int k) {
        int n = numbers.length;
        if (n == 0 || (k = k % n) == 0) {
            return;
        }
        reverse(numbers, 0, n - 1);
        reverse(numbers, 0, k - 1);
        reverse(numbers, k, n - 1);
    }
    
    public void rotateOrderNSpace(int[] numbers, int k) {
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
