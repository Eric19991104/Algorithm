#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;}
void quicksort(int [],int,int);
void partiton(int [],int,int,int *);
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
    int i = low,j = high;
    if(high > low)
    {
        int pivotpoint;
        partiton(S,low,high,&pivotpoint);      //透過呼叫partiton找尋pivotpoint
        quicksort(S,low,pivotpoint - 1);
        quicksort(S,pivotpoint + 1,high);
    }
}
void partiton(int S[],int low,int high,int *pivotpoint)
{
    int pivotitem = S[low],i = low,j = high + 1;
    do
    {
        i++;
    }while(i < high && S[i] <= pivotitem);
    do
    {
        j--;
    }while(S[j] > pivotitem);
    while(i < j)
    {
        SWAP(S[i],S[j]);
        do
        {
            i++;
        }while(S[i] <= pivotitem);
        do
        {
            j--;
        }while(S[j] > pivotitem);
    }
    *pivotpoint = j;
    SWAP(S[low],S[*pivotpoint]);        //將pivotitem放在pivotpoint的位置
}