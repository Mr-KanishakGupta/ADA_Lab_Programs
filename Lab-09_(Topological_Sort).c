#include <stdio.h>

#define MAX 100

int stack[MAX];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

void dfs(int v,int n,int graph[MAX][MAX],int visited[]){
    visited[v]=1;

    for(int i=0;i<n;i++){
        if(graph[v][i] && !visited[i])
            dfs(i,n,graph,visited);
    }

    push(v);
}

void topologicalSort(int n,int graph[MAX][MAX]){
    int visited[MAX]={0};

    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,n,graph,visited);
    }

    printf("Topological Ordering:\n");

    while(top!=-1)
        printf("%d ",pop());

    printf("\n");
}

int main(){
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

    topologicalSort(n,graph);

    return 0;
}