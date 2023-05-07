#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;} 
void quicksort(int [],int,int);
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
    int pivotpoint = S[low],i = low,j = high;
    if(high > low)
    {
        while(i != j)
        {
            while(S[j] >= pivotpoint && i < j)
            {
                j--;
            }
            while(S[i] <= pivotpoint && i < j)
            {
                i++;
            }
            if(i < j)
            {
                SWAP(S[i],S[j]);
            }
        }
        S[low] = S[i];                          //最後一個和pivotpoint交換
        S[i] = pivotpoint;
        quicksort(S,low,i - 1);
        quicksort(S,i + 1,high);
    }
}