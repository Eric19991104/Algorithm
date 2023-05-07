#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;} 
void selectionsort(int [],int);
main()
{
    int N;
    scanf("%d",&N);
    int S[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&S[i]);
    }
    selectionsort(S,N);
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",S[i]);
    }
}
void selectionsort(int S[],int high)
{
    for(int i = 0 ; i < high - 1 ; i++)
    {
        int min = i;
        for(int j = i + 1 ; j < high ; j++)
        {
            if(S[j] < S[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            SWAP(S[min],S[i]);
        }
    }
}
