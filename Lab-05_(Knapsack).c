#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int profit;
    int weight;
    float ratio;
}Item;

void swap(Item *a,Item *b){
    Item t=*a;
    *a=*b;
    *b=t;
}

void sort(Item a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].ratio<a[j+1].ratio)
                swap(&a[j],&a[j+1]);
        }
    }
}

int main(){
    int n;
    
    printf("Enter number of items: ");
    scanf("%d",&n);

    Item a[n];

    printf("Enter profit and weight of each item:\n");
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].profit,&a[i].weight);
        a[i].ratio=(float)a[i].profit/a[i].weight;
    }

    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);

    sort(a,n);

    float maxProfit=0.0;

    for(int i=0;i<n;i++){
        if(capacity>=a[i].weight){
            maxProfit+=a[i].profit;
            capacity-=a[i].weight;
        }
        else{
            maxProfit+=a[i].ratio*capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n",maxProfit);

    return 0;
}