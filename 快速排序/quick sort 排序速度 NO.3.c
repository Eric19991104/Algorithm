#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;} 
void quicksort(int [],int,int);
void partition(int [],int,int,int*);
main()
{
    int N;
    scanf("%d",&N);
    int S[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&S[i]);
    }
    quicksort(S,0,N - 1);
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",S[i]);
    }
}
void quicksort(int S[],int low,int high)
{
    int pivotpoint;
    if(high > low)
    {
        partition(S,low,high,&pivotpoint);
        quicksort(S,low,pivotpoint - 1);
        quicksort(S,pivotpoint + 1,high);
    }
}
void partition(int S[],int low,int high,int *pivotpoint)
{
    int j = low,pivotitem = S[low];
    for(int i = low + 1 ; i <= high ; i++)
    {
        if(S[i] < pivotitem)
        {
            j++;
            SWAP(S[i],S[j]);
        }
    }
    *pivotpoint = j;
    SWAP(S[low],S[*pivotpoint]);
}