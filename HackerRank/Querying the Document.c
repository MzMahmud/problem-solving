#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char ***kth_paragraph(char ****document, int k) { return document[k - 1]; }

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m) {
    return kth_paragraph(document, m)[k - 1];
}

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n) {
    return kth_sentence_in_mth_paragraph(document, m, n)[k - 1];
}

void w_init(char **w, int *w_len) {
    *w     = (char *)malloc(MAX_CHARACTERS * sizeof(char));
    *w_len = 0;
}

void s_init(char ***s, int *s_len) {
    *s     = (char **)malloc(MAX_CHARACTERS * sizeof(char *));
    *s_len = 0;
}

void p_init(char ****p, int *p_len) {
    *p     = (char ***)malloc(MAX_CHARACTERS * sizeof(char **));
    *p_len = 0;
}

void d_init(char *****d, int *d_len) {
    *d     = (char ****)malloc(MAX_PARAGRAPHS * sizeof(char ***));
    *d_len = 0;
}

char ****get_document(char *text) {
    char *w;
    int w_len = 0;
    w_init(&w, &w_len);
    char **s;
    int s_len = 0;
    s_init(&s, &s_len);
    char ***p;
    int p_len = 0;
    p_init(&p, &p_len);
    char ****d;
    int d_len = 0;
    d_init(&d, &d_len);

    for (int i = 0; text[i] != 0; ++i) {
        if (text[i] == ' ') {
            if (w_len > 0)
                s[s_len++] = w;
            w_init(&w, &w_len);
        } else if (text[i] == '.') {
            if (w_len > 0)
                s[s_len++] = w;
            w_init(&w, &w_len);
            if (s_len > 0)
                p[p_len++] = s;
            s_init(&s, &s_len);
        } else if (text[i] == '\n') {
            if (w_len > 0)
                s[s_len++] = w;
            w_init(&w, &w_len);
            if (s_len > 0)
                p[p_len++] = s;
            s_init(&s, &s_len);
            if (p_len > 0)
                d[d_len++] = p;
            p_init(&p, &p_len);
        } else {
            w[w_len++] = text[i];
        }
    }
    if (w_len > 0)
        s[s_len++] = w;
    if (s_len > 0)
        p[p_len++] = s;
    if (p_len > 0)
        d[d_len++] = p;
    return d;
}

char *get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char *word) { printf("%s", word); }

void print_sentence(char **sentence) {
    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++) {
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char ***paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() {
    char *text        = get_input_text();
    char ****document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else {
            int k;
            scanf("%d", &k);
            char ***paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}