#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }

    swap(&a[i+1],&a[high]);
    return i+1;
}

void quickSort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);

        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
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

    quickSort(a,0,n-1);

    clock_t end=clock();

    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Time taken: %lf seconds\n",time_taken);

    free(a);

    return 0;
}