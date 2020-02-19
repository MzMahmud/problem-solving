/*
    LOJ 1164 - Horrible Queries
    Author: Moaz Mahmud
    Date  : 18 Feb,2020

    My Solution:
        Segment Tree with Lazy Propagation
    END :D :D
*/

#include <cstdio>
#include <vector>

using namespace std;

struct Node {
    long long sum, prop;
    Node(long long s = 0, long long p = 0) : sum(s), prop(p) {}
};

// SegmentTree with Lazy Propagation
class SegmentTree {
  private:
    vector<Node> tree;
    int n;

    void make_tree(const vector<long long> &a, long long root,
                   long long begin_index, long long end_index);

    long long query(long long i, long long j, long long root,
                    long long begin_index, long long end_index,
                    long long carry);

    void update(long long val, long long i, long long j, long long root,
                long long begin_index, long long end_index);

  public:
    SegmentTree(const vector<long long> &a) {
        n             = a.size();
        int tree_size = 3 * n; // 2 * (n + 1);

        for (int i = 0; i < tree_size; i++)
            tree.emplace_back(0, 0);
        make_tree(a, 1, 1, n);
    }

    long long query(long long begin_index, long long end_index);
    void update(long long val, long long index);
    void update(long long val, long long i, long long j);
};

void SegmentTree::make_tree(const vector<long long> &a, long long root,
                            long long begin_index, long long end_index) {
    if (begin_index == end_index) {
        tree[root].sum  = a[begin_index - 1]; // 0 based in user side
        tree[root].prop = 0;
        return;
    }

    long long left  = root << 1;
    long long right = left + 1;

    long long mid = (begin_index + end_index) >> 1;
    make_tree(a, left, begin_index, mid);
    make_tree(a, right, mid + 1, end_index);

    tree[root].sum = tree[left].sum + tree[right].sum;
}

long long SegmentTree::query(long long i, long long j, long long root,
                             long long begin_index, long long end_index,
                             long long carry = 0) {

    // range fully outside
    // begin_index---end_index  i----j
    // i----j begin_index---end_index
    if ((end_index < i) || (j < begin_index))
        return 0;

    // range fully inside
    // i---begin_index---end_index---j
    if ((i <= begin_index) && (end_index <= j))
        return tree[root].sum + (end_index - begin_index + 1) * carry;

    // else long longersecting range
    long long left  = root << 1;
    long long right = left + 1;

    long long mid = (begin_index + end_index) >> 1;

    long long l_val =
        query(i, j, left, begin_index, mid, carry + tree[root].prop);
    long long r_val =
        query(i, j, right, mid + 1, end_index, carry + tree[root].prop);

    return l_val + r_val;
}

void SegmentTree::update(long long val, long long i, long long j,
                         long long root, long long begin_index,
                         long long end_index) {

    // fully outside
    // begin---end i---j
    // i---j begin---end
    if (j < begin_index || end_index < i)
        return;

    // fully inside
    // i---begin---end---j
    if (i <= begin_index && end_index <= j) {
        tree[root].sum += (val * (end_index - begin_index + 1));
        tree[root].prop += val;
        return;
    }

    long long left  = root << 1;
    long long right = left + 1;
    long long mid   = (begin_index + end_index) >> 1;

    update(val, i, j, left, begin_index, mid);
    update(val, i, j, right, mid + 1, end_index);

    tree[root].sum = tree[left].sum + tree[right].sum +
                     tree[root].prop * (end_index - begin_index + 1);
}

// index is expected to be 0 based from user
long long SegmentTree::query(long long begin_index, long long end_index) {
    return query(begin_index + 1, end_index + 1, 1, 1, n);
}

// index is expected to be 0 based from user
void SegmentTree::update(long long value, long long index) {
    update(value, index + 1, index + 1, 1, 1, n);
}

// index is expected to be 0 based from user
void SegmentTree::update(long long value, long long i, long long j) {
    update(value, i + 1, j + 1, 1, 1, n);
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    int T, cn = 1;

    scanf("%d", &T);
    while (T--) {
        int n, q, c;
        long long v, x, y;

        scanf("%d%d", &n, &q);

        vector<long long> a(n, (long long)0);
        SegmentTree st(a);

        printf("Case %d:\n", cn++);

        while (q--) {
            scanf("%d", &c);
            if (c == 0) {
                scanf("%lld%lld%lld", &x, &y, &v);
                st.update(v, x, y);
            } else {
                scanf("%lld%lld", &x, &y);
                printf("%lld\n", st.query(x, y));
            }
        }
    }
    return 0;
}