#include<bits/stdc++.h>
using namespace std;
struct item
{
	int profit;
	int weight;
	double cp;
};
struct node
{
	int level;
	int profit;
	int weight;
	double bound;
	bool operator > (const node &s)const
	{
		return bound < s.bound;
	}
};
int knapsack(int,int,item []);
bool compare_item(item,item);
double profit_bound(node,int,int,item []);
int main()
{
	int n,W;
	cin >> n;
	cin >> W;
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
	priority_queue<node,vector<node>,greater<node> > PQ;
	node u,v;
	v.level = -1;
	v.profit = 0;
	v.weight = 0;
	v.bound = profit_bound(v,n,W,arr);
	int maxprofit = 0;
	PQ.push(v);
	while(!PQ.empty())
	{
		v = PQ.top();
		PQ.pop();
		if(v.bound > (double)maxprofit)
		{
			u.level = v.level + 1;
			u.profit = v.profit + arr[u.level].profit;
			u.weight = v.weight + arr[u.level].weight;
			if(u.weight <= W && u.profit > maxprofit)
			{
				maxprofit = u.profit;
			}
			u.bound = profit_bound(u,n,W,arr);
			if(u.bound > (double)maxprofit)
			{
				PQ.push(u);
			}
			u.weight -= arr[u.level].weight;
			u.profit -= arr[u.level].profit;
			u.bound = profit_bound(u,n,W,arr);
			if(u.bound > (double)maxprofit)
			{
				PQ.push(u);
			}
		}
	}
	return maxprofit;
}
bool compare_item(item a,item b)
{
	return a.cp > b.cp;
}
double profit_bound(node u,int n,int W,item arr[])
{
	int remaining_capacity = W - u.weight,lvl = u.level;
	double result = (double)u.profit;
	while(lvl < n && arr[lvl].weight <= remaining_capacity)
	{
		remaining_capacity -= arr[lvl].weight;
		result += (double)arr[lvl].profit;
		lvl++;
	}
	if(lvl < n)
	{
		result += (double)(arr[lvl].cp * remaining_capacity);
	}
	return result;
}