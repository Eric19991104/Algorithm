#include<stdio.h>
#define SWAP(x,y){int t;t = x;x = y;y = t;} 
void cocktailsort(int [],int);
main()
{
    int N;
    scanf("%d",&N);
    int S[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&S[i]);
    }
    cocktailsort(S,N - 1);
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",S[i]);
    }
}
void cocktailsort(int S[],int high)
{
    int left = 0,right = high;
    while(left < right)
    {
        for(int i = 0 ; i < right ; i++)
        {
            if(S[i] > S[i + 1])
            {
                SWAP(S[i],S[i + 1]);
            }
        }
        right--;
        for(int i = right ; i > left ; i--)
        {
            if(S[i - 1] > S[i])
            {
                SWAP(S[i - 1],S[i]);
            }
        }
        left++;
    }
}