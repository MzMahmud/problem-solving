#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

typedef vector<vector<int>> Matrix2D;

void print_matrix(const Matrix2D &mat) {
    int row = mat.size();
    int col = mat[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", mat[i][j]);

            printf("%4s", "");
        }
        printf("\n");
    }
    printf("\n\n");
}

struct DistPath {
    Matrix2D dist, path;
    DistPath(Matrix2D d, Matrix2D p) : dist(d), path(p) {}
};

/*
 * Floyd Warshall Algorithm
 * Input: Graph in Adjancy Matrix form
 * Out  : 2D matrix->all pair shortest path
 * NOTE : Works for both POSITIVE and NEGATIVE edge wighted graph
 * Complexity: O(|V|^3)
 */
Matrix2D floyd_warshall(const Matrix2D &adj_matrix) {
    // A |V|x|V| array with initilized by adj Matrix
    Matrix2D dist = adj_matrix;

    int n = dist.size();
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

/*
 * Floyd Warshall Algorithm With Path Construction
 * Input: Graph in Adjancy Matrix form
 * Out  : 2D matrix->all pair shortest path and All pair Path Matrix
 * NOTE : Works for both POSITIVE and NEGATIVE edge wighted graph
 * Complexity: O(|V|^3)
 */
DistPath floyd_warshall_with_path(const Matrix2D &adj_matrix) {
    // A |V|x|V| array with initilized by adj Matrix
    Matrix2D dist = adj_matrix;
    Matrix2D path = adj_matrix;

    int n = dist.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
                path[i][j] = i;
                continue;
            }

            if (adj_matrix[i][j] == INF)
                path[i][j] = -1;
            else
                path[i][j] = j;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                int new_cost = dist[i][k] + dist[k][j];
                if (new_cost < dist[i][j]) {
                    dist[i][j] = new_cost;
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    return DistPath(dist, path);
}

vector<int> get_path(int u, int v, const Matrix2D &paths) {
    if (paths[u][v] < 0) // no path
        return {};

    vector<int> path;
    path.push_back(u);
    while (u != v) {
        u = paths[u][v];
        path.push_back(u);
    }
    return path;
}

int main() {
    // Floyd Warshall Implementation
    int n = 8;
    Matrix2D adj_matrix(n, vector<int>(n, INF));

    int u, v, c;
    while (cin >> u >> v >> c)
        adj_matrix[u][v] = c;

    print_matrix(adj_matrix);

    DistPath dist_path = floyd_warshall_with_path(adj_matrix);

    print_matrix(dist_path.dist);
    print_matrix(dist_path.path);

    vector<int> path = get_path(5, 4, dist_path.path);

    for_each(path.begin(), path.end(),
             [](int u) { cout << u << "->"; });
    cout << endl;

    return 0;
}

/*
An input Graph

0 1 1
0 2 2
0 4 3
1 0 1
1 3 3
1 5 4
1 6 9
2 0 2
2 5 6
3 1 3
4 0 3
4 6 4
4 7 9
5 1 4
5 2 6
5 7 5
6 1 9
6 4 4
7 4 9
7 5 5

*/
