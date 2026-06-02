#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int a[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left]>a[largest])
        largest=left;

    if(right<n && a[right]>a[largest])
        largest=right;

    if(largest!=i){
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(int i=n-1;i>0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int *a=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
        a[i]=rand();

    clock_t start=clock();

    heapSort(a,n);

    clock_t end=clock();

    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Time taken: %lf seconds\n",time_taken);

    free(a);

    return 0;
}