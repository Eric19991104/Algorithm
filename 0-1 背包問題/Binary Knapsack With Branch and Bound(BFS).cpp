#include<bits/stdc++.h>
using namespace std;
typedef struct
{
	int profit;
	int weight;
	double cp;
}item;
typedef struct
{
	int level;
	int profit;
	int weight;
}node;
int knapsack(int,int,item []);
bool compare_item(item,item);
double bound(node,int,int,item []);
int main()
{
	int n,W;
	cin >> n >> W;
	item arr[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].profit;
	}
	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].weight;
		arr[i].cp = (double)arr[i].profit / (double)arr[i].weight;
	}
	cout << knapsack(n,W,arr);
	return 0;
}
int knapsack(int n,int W,item arr[])
{
	sort(arr,arr + n,compare_item);
	queue<node> Q;
	node u,v;
	while(!Q.empty())
	{
		Q.pop();
	}
	v.level = -1;
	v.profit = 0;
	v.weight = 0;
	int maxprofit = 0;
	Q.push(v);
	while(!Q.empty())
	{
		v = Q.front();
		Q.pop();
		u.level = v.level + 1;
		u.profit = v.profit + arr[u.level].profit;
		u.weight = v.weight + arr[u.level].weight;
		if(u.weight <= W && u.profit > maxprofit)
		{
			maxprofit = u.profit;
		}
		if(bound(u,n,W,arr) > maxprofit)
		{
			Q.push(u);
		}
		u.weight = v.weight;
		u.profit = v.profit;
		if(bound(u,n,W,arr) > maxprofit)
		{
			Q.push(u);
		}
	}
	return maxprofit;
}
bool compare_item(item a,item b)
{
	return a.cp > b.cp;
}
double bound(node u,int n,int W,item arr[])
{
	int j,k,totweight;
	double result;
	if(u.weight >= W)
	{
		return 0;
	}
	else
	{
		result = (double)u.profit;
		j = u.level + 1;
		totweight = u.weight;
		while(j < n && totweight + arr[j].weight <= W)
		{
			totweight += arr[j].weight;
			result += (double)arr[j].profit;
			j++;
		}
		k = j;
		if(k < n)
		{
			result += (double)(W - totweight) * arr[k].cp;
		}
	}
	return result;
}