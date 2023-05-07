#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int profit;
    int weight;
    double profit_density;
}item;
int Knapsack(int,int,int [],int []);
int compare_item(const void *,const void *);
void recursive(item [],int,int,int *,int *,int *,int);
double profit_bound(item [],int,int,int,int,int);
main()
{
    int n,W;
    scanf("%d\n%d",&n,&W);
    int p[n],w[n];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&w[i]);
    }
    printf("%d",Knapsack(W,n,p,w));
}
int Knapsack(int W,int n,int p[],int w[])
{
    int current_weight = 0,current_profits = 0,max_profits = 0;
    item *data = malloc(n * sizeof(item));
    for(int i = 0 ; i < n ; i++)
    {
        data[i].profit = p[i];
        data[i].weight = w[i];
        data[i].profit_density = (double)p[i] / (double)w[i];
    }
    qsort(data,n,sizeof(item),compare_item);
    recursive(data,W,n,&current_profits,&current_weight,&max_profits,0);
    free(data);
    return max_profits;
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
void recursive(item data[],int W,int n,int *current_profits,int *current_weight,int *max_profits,int level)
{
    if(n == level)
    {
        *max_profits = *current_profits;
        return;
    }
    if(*current_weight + data[level].weight <= W)
    {
        *current_profits += data[level].profit;
        *current_weight += data[level].weight;
        recursive(data,W,n,current_profits,current_weight,max_profits,level + 1);
        *current_profits -= data[level].profit;
        *current_weight -= data[level].weight;
    }
    if(profit_bound(data,W,n,*current_profits,*current_weight,level + 1) > (double)(*max_profits))
    {
        recursive(data,W,n,current_profits,current_weight,max_profits,level + 1);
    }
}
double profit_bound(item data[],int W,int n,int current_profits,int current_weight,int level)
{
    int remaining_capacity = W - current_weight,lvl = level;
    double bound = (double)current_profits;
    while(lvl < n && data[lvl].weight <= remaining_capacity)
    {
        remaining_capacity -= data[lvl].weight;
        bound += (double)data[lvl].profit;
        lvl++;
    }
    if(lvl < n)
    {
        bound += (double)(data[lvl].profit_density * remaining_capacity);
    }
    return bound;
}