#include<stdio.h>
void insertionsort(int [],int);
main()
{
    int N;
    scanf("%d",&N);
    int S[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&S[i]);
    }
    insertionsort(S,N);
    for(int i = 0 ; i < N ; i++)
    {
        printf("%d ",S[i]);
    }
}
void insertionsort(int S[],int high)
{
    int key,j;
    for(int i = 1 ; i < high ; i++)
    {
        key = S[i];
        j = i - 1;
        while(j >= 0 && S[j] > key)
        {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = key;
    }
}