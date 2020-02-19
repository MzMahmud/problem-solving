/*
    LOJ 1082 - Array Queries
    Author: Moaz Mahmud
    Date  : 17 Feb,2020

    My Solution:
        Range Minimum Query with Segment Tree
    END :D :D
*/

#include <cstdio>
#include <vector>

#define INF 100005
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

class SegmentTree {
  private:
    vector<int> tree;
    int n;

    void make_tree(const vector<int> &a, int root, int begin_index,
                   int end_index);
    int query(int i, int j, int root, int begin_index, int end_index);
    void update(int val, int index, int root, int begin_index, int end_index);

  public:
    SegmentTree(const vector<int> &a) {
        n             = a.size();
        int tree_size = 3 * n; // 2 * (n + 1);

        tree = vector<int>(tree_size);
        make_tree(a, 1, 1, n);
    }

    int query(int begin_index, int end_index);
    void update(int val, int index);
};

void SegmentTree::make_tree(const vector<int> &a, int root, int begin_index,
                            int end_index) {
    if (begin_index == end_index) {
        tree[root] = a[begin_index - 1]; // 0 based in user side
        return;
    }

    int left  = 2 * root;
    int right = 2 * root + 1;

    int mid = (begin_index + end_index) >> 1;
    make_tree(a, left, begin_index, mid);
    make_tree(a, right, mid + 1, end_index);

    tree[root] = MIN(tree[left], tree[right]);
}

int SegmentTree::query(int i, int j, int root, int begin_index, int end_index) {

    // range fully outside
    // begin_index---end_index  i----j
    // i----j begin_index---end_index
    if ((end_index < i) || (j < begin_index))
        return INF;

    // range fully inside
    // i---begin_index---end_index---j
    if ((i <= begin_index) && (end_index <= j))
        return tree[root];

    // else intersecting range
    int left  = 2 * root;
    int right = 2 * root + 1;

    int mid = (begin_index + end_index) / 2;

    int l_val = query(i, j, left, begin_index, mid);
    int r_val = query(i, j, right, mid + 1, end_index);

    return MIN(l_val, r_val);
}

void SegmentTree::update(int val, int index, int root, int begin_index,
                         int end_index) {

    if (index > end_index || index < begin_index)
        return;

    if (begin_index >= index && end_index <= index) {
        tree[root] = val;
        return;
    }

    int left  = root * 2;
    int right = root * 2 + 1;
    int mid   = (begin_index + end_index) / 2;

    update(val, index, left, begin_index, mid);
    update(val, index, right, mid + 1, end_index);

    tree[root] = tree[left] + tree[right];
}

// index is expected to be 0 based from user
int SegmentTree::query(int begin_index, int end_index) {
    return query(begin_index + 1, end_index + 1, 1, 1, n);
}

// index is expected to be 0 based from user
void SegmentTree::update(int value, int index) {
    update(value, index + 1, 1, 1, n);
}

int main() {
    int T, cn = 1;

    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d", &n, &q);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("Case %d:\n", cn++);

        SegmentTree segmentTree(a);
        for (int i = 0; i < q; i++) {
            int start, end;
            scanf("%d%d", &start, &end);
            printf("%d\n", segmentTree.query(start - 1, end - 1));
        }
    }
    return 0;
}