#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;} 
void gnomesort(int [],int,int);
main()
{
    int N;
    scanf("%d",&N);
    int S[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&S[i]);
    }
    gnomesort(S,0,N);
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",S[i]);
    }
}
void gnomesort(int S[],int low,int high)
{
    int pos = low;
    while(pos < high)
    {
        if(pos == 0 || S[pos] >= S[pos - 1])
        {
            pos++;
        }
        else
        {
            SWAP(S[pos],S[pos - 1]);
            pos--;
        }
    }
}
