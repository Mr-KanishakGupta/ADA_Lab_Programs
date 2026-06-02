#include <stdio.h>
#define INF 99999
#define N 4

void floyd(int dist[N][N]) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

void print_matrix(int dist[N][N]) {
    printf("     ");
    for (int i = 0; i < N; i++) printf("%6d", i);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%4d ", i);
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF) printf("   INF");
            else printf("%6d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int dist[N][N] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };
    printf("Initial matrix:\n");
    print_matrix(dist);
    floyd(dist);
    printf("\nShortest paths:\n");
    print_matrix(dist);
    return 0;
}