/* Resources
 * http://www.shafaetsplanet.com/?p=1961
 * https://codeforces.com/blog/entry/57292
 */

#include <bits/stdc++.h>

using namespace std;

void update(long long tree[],int n,int index,long long val){
    index++;
    // 0 based in user side,1 based in implementation

    while(index <= n){
        tree[index] += val;
        index       += (index & (-index));
        // adds the right most set bit
    }
}

// Prefix Sum query
long long query(long long tree[],int index){
    index++;
    // 0 based in user side,1 based in implementation

    long long sum = 0;
    while(index > 0){
        sum     += tree[index];
        index   -= (index & (-index));
        // Takes away the right most set bit
    }
    return sum;
}

// Range Query
long long query(long long tree[],int i,int j){
    return query(tree,j) - query(tree,i - 1);
}

int main() {
    int n = 8;
    long long a[8] = {9,-1,4,6, 8,-1,0,6};

    // Binary Index tree (BIT)
    long long tree[n + 1];
    // Every Value is 0 initially
    memset(tree,0,(n + 1)*sizeof(tree[0]));

    // Formation of BIT
    for(int i = 0;i < n;i++)
        update(tree, n, i, a[i]);

    cout << "array: ";
    for(int i = 0;i < n;i++)
        cout << a[i] << ", ";
    cout << endl;

    // Prefix Sum query
    for(int i = 0;i < n;i++)
        cout << "Prefix sum upto " << i
             <<  " : " << query(tree,i) << endl;

    // Range Sum query
    for(int i = 0;i < n;i++)
        for(int j = i;j < n;j++)
            cout << "Range Sum (" << i <<  " : " << j << ") "
                 << query(tree,i,j) << endl;

    // Update
    update(tree,n,2,3);// adds 3 to index 2

    return 0;
}
