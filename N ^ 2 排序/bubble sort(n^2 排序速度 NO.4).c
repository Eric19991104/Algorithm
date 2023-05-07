#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;} 
void bubblesort(int [],int,int);
main()
{
    int N;
    scanf("%d",&N);
    int S[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&S[i]);
    }
    bubblesort(S,0,N - 1);
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",S[i]);
    }
}
void bubblesort(int S[],int low,int high)
{
    for(int i = low ; i < high - 1 ; i++)
    {
        for(int j = low ; j < high - low - i ; j++)
        {
            if(S[j] > S[j + 1])
            {
                SWAP(S[j],S[j + 1]);
            }
        }
    }
}