#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int profit;
    int weight;
    double profit_density;
}item;
int max(int,int);
int compare_item(const void *,const void *);
int Knapsack(int,int,item []);
main()
{
    int n,W;
    scanf("%d\n%d",&n,&W);
    item array[n];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&array[i].profit);
    }
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&array[i].weight);
        array[i].profit_density = (double)array[i].profit / (double)array[i].weight;
    }
    qsort(array,n,sizeof(item),compare_item);
    printf("%d",Knapsack(W,n,array));
}
int max(int a,int b)
{
    return (a > b) ? a : b; 
}
int compare_item(const void *avg1,const void *avg2)
{
    item item1 = *(item*)(avg1),item2 = *(item*)(avg2);
    if(item1.profit_density > item2.profit_density)
    {
        return -1;
    }
    else if(item2.profit_density > item1.profit_density)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Knapsack(int W,int n,item array[])
{
    int DP[W + 1],sum = 0;
    memset(DP,0,sizeof(DP));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = W ; j >= array[i].weight ; j--)
        {
            DP[j] = max(DP[j],DP[j - array[i].weight] + array[i].profit);
        }
    }
    return DP[W];
}