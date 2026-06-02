#include <stdio.h>

int getMobile(int a[],int dir[],int n){
    int mobile=0,mobilePos=-1;

    for(int i=0;i<n;i++){
        if(dir[i]==-1 && i>0 && a[i]>a[i-1] && a[i]>mobile){
            mobile=a[i];
            mobilePos=i;
        }

        if(dir[i]==1 && i<n-1 && a[i]>a[i+1] && a[i]>mobile){
            mobile=a[i];
            mobilePos=i;
        }
    }

    return mobilePos;
}

void printPermutation(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void johnsonTrotter(int n){
    int a[n],dir[n];

    for(int i=0;i<n;i++){
        a[i]=i+1;
        dir[i]=-1;
    }

    printPermutation(a,n);

    while(1){
        int pos=getMobile(a,dir,n);

        if(pos==-1)
            break;

        int swapPos=pos+dir[pos];

        int temp=a[pos];
        a[pos]=a[swapPos];
        a[swapPos]=temp;

        temp=dir[pos];
        dir[pos]=dir[swapPos];
        dir[swapPos]=temp;

        int mobile=a[swapPos];

        for(int i=0;i<n;i++){
            if(a[i]>mobile)
                dir[i]=-dir[i];
        }

        printPermutation(a,n);
    }
}

int main(){
    int n;

    printf("Enter value of n: ");
    scanf("%d",&n);

    johnsonTrotter(n);

    return 0;
}