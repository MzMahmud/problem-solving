#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char *data;
};

struct sentence {
    struct word *data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence *data;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph *data;
    int paragraph_count;//denotes number of paragraphs in a document
};
typedef struct word Word;
typedef struct sentence Sentence;
typedef struct paragraph Paragraph;
typedef struct document Document;

void word_constructor(Word *w, int *w_len) {
    w->data = (char *) (malloc(MAX_CHARACTERS * sizeof(char)));
    memset(w->data, 0, MAX_CHARACTERS * sizeof(char));
    *w_len = 0;
}

void sentence_constructor(Sentence *s) {
    s->data = (Word *) malloc(MAX_CHARACTERS * sizeof(Word));
    s->word_count = 0;
}

void paragraph_constructor(Paragraph *p) {
    p->data = (Sentence *) malloc(MAX_CHARACTERS * sizeof(Sentence));
    p->sentence_count = 0;
}

void document_constructor(Document *d) {
    d->data = (Paragraph *) malloc(MAX_PARAGRAPHS * sizeof(Paragraph));
    d->paragraph_count = 0;
}

struct document get_document(char *text) {
    Word w;
    int w_len;
    word_constructor(&w, &w_len);
    Sentence s;
    sentence_constructor(&s);
    Paragraph p;
    paragraph_constructor(&p);
    Document doc;
    document_constructor(&doc);

    for (int i = 0;; ++i) {
        int skip_this_char = 0;
        if (text[i] == 0 || text[i] == ' ' || text[i] == '.' || text[i] == '\n') {
            if (w_len > 0) {
                s.data[s.word_count++] = w;
                word_constructor(&w, &w_len);
            }
            skip_this_char = 1;
        }
        if (text[i] == 0 || text[i] == '.' || text[i] == '\n') {
            if (s.word_count > 0) {
                p.data[p.sentence_count++] = s;
                sentence_constructor(&s);
            }
            skip_this_char = 1;
        }
        if (text[i] == 0 || text[i] == '\n') {
            if (p.sentence_count > 0) {
                doc.data[doc.paragraph_count++] = p;
                paragraph_constructor(&p);
            }
            skip_this_char = 1;
        }
        if (text[i] == 0) break;
        if (!skip_this_char) w.data[w_len++] = text[i];
    }
    return doc;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return kth_paragraph(Doc, m).data[k - 1];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m,
                                                      int n) {
    return kth_sentence_in_mth_paragraph(Doc, m, n).data[k - 1];
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for (int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for (int i = 0; i < para.sentence_count; i++) {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for (int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

int main() {
    char *text = "Learning C is fun.\nMoaz pointers is more fun.It is good to have pointers.";
    Document d = get_document(text);
    print_document(d);
}