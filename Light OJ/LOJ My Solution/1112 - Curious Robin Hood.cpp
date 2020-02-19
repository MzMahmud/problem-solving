/*
    LOJ 1112 - Curious Robin Hood
    Author: Moaz Mahmud
    Date  : 19 Feb,2020

    My Solution:
        Range Sum with Binary Index Tree
    END :D :D
*/
#include <cstdio>

using namespace std;

void update(long long tree[],int n,int i,long long val){
    i++;// 0 based in user side,1 based in implementation
    while(i <= n){
        tree[i] += val;
        i       += (i & (-i));
    }
}

long long query(long long tree[],int i){
    i++; // 0 based in user side,1 based in implementation
    long long sum = 0;
    while(i > 0){
        sum += tree[i];
        i   -= (i & (-i));
    }
    return sum;
}

// Range Query
long long query(long long tree[],int i,int j){
    return query(tree,j) - query(tree,i - 1);
}

int main(){
    freopen("in.txt" , "r", stdin);
    freopen("out.txt", "w", stdout);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n,q;
        scanf("%d%d", &n,&q);

        long long tree[n + 1] = {};

        for(int i = 0;i < n;i++){
            long long val;
            scanf("%lld", &val);
            update(tree,n,i,val);
        }

        printf("Case %d:\n",cn++);
        while(q--){
            int com;
            scanf("%d", &com);
            if(com == 1){
                int i;
                scanf("%d", &i);
                long long val = query(tree,i,i);
                printf("%lld\n",val);
                update(tree,n,i,-val);
            }else if(com == 2){
                int i;long long val;
                scanf("%d%lld", &i,&val);
                update(tree,n,i,val);
            }else{
                int i,j;
                scanf("%d%d", &i,&j);
                printf("%lld\n",query(tree,i,j));
            }
        }
    }
    return 0;
}


/*

/*
    LOJ 1112 - Curious Robin Hood
    Author: Moaz Mahmud
    Date  : 17 Feb,2020

    My Solution:
        Range Sum with Segment Tree
    END :D :D
*/

#include <cstdio>
#include <vector>

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

    tree[root] = tree[left] + tree[right];
}

int SegmentTree::query(int i, int j, int root, int begin_index, int end_index) {

    // range fully outside
    // begin_index---end_index  i----j
    // i----j begin_index---end_index
    if ((end_index < i) || (j < begin_index))
        return 0;

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

    return l_val + r_val;
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
            int command;
            scanf("%d", &command);
            if (command == 1) {
                int i;
                scanf("%d", &i);
                printf("%d\n", a[i]);
                if (a[i] > 0) {
                    a[i] = 0;
                    segmentTree.update(a[i], i);
                }
            } else {
                int i, j;
                scanf("%d%d", &i, &j);
                if (command == 2) {
                    a[i] = a[i] + j;
                    segmentTree.update(a[i], i);
                } else
                    printf("%d\n", segmentTree.query(i, j));
            }
        }
    }
    return 0;
}

*/