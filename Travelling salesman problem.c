#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void travel();
int **map,**dp,n;
main()
{
    scanf("%d",&n);
    map = (int **)malloc(n * sizeof(int *));
    dp = (int **)malloc(n * sizeof(int *));
    for(int i = 0 ; i < n ; i++)
    {
        map[i] = (int *)malloc(n * sizeof(int));
        dp[i] = (int *)malloc((1 << (n - 1)) * sizeof(int));
    }
    for(int i = 0 ; i < n ; i++)
    {
        map[i][i] = 0;
    }
    int x,y,z;
    for(int i = 0 ; i < n * (n - 1) ; i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        map[x][y] = z;
    }
    travel();
    printf("%d\n",dp[0][(1 << (n - 1)) - 1]);
    free(map);
    free(dp);
}
void travel()
{
    for(int i = 0 ; i < n ; i++)
    {
        dp[i][0] = map[i][0];
    }
    for(int j = 1 ; j < 1 << (n - 1) ; j++)                             //除了空集合以外的集合
    {
        for(int i = 0 ; i < n ; i++)                                    //n個節點，每個節點拜訪集合
        {
            dp[i][j] = INT_MAX;
            if(j >> (i - 1) & 1)                                        //看哪個節點不在j集合，不在才繼續
            {
                continue;
            }
            for(int k = 1 ; k < n ; k++)
            {
                if((j >> (k - 1) & 1) == 0)                               //看集合中有哪些節點，不在就離開
                {
                    continue;
                }
                if(dp[i][j] > map[i][k] + dp[k][j ^ (1 << (k - 1))])
                {
                    dp[i][j] = map[i][k] + dp[k][j ^ (1 << (k - 1))];
                }
            }
        }
    }
}