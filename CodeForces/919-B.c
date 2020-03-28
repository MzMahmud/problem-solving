#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main() {
    int k;
    scanf("%d", &k);
    int n = 0;
    while (k) {
        if (sum_of_digits(++n) == 10)
            k--;
    }
    printf("%d\n", n);
    return 0;
}