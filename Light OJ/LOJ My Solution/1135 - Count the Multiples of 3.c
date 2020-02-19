/*
    LOJ 1135 - Count the Multiples of 3
    Author: Moaz Mahmud
    Date  : 18 Feb,2020

    My Solution:
        Segment Tree with Lazy Propagation
        The trick is to conver the logic of sum with propagation
        to adding a value.

        if propagation % 3 = 0:
            sum[i] comes from left.sum[i] , right.sum[i]
        if propagation % 3 = 1:
            sum[0] comes from left.sum[2] , right.sum[2]
            sum[1] comes from left.sum[0] , right.sum[0]
            sum[2] comes from left.sum[1] , right.sum[1]
        if propagation % 3 = 2:
            sum[0] comes from left.sum[1] , right.sum[1]
            sum[1] comes from left.sum[2] , right.sum[2]
            sum[2] comes from left.sum[0] , right.sum[0]

        Similarly query logic can be modified

    END :D :D
*/

#include <cstdio>
#include <vector>

using namespace std;

struct Node {
    long long sum[3], prop;
    Node(long long n0 = 0, long long n1 = 0, long long n2 = 0) {
        sum[0] = n0;
        sum[1] = n1;
        sum[2] = n2;
        prop   = 0;
    }
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
            tree.emplace_back(0, 0, 0);
        make_tree(a, 1, 1, n);
    }

    long long query(long long begin_index, long long end_index);
    void update(long long val, long long index);
    void update(long long val, long long i, long long j);
};

void SegmentTree::make_tree(const vector<long long> &a, long long root,
                            long long begin_index, long long end_index) {
    if (begin_index == end_index) {
        for (int i            = 0; i < 3; i++)
            tree[root].sum[i] = 0;
        tree[root].prop       = 0;

        int ind = a[begin_index - 1] % 3;
        tree[root].sum[ind]++;
        return;
    }

    long long left  = root << 1;
    long long right = left + 1;

    long long mid = (begin_index + end_index) >> 1;
    make_tree(a, left, begin_index, mid);
    make_tree(a, right, mid + 1, end_index);

    // tree[root].sum = tree[left].sum + tree[right].sum;
    for (int i = 0; i < 3; i++) {
        tree[root].sum[i] = tree[left].sum[i] + tree[right].sum[i];
    }
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
    if ((i <= begin_index) && (end_index <= j)) {
        // return tree[root].sum + (end_index - begin_index + 1) * carry;

        long long mod = carry % 3;
        long long ret;
        if (mod == 0)
            ret = tree[root].sum[0];
        else if (mod == 1)
            ret = tree[root].sum[2];
        else if (mod == 2)
            ret = tree[root].sum[1];

        return ret;
    }

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
        // tree[root].sum += (val * (end_index - begin_index + 1));

        // effect of adding one
        // as value = 1 always dont bother for other cases
        long long sum[3];
        sum[0] = tree[root].sum[2];
        sum[1] = tree[root].sum[0];
        sum[2] = tree[root].sum[1];

        for (int i = 0; i < 3; i++) {
            tree[root].sum[i] = sum[i];
        }

        // tree[root].prop += val;
        tree[root].prop = (tree[root].prop + val) % 3;
        return;
    }

    long long left  = root << 1;
    long long right = left + 1;
    long long mid   = (begin_index + end_index) >> 1;

    update(val, i, j, left, begin_index, mid);
    update(val, i, j, right, mid + 1, end_index);

    // tree[root].sum = tree[left].sum + tree[right].sum +
    //                 tree[root].prop * (end_index - begin_index + 1);

    // marge results from left and right
    int mod = tree[root].prop % 3;

    if (mod == 0) {
        tree[root].sum[0] = tree[left].sum[0] + tree[right].sum[0];
        tree[root].sum[1] = tree[left].sum[1] + tree[right].sum[1];
        tree[root].sum[2] = tree[left].sum[2] + tree[right].sum[2];
    } else if (mod == 1) {
        tree[root].sum[0] = tree[left].sum[2] + tree[right].sum[2];
        tree[root].sum[1] = tree[left].sum[0] + tree[right].sum[0];
        tree[root].sum[2] = tree[left].sum[1] + tree[right].sum[1];
    } else if (mod == 2) {
        tree[root].sum[0] = tree[left].sum[1] + tree[right].sum[1];
        tree[root].sum[1] = tree[left].sum[2] + tree[right].sum[2];
        tree[root].sum[2] = tree[left].sum[0] + tree[right].sum[0];
    }
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
            scanf("%d%lld%lld", &c, &x, &y);
            if (c == 0) {
                st.update(1, x, y);
            } else {
                printf("%lld\n", st.query(x, y));
            }
        }
    }
    return 0;
}
