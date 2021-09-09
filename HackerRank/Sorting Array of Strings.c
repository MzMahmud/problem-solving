#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)

int lexicographic_sort(const char *a, const char *b) {
    int len_a   = strlen(a);
    int len_b   = strlen(b);
    int min_len = MIN(len_a, len_b);
    for (int i = 0; i < min_len; ++i)
        if (a[i] != b[i])
            return a[i] - b[i];
    return len_a - len_b;
}

int lexicographic_sort_reverse(const char *a, const char *b) {
    return -lexicographic_sort(a, b);
}

#define SIZE 1 << 8
int get_inque_count(const char *a) {
    int count[SIZE] = {};
    int len         = strlen(a);
    for (int i = 0; i < len; ++i)
        ++count[(int)a[i]];
    int unique_count = 0;
    for (int i = 0; i < SIZE; ++i)
        unique_count += (count[i] != 0);
    return unique_count;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
    int inque_count_a = get_inque_count(a);
    int inque_count_b = get_inque_count(b);
    if (inque_count_a != inque_count_b)
        return inque_count_a - inque_count_b;
    return lexicographic_sort(a, b);
}

int sort_by_length(const char *a, const char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a != len_b)
        return len_a - len_b;
    return lexicographic_sort(a, b);
}

void string_sort(char **arr, const int len,
                 int (*cmp_func)(const char *a, const char *b)) {
    char *temp;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                temp   = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
