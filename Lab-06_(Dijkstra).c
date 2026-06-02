#include <stdio.h>

#define MAX 100
#define INF 999999

int main(){
    int n,graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);

            if(i!=j && graph[i][j]==0)
                graph[i][j]=INF;
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d",&source);

    int dist[MAX],visited[MAX];

    for(int i=0;i<n;i++){
        dist[i]=graph[source][i];
        visited[i]=0;
    }

    dist[source]=0;
    visited[source]=1;

    for(int i=1;i<n;i++){
        int min=INF,u=-1;

        for(int j=0;j<n;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }

        if(u==-1)
            break;

        visited[u]=1;

        for(int v=0;v<n;v++){
            if(!visited[v] && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }

    printf("\nShortest distances from vertex %d:\n",source);

    for(int i=0;i<n;i++)
        printf("%d -> %d = %d\n",source,i,dist[i]);

    return 0;
}