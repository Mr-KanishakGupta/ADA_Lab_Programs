#include <stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

void knapsack(int profit[],int weight[],int n,int capacity){
    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(weight[i]<=j)
                dp[i][j]=max(profit[i]+dp[i-1][j-weight[i]],
                             dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    printf("Maximum profit = %d\n",dp[n][capacity]);
}

int main(){
    int n;

    printf("Enter number of items: ");
    scanf("%d",&n);

    int profit[n+1],weight[n+1];

    printf("Enter profits:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&profit[i]);

    printf("Enter weights:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&weight[i]);

    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);

    knapsack(profit,weight,n,capacity);

    return 0;
}