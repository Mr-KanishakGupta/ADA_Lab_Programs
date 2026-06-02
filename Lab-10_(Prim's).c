#include <stdio.h>

#define MAX 100
#define INF 999999

int minKey(int key[],int mst[],int n){
    int min=INF,index=-1;

    for(int i=0;i<n;i++){
        if(!mst[i] && key[i]<min){
            min=key[i];
            index=i;
        }
    }

    return index;
}

void prim(int graph[MAX][MAX],int n){
    int parent[MAX];
    int key[MAX];
    int mst[MAX];

    for(int i=0;i<n;i++){
        key[i]=INF;
        mst[i]=0;
    }

    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<n-1;i++){
        int u=minKey(key,mst,n);

        mst[u]=1;

        for(int v=0;v<n;v++){
            if(graph[u][v] && !mst[v] && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    int cost=0;

    printf("\nEdges in MST:\n");

    for(int i=1;i<n;i++){
        printf("%d - %d : %d\n",parent[i],i,graph[i][parent[i]]);
        cost+=graph[i][parent[i]];
    }

    printf("Minimum Cost = %d\n",cost);
}

int main(){
    int n;
    
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[MAX][MAX];

    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

    prim(graph,n);

    return 0;
}