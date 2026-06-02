#include <stdio.h>

#define MAX 100

typedef struct{
    int u,v,w;
}Edge;

int parent[MAX];

int find(int v){
    while(parent[v]!=v)
        v=parent[v];
    return v;
}

void unionSet(int u,int v){
    parent[find(u)]=find(v);
}

void sortEdges(Edge e[],int m){
    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(e[j].w>e[j+1].w){
                Edge t=e[j];
                e[j]=e[j+1];
                e[j+1]=t;
            }
        }
    }
}

int main(){
    int n,m;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d",&n,&m);

    Edge e[m];

    printf("Enter source destination weight:\n");
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

    for(int i=0;i<n;i++)
        parent[i]=i;

    sortEdges(e,m);

    int cost=0,edges=0;

    printf("\nEdges in MST:\n");

    for(int i=0;i<m && edges<n-1;i++){
        int u=find(e[i].u);
        int v=find(e[i].v);

        if(u!=v){
            printf("%d - %d : %d\n",e[i].u,e[i].v,e[i].w);

            cost+=e[i].w;
            edges++;

            unionSet(u,v);
        }
    }

    printf("Minimum Cost = %d\n",cost);

    return 0;
}